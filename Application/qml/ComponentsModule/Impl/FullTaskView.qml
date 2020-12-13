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

    AlarmDialog {
        id: _alarmDialog


        onAboutToShow: defineCurrentToAlarmDialog()

        onAccepted: changeDate(date)
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
        _tasksLoader.item.viewModel.changeElement(index, header, date.toLocaleDateString(Qt.locale("en_EN"), "dd.MM.yyyy"),
                                date.toLocaleTimeString(Qt.locale(), "hh:mm"))
        root.date = _dateTime.dateComp.text = date.toLocaleDateString(Qt.locale("en_EN"), "dd.MM.yyyy")
        root.time = _dateTime.timeComp.text = date.toLocaleTimeString(Qt.locale(), "hh:mm")
    }

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
                header = text
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
                text: time

            }
            dateComp {
                text: date

            }
        }
        MouseArea {
            anchors.fill: _dateTime
            hoverEnabled: true
            onClicked: _alarmDialog.open()
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
                if (text !== info) {
                    _tasksLoader.item.viewModel.changeTask(index, text)
                    info = text
                }
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
