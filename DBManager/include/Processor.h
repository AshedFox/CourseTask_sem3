#pragma once
#include "DBTypes.h"
#include <memory>
#include <QVector>

namespace db {
    class Processor
    {
    public:
        Processor();
        ~Processor();
        QPair <DBResult, QVector<DBEntry>> requestTableData(DBTables table);
        int insertData(const QString& tableName, const QVariantList& rowData);
        void deleteData(const QString& tableName, const QVariantList& rowData);
        void changeData(const QString& tableName, const int index, const QVariantList& newRowData);

    private:
        struct ProcessorPrivate;
        std::unique_ptr<ProcessorPrivate> m_deepPtr;
    };
}




