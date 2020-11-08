#include "task.h"

Task::Task(const int id, const QString& header, const QString& date, const QString& time, const QString& info)
    : m_id {id},
      m_header{header},
      m_date{date},
      m_time{time},
      m_info{info}
{

}

Task::Task(const QString& header, const QString& date, const QString& time, const QString& info)
    : m_header{header},
      m_date{date},
      m_time{time},
      m_info{info}

{

}

int Task::id() const
{
    return m_id;
}

QString Task::header() const
{
    return m_header;
}


QString Task::date() const
{
    return m_date;
}

QString Task::time() const
{
    return m_time;
}

QString Task::info() const
{
    return m_info;
}

QVariantList Task::getfullRowData() const
{
    return {m_id, m_header, m_date, m_time, m_info};
}
