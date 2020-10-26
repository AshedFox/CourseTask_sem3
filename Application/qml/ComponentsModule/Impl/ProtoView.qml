import QtQuick 2.0
import ComponentsModule.Base 1.0
import QtQuick.Controls 2.0
import Notes 1.0
import StyleSettings 1.0


BaseProtoView {
    id: root
    property alias viewModel: _nodesModel
    model: NotesModel {
        id: _nodesModel
    }
    delegate: ProtoDelegate {
        id: _nodes
        width: root.width
        height: 80
    }
}
