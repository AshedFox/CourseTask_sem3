import QtQuick 2.9
import StyleSettings 1.0
import ResourceProvider 1.0
import QtQuick.Controls 2.5
import ComponentsModule.Base 1.0

BaseProtoDelegate {
    id: root
    property alias delegateArea: _delegateArea
    BaseHeaderText {
        id: _header

        anchors.left: root.left
        anchors.right: _buttons.left
        anchors.leftMargin: Style.defaultOffset * 2
        anchors.rightMargin: Style.defaultOffset
        anchors.verticalCenter: parent.verticalCenter

        verticalAlignment: Text.AlignVCenter
        selectByMouse: true

        text: header

        onTextEdited: {
            viewModel.changeElement(index, text)
        }
        onAccepted: {
            readOnly = true
        }
    }

    opacity: _delegateArea.pressed ? Style.secondaryOpacity
                                   : Style.emphasisOpacity
    MouseArea {
        id: _delegateArea
        anchors.fill: root
        enabled: _header.readOnly ? true : false

        onClicked: {
            forceActiveFocus()

            _notesLoader.item.visible = false

            _fullNote.index = index
            _fullNote.header = header
            _fullNote.info = info

            _fullNote.visible = true
        }
    }

    Row {
        id: _buttons
        anchors.right: root.right
        anchors.verticalCenter: root.verticalCenter
        anchors.margins: Style.tinyOffset
        height: root.height
        Rectangle {
            id: _separator
        }
        ChangeButton{
            height: parent.height
            width: height
            area.onClicked: {
                _header.readOnly = !_header.readOnly
                _header.forceActiveFocus()
            }

        }
        DeleteButton{
            height: parent.height
            width: height
            area.onClicked: viewModel.deleteElement(index)
        }
    }
}
