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
private:
    std::unique_ptr<db::Processor> m_processor;
};
