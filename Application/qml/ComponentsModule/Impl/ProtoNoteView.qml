import QtQuick 2.0
import ComponentsModule.Base 1.0
import Notes 1.0


BaseProtoView {
    id: root
    property alias viewModel: _notesModel
    model: NotesModel {
        id: _notesModel
    }
    delegate: ProtoNoteDelegate {
        id: _notes
        width: root.width
        height: 80
    }

}
