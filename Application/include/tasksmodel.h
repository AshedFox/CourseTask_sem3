#ifndef TASKSMODEL_H
#define TASKSMODEL_H

#include <QAbstractListModel>
#include <QVector>
#include "task.h"
#include "tasksreader.h"
#include <QDebug>

class TasksModel : public QAbstractListModel
{
    Q_OBJECT

public:
    TasksModel();

    static void registerMe(const std::string& moduleName);

    int rowCount(const QModelIndex& parent = {}) const override;

    QVariant data(const QModelIndex& index = {}, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE bool deleteElement(int index);
    Q_INVOKABLE bool addElement(QString header, QString date, QString time);
    Q_INVOKABLE bool changeElement(int index, QString header, QString date, QString time);
    Q_INVOKABLE bool changeTask(int index, QString info);


private:
    TasksReader m_TasksReader;

    QVector<Task> m_Tasks;

    enum TaskRoles {
        idRole = Qt::UserRole+1,
        HeaderRole,
        DateRole,
        TimeRole,
        InfoRole
    };

    bool updateTasks();
};

#endif // TASKSMODEL_H
