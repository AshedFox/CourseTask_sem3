#pragma once
#include "DBTypes.h"
#include "Executor.h"
#include <QVariantList>

namespace db {
    class Selector
    {
    public:
        QPair<DBResult,  QVector<DBEntry>> SelectAll(const QString& tableName);
    private:
        Executor m_executor;
        QString generateQuery(const QString& tableName) const;
    };
}

