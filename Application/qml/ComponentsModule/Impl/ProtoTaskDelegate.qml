import QtQuick 2.9
import StyleSettings 1.0
import ResourceProvider 1.0
import QtQuick.Controls 2.5
import ComponentsModule.Base 1.0

BaseProtoDelegate {
    id: root
    property bool isInEditing: false

    AlarmDialog {
        id: _alarmDialog

        y:{
           if (count > 4 && index === count-1)
               y = -100
           else
               y = 0
        }
        onAboutToShow: {
            defineCurrentToAlarmDialog()
        }

        onAccepted: changeDate(date)
    }
    DeleteDialog{
        id: _deleteDialog

        y:{
           if (count > 4 && index === count-1)
               y = -Style.notesSize
           else
               y = 0
        }

        onAccepted: deleteTask()
    }

    function defineCurrentToAlarmDialog() {
        var num = time.slice(3,5)
        _alarmDialog.minutesTumbler.currentIndex = num
        num = time.slice(0, 2)
        _alarmDialog.hoursTumbler.currentIndex = num
        num = date.slice(0, 2)
        _alarmDialog.dayTumbler.currentIndex = num - 1
        num = date.slice(3, 5)
        _alarmDialog.monthTumbler.currentIndex = num - 1
        num = date.slice(6, 10)
        num -= _alarmDialog.yearTumbler.years[0]
        _alarmDialog.yearTumbler.currentIndex = num
    }

    function changeDate(date){
        viewModel.changeElement(index, header, date.toLocaleDateString(Qt.locale("en_EN"), "dd.MM.yyyy"),
                                date.toLocaleTimeString(Qt.locale(), "hh:mm"))
    }
    function deleteTask(){
        viewModel.deleteElement(index)
    }

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
            text: time

            onAccepted: {
                editingModeSwap()
            }
        }
        dateComp {
            text: date

            onAccepted: {
                editingModeSwap()
            }
        }
    }
    MouseArea {
        anchors.fill: _dateTime
        hoverEnabled: true
        onClicked: _alarmDialog.open()
    }

    opacity: _delegateArea.pressed ? Style.secondaryOpacity
                                   : Style.emphasisOpacity
    MouseArea {
        id: _delegateArea
        anchors.fill: root
        enabled: isInEditing ? false : true
        onClicked: {
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
        if (isInEditing) {
            opacity = Style.secondaryOpacity
            _header.forceActiveFocus()
        }
        else {
            opacity = Style.emphasisOpacity
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
            area.onClicked: editingModeSwap()
        }
        DeleteButton{
            height: parent.height
            width: height
            area.onClicked: _deleteDialog.open()
        }
    }
}
