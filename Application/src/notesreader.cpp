#include "notesreader.h"
#include "Processor.h"
#include "DBTypes.h"

NotesReader::NotesReader()
    : m_processor {new db::Processor{}}
{

}

NotesReader::~NotesReader()
{

}

QVector<Note> transform(const QVector<db::DBEntry>& source){
    QVector<Note> target;
    std::transform(source.begin(),source.end(), std::back_inserter(target),
            [] (const db::DBEntry& entry){
        return Note {entry[1].toString()
        };
    });
    return target;
}

QPair<bool, QVector<Note> > NotesReader::requestNotesBrowse()
{
    QPair<db::DBResult, QVector<db::DBEntry>> pair;
    pair = m_processor->requestTableData(db::DBTables::Notes);
    return {pair.first == db::DBResult::OK, transform(pair.second)};
}
