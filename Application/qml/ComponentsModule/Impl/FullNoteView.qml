import QtQuick 2.0
import StyleSettings 1.0
import QtQuick.Controls 2.12
import ComponentsModule.Base 1.0

Item {
    id: root
    property int index
    property var header: ""
    property var info: ""

    anchors.fill: parent

    Rectangle {
        id: _header
        width: root.width
        height: Style.notesSize
        color: Style.backgroundColor

        BackButton {
            id: _backButton
            height: _header.height-20
            width: height

            anchors.verticalCenter: parent.verticalCenter

            opacity: Style.emphasisOpacity
            area.onClicked: {
                _notesLoader.item.visible = true
                _fullNote.visible = false
            }
        }
        BaseHeaderText {
            text: header

            anchors.verticalCenter: parent.verticalCenter
            anchors.left: _backButton.right
            anchors.right: parent.right

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

            opacity: Style.emphasisOpacity

            readOnly: false

            selectByMouse: true

            onTextEdited: {
                _notesLoader.item.viewModel.changeElement(index, text)
                header = text
            }
        }
    }
    ScrollView {
        width: root.width
        anchors.top: _header.bottom
        anchors.bottom: root.bottom
        opacity: Style.emphasisOpacity
        background: Rectangle {
            anchors.fill: parent
            color: Style.backgroundColor
            opacity: Style.emphasisOpacity
            anchors.margins: Style.tinyOffset
            radius: 5
        }
        BaseText {
            id: _textField
            text: info
            onTextChanged: {
                if (text !== info) {
                    _notesLoader.item.viewModel.changeNote(index, text)
                    info = text
                }
            }
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
