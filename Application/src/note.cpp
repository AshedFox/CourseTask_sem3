#include "note.h"

Note::Note(const int id, const QString &header)
    : m_id {id},
      m_header{header}
{

}

Note::Note(const QString &header)
    : m_header {header}

{    
//    if (m_header.isEmpty()){
//        m_header = "Undefined";
//    }
}

int Note::getId() const
{
    return m_id;
}

QString Note::header() const
{
    return m_header;
}

QVariantList Note::getfullRowData() const
{
//    QVariantList result {m_id, m_header};
    return {m_id, m_header};
}
