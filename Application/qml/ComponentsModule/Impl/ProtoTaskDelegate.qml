import QtQuick 2.9
import StyleSettings 1.0
import ResourceProvider 1.0
import QtQuick.Controls 2.5
import ComponentsModule.Base 1.0

BaseProtoDelegate {
    id: root
    BaseProtoText {
        id: _header
        property string fullText: header

        anchors.left: root.left
        anchors.right: _dateTime.left        
        anchors.leftMargin: Style.defaultOffset * 2
        anchors.verticalCenter: parent.verticalCenter

        verticalAlignment: Text.AlignVCenter

        text: fullText
        onTextEdited: {
            fullText = text
            viewModel.changeElement(index, text, date, time)
        }

    }
    Column {
        id: _dateTime

        property string fullTime: time
        property string fullDate: date

        anchors.right: _buttons.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: Style.tinyOffset
        anchors.rightMargin: Style.defaultOffset
        BaseText {
            id: _time
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenter: parent.horizontalCenter

            text: _dateTime.fullTime

        }
        BaseText {
            id: _date
            verticalAlignment: Text.AlignVCenter

            text: _dateTime.fullDate
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
            area.onClicked:{
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
