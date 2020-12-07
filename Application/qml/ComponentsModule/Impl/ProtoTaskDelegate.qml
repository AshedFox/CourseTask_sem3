import QtQuick 2.9
import StyleSettings 1.0
import ResourceProvider 1.0
import QtQuick.Controls 2.5
import ComponentsModule.Base 1.0

BaseProtoDelegate {
    id: root
    property bool isInEditing: false

    BaseHeaderText {
        id: _header

        anchors.left: root.left
        anchors.right: _dateTime.left        
        anchors.leftMargin: Style.defaultOffset * 2
        anchors.rightMargin: Style.defaultOffset
        anchors.verticalCenter: parent.verticalCenter

        verticalAlignment: Text.AlignVCenter

        text: header
        selectByMouse: true
        onTextEdited: {         
            viewModel.changeElement(index, text, date, time)
        }
        onAccepted: {
             editingModeSwap()
        }
    }

    DateTimeArea {
        id: _dateTime

        anchors.right: _buttons.left
        anchors.verticalCenter: parent.verticalCenter

        timeComp {
            inputMask: "99:99"
            inputMethodHints: Qt.ImhDigitsOnly
            text: time

            onAccepted: {
                editingModeSwap()
            }
            onTextEdited: {
                if (timeComp.acceptableInput){
                    viewModel.changeElement(index, header, date, timeComp.text)
                }
                else {
                    text = time
                }
            }
        }
        dateComp {
            inputMask: "99.99.9999"
            inputMethodHints: Qt.ImhDigitsOnly
            text: date

            onAccepted: {
                editingModeSwap()
            }
            onTextEdited: {
                if (dateComp.acceptableInput){
                    viewModel.changeElement(index, header, dateComp.text, time)
                }
                else {
                    text = date
                }
            }
        }

    }

    opacity: _delegateArea.pressed ? Style.secondaryOpacity
                                   : Style.emphasisOpacity
    MouseArea {
        id: _delegateArea
        anchors.fill: root
        enabled: isInEditing ? false : true
        onClicked: {
            forceActiveFocus()

            if (isInEditing) {
                editingModeSwap()
            }

            _tasksLoader.item.visible = false

            _fullTask.index = index
            _fullTask.header = header
            _fullTask.date = date
            _fullTask.time = time
            _fullTask.info = info

            _fullTask.visible = true
        }
    }

    function editingModeSwap(){
        isInEditing = !isInEditing
        _header.readOnly = !isInEditing
        _dateTime.dateComp.readOnly = !isInEditing
        _dateTime.timeComp.readOnly = !isInEditing
        if (isInEditing)
            _header.forceActiveFocus()
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
            area.onClicked: editingModeSwap()
        }
        DeleteButton{
            height: parent.height
            width: height
            area.onClicked: viewModel.deleteElement(index)
        }
    }
}
