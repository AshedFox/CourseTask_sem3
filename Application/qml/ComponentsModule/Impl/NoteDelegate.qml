import QtQuick 2.9
import StyleSettings 1.0
import ResourceProvider 1.0
import QtQuick.Controls 2.5
import ComponentsModule.Base 1.0

BaseNoteDelegate {
    id: root
    //anchors.fill: parent
    BaseProtoText {
        id: _header

        anchors.left: root.left
        anchors.right: root.right
        anchors.top: root.top
        anchors.leftMargin: Style.defaultOffset
        verticalAlignment: Text.AlignVCenter
        height: 80

        text: header
    }
    BaseText {
        id: _note
        anchors.leftMargin: Style.mediumOffset
        anchors.top: _header.bottom
        anchors.bottom: root.bottom
        anchors.left: root.left
        anchors.right: root.right
        width: parent.index

        text: info
    }
}
