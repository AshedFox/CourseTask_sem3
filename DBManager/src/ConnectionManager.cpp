#include "ConnectionManager.h"
#include <QString>
#include <QSqlDatabase>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QSqlError>
#include <QSqlQuery>

#include "DBTypes.h"

namespace  {
    class dbCloser {
    public:
        void operator() (QSqlDatabase *db){
            db->close();
            QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
            delete db;
        }
    };
}

struct db::ConnectionManager::ConnectionManagerPrivate {

    std::unique_ptr<QSqlDatabase, dbCloser> database;
    QString dbPath;
    bool isValid {true};
    DBState state {DBState::OK};

    bool setup();
    bool setupWorkspace();
    bool setupTables();
};

db::ConnectionManager::ConnectionManager()
    : m_deepPtr{new ConnectionManagerPrivate{}}
{
    const bool setupResult {m_deepPtr->setup()};
    m_deepPtr->isValid = setupResult;
}

db::ConnectionManager::~ConnectionManager()
{

}

bool db::ConnectionManager::isValid() const
{
    return m_deepPtr->isValid;
}

db::ConnectionManager &db::ConnectionManager::instance()
{
    static ConnectionManager instance;
    return instance;
}


bool db::ConnectionManager::ConnectionManagerPrivate::setup()
{
    static const QString driver ("QSQLITE");

    if (!QSqlDatabase::isDriverAvailable("QSQLITE")){
        state = DBState::ERROR_NO_DRIVER;
        qCritical()<<"Driver" << driver << "is not available";
        return false;
    }
    if (!setupWorkspace()){
        state = DBState::ERROR_WORKSPACE;
        qCritical() << "Workspace setup failed";
        return false;
    }

    database.reset(new QSqlDatabase {QSqlDatabase::addDatabase(driver)});
    database->setDatabaseName(dbPath);

    qDebug() << "Database name: "<< database->databaseName();
    if (!database->open()){
        state = DBState::ERROR_OPENING;
        qCritical() << "Database " << database->databaseName() << " opening failed"
                    << ", error: "<< database->lastError().text();
        return false;
    }

    return setupTables();
}

bool db::ConnectionManager::ConnectionManagerPrivate::setupWorkspace()
{
#ifdef BUILD_TESTS
    static const QString databaseName {"TestDB.sqlite"};
#else
    static const QString databaseName {"NotesDB.sqlite"};
#endif
    const QString location {QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)};
    const QString fullPath {location + "/" + databaseName};

    dbPath = fullPath;

    QDir dbDirection {location};
    if (!dbDirection.exists()){
        const bool creationResult {dbDirection.mkpath(location)};
        qInfo() << "DB directory not exists, creating result: " << creationResult;
    }
    qDebug() << "DB path: " << fullPath;
    return dbDirection.exists();
}

bool db::ConnectionManager::ConnectionManagerPrivate::setupTables()
{
    bool result {true};

    QVector<QSqlQuery> creationQuerry{
        QSqlQuery{
            "CREATE TABLE IF NOT EXISTS Notes"
            "("
            "Header TEXT"
            ")"
        }
    };
    for (auto& query:creationQuerry){
        if (!query.exec()){
            result = false;
            state = DBState::ERROR_TABLES;
            qWarning() << "Table creation error: " << query.lastError()
                       << ". Query: \n" << query.lastQuery();
        }
        else {
            qInfo() << "Table successfully created. Query:\n" << query.lastQuery();
        }

    }
    return result;
}
