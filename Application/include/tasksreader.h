#ifndef TASKSREADER_H
#define TASKSREADER_H

#include <QVector>
#include <memory>
#include "task.h"

namespace db {
    class Processor;
}
class TasksReader
{
public:
    TasksReader();
    ~TasksReader();
    QPair<bool, QVector<Task>> requestTasksBrowse();
    int requestTaskAddition(const QVariantList& addData);
    bool requestTaskDeletion(const QVariantList& deleteData);
    bool requestTaskChange(const int index, const QVariantList& newData);

private:
    std::unique_ptr<db::Processor> m_processor;
};

#endif // TASKSREADER_H
