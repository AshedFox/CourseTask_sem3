#include "notesmodel.h"
#include <QQmlEngine>
#include <QDebug>

NotesModel::NotesModel()
{
    const bool updateResult {updateNotes()};
    if (!updateResult) {
         qWarning() << "Notes update failed;";
    }
}


void NotesModel::registerMe(const std::string& moduleName)
{
    qmlRegisterType<NotesModel>(moduleName.c_str(), 1, 0, "NotesModel");
}

QHash<int, QByteArray> NotesModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NoteRoles::idRole] = "id";
    roles[NoteRoles::HeaderRole] = "header";
    roles[NoteRoles::InfoRole] = "info";
    return roles;
}

bool NotesModel::deleteElement(int index)
{
    beginRemoveRows(QModelIndex(), index,index);
    m_NotesReader.requestNoteDeletion({m_Notes.at(index).id()});
    m_Notes.removeAt(index);
    endRemoveRows();
    return true;
}

bool NotesModel::addElement(QString header)
{
    beginInsertRows(QModelIndex(), m_Notes.size(), m_Notes.size());
    m_Notes.push_back({m_NotesReader.requestNoteAddition({header, ""}), header, ""});
    endInsertRows();
    return true;
}

bool NotesModel::changeElement(int index, QString header)
{
    m_NotesReader.requestNoteChange(m_Notes.at(index).id(), {header, m_Notes.at(index).info()});
    Note oldData {m_Notes.at(index).id(), header, m_Notes.at(index).info()};
    m_Notes.removeAt(index);
    m_Notes.insert(index, oldData);
    emit dataChanged(createIndex(index,0), createIndex(index,0));
    return true;
}

bool NotesModel::changeNote(int index, QString info)
{
    m_NotesReader.requestNoteChange(m_Notes.at(index).id(), {m_Notes.at(index).header(),info});
    Note oldData {m_Notes.at(index).id(), m_Notes.at(index).header(), info};
    m_Notes.removeAt(index);
    m_Notes.insert(index, oldData);
    emit dataChanged(createIndex(index,0), createIndex(index,0));
    return true;
}


bool NotesModel::updateNotes()
{
    QPair<bool, QVector<Note>> MyPair;
    MyPair = m_NotesReader.requestNotesBrowse();

    if (MyPair.first){
        m_Notes.swap(MyPair.second);
        emit dataChanged(createIndex(0,0), createIndex(m_Notes.size(), 0));
    }
    return MyPair.first;
}

int NotesModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_Notes.size();
}

QVariant NotesModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row()>rowCount(index)){
        return {};
    }

    const Note& Note {m_Notes.at(index.row())};

    switch (role) {
    case NoteRoles::idRole:{
        return QVariant::fromValue(Note.id());
    }
    case NoteRoles::HeaderRole:{
        return QVariant::fromValue(Note.header());
    }
    case NoteRoles::InfoRole: {
        return QVariant::fromValue(Note.info());
    }

    default:
        return true;
    }
}
