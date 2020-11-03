#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QAbstractListModel>
#include <QList>


class Task
{
public:

    Task() = default;
    Task(const int id, const QString& header, const QString& date, const QString& time, const QString& info);
    Task(const QString& header, const QString& date, const QString& time);

    int id() const;

    QString header() const;

    QString date() const;

    QString time() const;

    QString info() const;

    QVariantList getfullRowData() const;

private:

    int m_id;
    QString m_header;
    QString m_date;
    QString m_time;
    QString m_info;
};


#endif // TASK_H
