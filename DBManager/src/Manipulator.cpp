#include "Manipulator.h"
#include "DBMapper.h"
#include <sstream>

namespace db{

QPair<DBResult, DBIndex> Manipulator::insertRow(const QString &tableName,const QVariantList &rowData)
{
    const QString& query {generateInsertQuery(tableName, rowData.size())};
    const auto& result {m_executor.execute(query,rowData)};
    return {result.first, result.second.lastInsertId().toInt()};
}

DBResult Manipulator::deleteRow(const QString &tableName, const DBEntry &rowData)
{
    const QString& query {generateDeleteQuery(tableName, rowData.size())};
    const auto& result {m_executor.execute(query, rowData)};
    return result.first;
}

QPair<DBResult, DBIndex> Manipulator::changeRow(const QString &tableName, const int index, const QVariantList& newRowData)
{
    const QString& query {generateChangeQuery(tableName, index, newRowData.size())};
    const auto& result {m_executor.execute(query, newRowData)};
    return {result.first, result.second.lastInsertId().toInt()};
}

QString Manipulator::generateBindString(size_t paramCount) const
{
    std::ostringstream bindings;
    std::fill_n(std::ostream_iterator<std::string>(bindings), paramCount, "?,");

    std::string bindString = bindings.str();
    bindString.pop_back();

    return QString::fromStdString(bindString);
}

QString Manipulator::generateInsertQuery(const QString &tableName, size_t paramCount) const
{
    QString query {"INSERT INTO " + tableName + " (" + tablesMappingWithoutID.value(tableName) + ")" +
                   " VALUES ("};
    query += generateBindString(paramCount);
    query += ")";
    return query;
}

QString Manipulator::generateDeleteQuery(const QString &tableName, size_t paramCount) const
{
    QString query {"DELETE FROM " + tableName + " WHERE" + " (id) = ("};
    query += generateBindString(paramCount);
    query += ")";
    return query;
}

QString Manipulator::generateChangeQuery(const QString &tableName, int index, size_t paramCount) const
{
    QString query {"UPDATE " + tableName + " SET (" + tablesMappingWithoutID.value(tableName) + ") = ("};
    query += generateBindString(paramCount);
    query += ")";
    query +=" WHERE (id) = (" + QString::number(index) + ")";

    return query;
}

//QString Manipulator::generateChangeQueryNewData(const QString &tableName, size_t paramCount) const
//{
//    QString query {" WHERE (" + tablesMapping.value(tableName) + ") = ("};
//    query += generateBindString(paramCount);
//    query += ")";
//    return query;
//}

}
