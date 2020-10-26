#include "Selector.h"
#include <QSqlRecord>


namespace db {

    QPair<DBResult, QVector<DBEntry>> Selector::SelectAll(const QString &tableName)
    {

        QString query = generateQuery(tableName);

        auto pair = m_executor.execute(query);

        QVector<DBEntry> returnData;
        if (pair.first == DBResult::OK){
            returnData.clear();
            returnData.reserve(pair.second.size());
            while (pair.second.next()){
                const QSqlRecord& entryRecord {pair.second.record()};
                QVariantList entryData;
                entryData.reserve(entryRecord.count());
                for (int i =0; i < entryRecord.count(); i++){
                    entryData.push_back(entryRecord.value(i));
                }

                returnData.push_back(entryData);
            }
        }
        return {pair.first, returnData};
    }


    QString Selector::generateQuery(const QString &tableName) const
    {
        QString query{"SELECT rowid, * FROM " + tableName};
        return query;
    }

}
