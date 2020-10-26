#pragma once
#include "Executor.h"
#include "DBTypes.h"

namespace db
{
class Manipulator
{
public:
    QPair<DBResult, DBIndex> insertRow(const QString& tableName, const QVariantList& rowData);

private:
    Executor m_executor;
    QString generateBindString(size_t paramCount) const;
    QString generateInsertQuery(const QString& tableName, size_t paramCount) const;
    //QString generateSetString(const QVector<QString>& columns, const QVariantList& values) const;
};
}

