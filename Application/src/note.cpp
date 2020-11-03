#include "note.h"

Note::Note(const int id, const QString& header, const QString& info)
    : m_id {id},
      m_header{header},
      m_info{info}
{

}

Note::Note(const QString &header)
    : m_header {header}

{

}

int Note::id() const
{
    return m_id;
}

QString Note::header() const
{
    return m_header;
}

QVariantList Note::getfullRowData() const
{
    return {m_id, m_header, m_info};
}

QString Note::info() const
{
    return m_info;
}
