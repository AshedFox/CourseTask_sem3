#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "notesmodel.h"
#include "tasksmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    //qmlRegisterType<NotesModel>("Game", 1, 0, "TNotesModel");
    NotesModel::registerMe("Notes");
    TasksModel::registerMe("Tasks");


    QQmlApplicationEngine engine;
    engine.addImportPath(":/qml");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    NotesModel hm;
    engine.rootContext()->setContextObject(&hm);

    engine.load(url);

    return app.exec();
}
