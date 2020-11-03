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

QVector<Note> transformNote(const QVector<db::DBEntry>& source){
    QVector<Note> target;
    std::transform(source.begin(),source.end(), std::back_inserter(target),
            [] (const db::DBEntry& entry){
        return Note {entry[1].toInt(),
                     entry[2].toString(),
                     entry[3].toString()
        };
    });
    return target;
}

QPair<bool, QVector<Note> > NotesReader::requestNotesBrowse()
{
    QPair<db::DBResult, QVector<db::DBEntry>> pair;
    pair = m_processor->requestTableData(db::DBTables::Notes);
    return {pair.first == db::DBResult::OK, transformNote(pair.second)};
}

int NotesReader::requestNoteAddition(const QVariantList &addData)
{
   return m_processor->insertData("Notes", addData);
}

bool NotesReader::requestNoteDeletion(const QVariantList& deleteData)
{
    m_processor->deleteData("Notes", deleteData);
    return true;
}

bool NotesReader::requestNoteChange(const int index, const QVariantList &newData)
{
    m_processor->changeData("Notes", index, newData);
    return true;
}
