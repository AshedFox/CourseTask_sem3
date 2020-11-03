import QtQuick 2.0
import ComponentsModule.Base 1.0
import Notes 1.0

BaseProtoView {
    id: root
    property alias viewModel2: _notesModel2
    model: NotesModel {
        id: _notesModel2
    }
    delegate: NoteDelegate {
        id: _notes2
        width: root.width
        height: 300
    }
}
