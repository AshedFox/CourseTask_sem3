#pragma once
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
    Q_INVOKABLE bool addElement(QString header);
    Q_INVOKABLE bool changeElement(int index, QString header);
    Q_INVOKABLE bool changeNote(int index, QString info);


private:
    NotesReader m_NotesReader;

    QVector<Note> m_Notes;

    enum NoteRoles {
        idRole = Qt::UserRole+1,
        HeaderRole,
        InfoRole
    };

    bool updateNotes();
};

