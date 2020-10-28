#pragma once
#include <QVector>
#include <memory>
#include "note.h"


namespace db {
    class Processor;
}
class NotesReader
{
public:
    NotesReader();
    ~NotesReader();
    QPair<bool, QVector<Note>> requestNotesBrowse();
    int requestNoteAddition(const QVariantList& addData);
    bool requestNoteDeletion(const QVariantList& deleteData);
    bool requestNoteChange(const int index, const QVariantList& newData);

private:
    std::unique_ptr<db::Processor> m_processor;
};
