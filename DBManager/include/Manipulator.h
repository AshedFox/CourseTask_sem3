#pragma once
#include "Executor.h"
#include "DBTypes.h"

namespace db
{
class Manipulator
{
public:
    QPair<DBResult, DBIndex> insertRow(const QString& tableName,const QVariantList& rowData);
    DBResult deleteRow(const QString& tableName, const DBEntry& rowData);
    QPair<DBResult, DBIndex> changeRow(const QString& tableName, const int index, const QVariantList& newRowData);

private:
    Executor m_executor;
    QString generateBindString(size_t paramCount) const;
    QString generateInsertQuery(const QString& tableName, size_t paramCount) const;
    QString generateDeleteQuery(const QString& tableName, size_t paramCount) const;

    QString generateChangeQuery(const QString& tableName, const int index, size_t paramCount) const;
};
}

