#include "note.h"

Note::Note(const QString &header)
    : m_header {header}

{    
    if (m_header.isEmpty()){
        m_header = "Undefined";
    }
}

QString Note::header() const
{
    return m_header;
}
