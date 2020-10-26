#pragma once
#include <QAbstractListModel>
#include <QVector>
#include "note.h"
#include "notesreader.h"
#include <QDebug>

class NotesModel : public QAbstractListModel
{
    Q_OBJECT

public:
    NotesModel();

    static void registerMe(const std::string& moduleName);

    int rowCount(const QModelIndex& parent = {}) const override;

    QVariant data(const QModelIndex& index = {}, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE bool deleteElement(int index);

private:
    NotesReader m_NotesReader;

    QVector<Note> m_Notes;


    enum NoteRoles {
        HeaderRole = Qt::UserRole+1
    };

    bool updateNotes();
};

