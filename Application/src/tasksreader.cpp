#include "tasksreader.h"

#include "Processor.h"
#include "DBTypes.h"

TasksReader::TasksReader()
    : m_processor {new db::Processor{}}
{

}

TasksReader::~TasksReader()
{

}

QVector<Task> transformTask(const QVector<db::DBEntry>& source){
    QVector<Task> target;
    std::transform(source.begin(),source.end(), std::back_inserter(target),
            [] (const db::DBEntry& entry){
        return Task {entry[1].toInt(),
                     entry[2].toString(),
                     entry[3].toString(),
                     entry[4].toString(),
                     entry[5].toString()
        };
    });
    return target;
}

QPair<bool, QVector<Task> > TasksReader::requestTasksBrowse()
{
    QPair<db::DBResult, QVector<db::DBEntry>> pair;
    pair = m_processor->requestTableData(db::DBTables::Tasks);
    return {pair.first == db::DBResult::OK, transformTask(pair.second)};
}

int TasksReader::requestTaskAddition(const QVariantList &addData)
{
   return m_processor->insertData("Tasks", addData);
}

bool TasksReader::requestTaskDeletion(const QVariantList& deleteData)
{
    m_processor->deleteData("Tasks", deleteData);
    return true;
}

bool TasksReader::requestTaskChange(const int index, const QVariantList &newData)
{
    m_processor->changeData("Tasks", index, newData);
    return true;
}
