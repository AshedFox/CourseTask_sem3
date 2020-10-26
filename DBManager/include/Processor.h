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
        void insertData(const QString& tableName, const QVariantList& rowData);

    private:
        struct ProcessorPrivate;
        std::unique_ptr<ProcessorPrivate> m_deepPtr;
    };
}




