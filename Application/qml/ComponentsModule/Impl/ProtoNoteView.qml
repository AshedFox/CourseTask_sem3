import QtQuick 2.12
import QtQuick.Controls 2.12
import ComponentsModule.Base 1.0
import StyleSettings 1.0
import Notes 1.0


BaseProtoView {
    id: root
    property alias viewModel: _notesModel
    model: NotesModel {
        id: _notesModel
    }
    delegate: ProtoNoteDelegate {
        id: _note
        width: root.width
        height: Style.notesSize
    }

}
