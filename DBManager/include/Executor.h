#pragma once
#include "ConnectionManager.h"
#include "DBTypes.h"
#include <QString>
#include <QVariantList>
#include <QSqlQuery>
#include <QPair>

namespace db {
    class Executor
    {
    public:
        Executor();
        Q_DISABLE_COPY(Executor)

        QPair<DBResult,
                  QSqlQuery> execute(const QString& queryText, const QVariantList& args = {});

    private:
        ConnectionManager& m_connectionManager;
    };
}
