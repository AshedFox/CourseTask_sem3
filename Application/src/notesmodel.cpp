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
    return roles;
}

bool NotesModel::deleteElement(int index)
{
    beginRemoveRows(QModelIndex(), index,index);
    m_NotesReader.requestNoteDeletion({m_Notes.at(index).getId()});
    m_Notes.removeAt(index);
    endRemoveRows();
    return true;
}

bool NotesModel::addElement(QString header)
{
    beginInsertRows(QModelIndex(), m_Notes.size(), m_Notes.size());
    //m_Notes.push_back({m_Notes.size()+1, header});
    m_Notes.push_back({m_NotesReader.requestNoteAddition({header}), header});
    endInsertRows();
    return true;
}

bool NotesModel::changeElement(int index, QString header)
{
    m_NotesReader.requestNoteChange(m_Notes.at(index).getId(), {header});
    m_Notes.removeAt(index);
    m_Notes.insert(index, header);
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
    case NoteRoles::HeaderRole:{
        return QVariant::fromValue(Note.header());
    }

    default:
        return true;
    }
}
