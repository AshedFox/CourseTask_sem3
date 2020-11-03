#include "tasksmodel.h"

#include <QQmlEngine>
#include <QDebug>

TasksModel::TasksModel()
{
    const bool updateResult {updateTasks()};
    if (!updateResult) {
         qWarning() << "Tasks update failed;";
    }
}


void TasksModel::registerMe(const std::string& moduleName)
{
    qmlRegisterType<TasksModel>(moduleName.c_str(), 1, 0, "TasksModel");
}

QHash<int, QByteArray> TasksModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TaskRoles::idRole] = "id";
    roles[TaskRoles::HeaderRole] = "header";
    roles[TaskRoles::DateRole] = "date";
    roles[TaskRoles::TimeRole] = "time";
    roles[TaskRoles::InfoRole] = "info";
    return roles;
}

bool TasksModel::deleteElement(int index)
{
    beginRemoveRows(QModelIndex(), index,index);
    m_TasksReader.requestTaskDeletion({m_Tasks.at(index).id()});
    m_Tasks.removeAt(index);
    endRemoveRows();
    return true;
}

bool TasksModel::addElement(QString header, QString date, QString time)
{
    beginInsertRows(QModelIndex(), m_Tasks.size(), m_Tasks.size());
    m_Tasks.push_back({m_TasksReader.requestTaskAddition({header, date, time, ""}), header, date, time, ""});
    endInsertRows();
    return true;
}

bool TasksModel::changeElement(int index, QString header, QString date, QString time)
{
    m_TasksReader.requestTaskChange(m_Tasks.at(index).id(), {header});
    m_Tasks.removeAt(index);
    m_Tasks.insert(index, {header, date, time});
    return true;
}

bool TasksModel::changeTask(int index, QString info)
{
    m_TasksReader.requestTaskChange(m_Tasks.at(index).id(), {m_Tasks.at(index).header(),info});
    Task oldData = {m_Tasks.at(index).header(), m_Tasks.at(index).date(), m_Tasks.at(index).time()};
    m_Tasks.removeAt(index);
    m_Tasks.insert(index, oldData);
    return true;
}


bool TasksModel::updateTasks()
{
    QPair<bool, QVector<Task>> MyPair;
    MyPair = m_TasksReader.requestTasksBrowse();

    if (MyPair.first){
        m_Tasks.swap(MyPair.second);
        emit dataChanged(createIndex(0,0), createIndex(m_Tasks.size(), 0));
    }
    return MyPair.first;
}

int TasksModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_Tasks.size();
}

QVariant TasksModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row()>rowCount(index)){
        return {};
    }

    const Task& Task {m_Tasks.at(index.row())};

    switch (role) {
    case TaskRoles::idRole:{
        return QVariant::fromValue(Task.id());
    }
    case TaskRoles::HeaderRole:{
        return QVariant::fromValue(Task.header());
    }
    case TaskRoles::InfoRole: {
        return QVariant::fromValue(Task.info());
    }

    default:
        return true;
    }
}
