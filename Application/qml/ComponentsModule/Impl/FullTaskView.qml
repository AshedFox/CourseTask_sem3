import QtQuick 2.0
import StyleSettings 1.0
import QtQuick.Controls 2.12
import ComponentsModule.Base 1.0

Item {
    id: root
    property int index
    property var header: ""
    property var info: ""
    property var date: ""
    property var time: ""

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
                _fullTask.visible = false
                _tasksLoader.item.visible = true
            }
        }
        BaseHeaderText {
            text: header
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width/5*3

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

            opacity: Style.emphasisOpacity

            selectByMouse: true
            onTextEdited: {
                _tasksLoader.item.viewModel.changeElement(index, text, date, time)
            }

            readOnly: false
        }
        DateTimeArea {
            id: _dateTime

            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.margins: Style.defaultOffset

            opacity: Style.emphasisOpacity

            timeComp {
                readOnly: false
                inputMask: "99:99"
                inputMethodHints: Qt.ImhDigitsOnly
                text: time

                onAccepted: {
                    editingModeSwap()
                }
                onTextEdited: {
                    if (timeComp.acceptableInput){
                        _tasksLoader.item.viewModel.changeElement(index, header, date, timeComp.text)
                    }
                    else {
                        text = time
                    }
                }
            }
            dateComp {
                readOnly: false
                inputMask: "99.99.9999"
                inputMethodHints: Qt.ImhDigitsOnly
                text: date

                onAccepted: {
                    editingModeSwap()
                }
                onTextEdited: {
                    if (dateComp.acceptableInput){
                        _tasksLoader.item.viewModel.changeElement(index, header, dateComp.text, time)
                    }
                    else {
                        text = date
                    }
                }
            }
        }
    }
    ScrollView {
        width: root.width
        anchors.top: _header.bottom
        anchors.bottom: root.bottom
        opacity: Style.emphasisOpacity
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

            text: info
            onTextChanged: {
                if (text !== info)
                    _tasksLoader.item.viewModel.changeTask(index, text)
            }
        }
        ScrollBar {
                id: vbar
                hoverEnabled: true
                active: hovered || pressed
                orientation: Qt.Vertical
                anchors.right: parent.right

                opacity: Style.emphasisOpacity
        }
    }
}
