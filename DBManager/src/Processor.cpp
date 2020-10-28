#include "Processor.h"
#include "Selector.h"
#include "DBMapper.h"
#include "Manipulator.h"
#include <mutex>

namespace db {
    struct Processor::ProcessorPrivate{
        Selector selector;
        Manipulator manipulator;
    };

    Processor::Processor()
        : m_deepPtr {new ProcessorPrivate()}
    {

    }

    Processor::~Processor()
    {

    }

    QPair<DBResult, QVector<DBEntry>> Processor::requestTableData(DBTables table)
    {
        const auto& result = m_deepPtr->selector.SelectAll(tableMapper.value(table));
        return result;
    }

    int Processor::insertData(const QString &tableName, const QVariantList &rowData)
    {
        return m_deepPtr->manipulator.insertRow(tableName,rowData).second;
    }

    void Processor::deleteData(const QString &tableName, const QVariantList &rowData)
    {
        m_deepPtr->manipulator.deleteRow(tableName, rowData);
    }

    void Processor::changeData(const QString &tableName, const int index, const QVariantList &newRowData)
    {
        m_deepPtr->manipulator.changeRow(tableName, index, newRowData);
    }
}

