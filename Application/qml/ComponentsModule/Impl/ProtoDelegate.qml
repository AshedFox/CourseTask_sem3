import QtQuick 2.9
import StyleSettings 1.0
import ResourceProvider 1.0
import QtQuick.Controls 2.5
import ComponentsModule.Base 1.0

BaseProtoDelegate {
    id: root
    BaseProtoText {
        id: _header

        anchors.left: root.left
        anchors.right: _buttons.left
        anchors.margins: Style.mediumOffset       
        verticalAlignment: Text.AlignVCenter
        height: parent.height

        text: header
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
            area.onClicked:{
                _header.readOnly = !_header.readOnly
                _header.forceActiveFocus()
            }
        }
        DeleteButton{
            height: parent.height
            width: height
            area.onClicked: _nodesModel.deleteElement(index)
        }
    }
}
