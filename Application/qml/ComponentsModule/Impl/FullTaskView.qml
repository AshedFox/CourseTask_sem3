import QtQuick 2.0
import StyleSettings 1.0
import QtQuick.Controls 2.12
import ComponentsModule.Base 1.0

Item {
    id: root
    property int index
    property string header
    property string info
    property string date
    property string time

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
                _fullTask.visible = false
                _tasksLoader.item.visible = true
            }
        }
        BaseProtoText {
            text: header
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            opacity: Style.emphasisOpacity            
        }
        Column {
            id: _dateTime

            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            opacity: Style.emphasisOpacity
            anchors.margins: Style.tinyOffset
            anchors.rightMargin: Style.defaultOffset

            BaseText {
                id: _time
                verticalAlignment: Text.AlignVCenter
                anchors.horizontalCenter: parent.horizontalCenter
                readOnly: true
                text: time

            }
            BaseText {
                id: _date
                verticalAlignment: Text.AlignVCenter
                anchors.horizontalCenter: parent.horizontalCenter
                readOnly: true
                text: date
            }
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
//                    _tasksLoader.item.viewModel.changeTask(index, text)
//            }
//            onEditingFinished: {
//                _tasksLoader.item.viewModel.changeTask(index, text)
//            }
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
