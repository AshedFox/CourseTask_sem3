import QtQuick 2.0
import StyleSettings 1.0
import QtQuick.Controls 2.12
import ComponentsModule.Base 1.0

Item {
    id: root
    property int index
    property string header
    property string info

    anchors.fill: parent

    Rectangle {
        id: _header
        width: root.width
        height: 80
        color: Style.backgroundColor
        BackButton {
            id: _backButton
            height: _header.height-20
            width: height

            anchors.verticalCenter: parent.verticalCenter

            opacity: Style.emphasisOpacity
            area.onClicked: {
                _fullNote.visible = false
                _notesLoader.item.visible = true
            }
        }
        BaseProtoText {
            text: header
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

            opacity: Style.emphasisOpacity
        }
    }
    ScrollView {
        width: root.width
        anchors.top: _header.bottom
        anchors.bottom: root.bottom
        background:
        Rectangle {
            anchors.fill: parent
            color: Style.backgroundColor
            opacity: Style.emphasisOpacity
            anchors.margins: Style.tinyOffset
            radius: 5
        }
        BaseText {
            id: _textField
            anchors.leftMargin: Style.mediumOffset
            text: info
//            onTextChanged: {
//                if (text !== info)
//                    _notesLoader.item.viewModel.changeTask(index, text)
//            }
//            onEditingFinished: {
//                _notesLoader.item.viewModel.changeNote(index, text)
//            }
        }
        ScrollBar {
                id: _vbar
                hoverEnabled: true
                active: hovered || pressed
                orientation: Qt.Vertical
                anchors.right: parent.right

                opacity: Style.emphasisOpacity
        }
    }
}
