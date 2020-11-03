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
        anchors.margins: Style.mediumOffset
        verticalAlignment: Text.AlignVCenter
        height: parent.height

        text: header
        onEditingFinished: {
            fullText = text
            viewModel.changeElement(index, text)
        }
    }
    Column {
        id: _dateTime
        anchors.left: _header.left
        anchors.right: _buttons.left
        anchors.margins: Style.mediumOffset
        height: parent.height
        BaseText {
            id: _time
            verticalAlignment: Text.AlignVCenter
            anchors.bottom: parent.verticalCenter

            readOnly: true

            property date fullTime: new Date()

            text: fullTime.toLocaleTimeString()

        }
        BaseText {
            id: _date
            verticalAlignment: Text.AlignVCenter
            anchors.top: parent.verticalCenter

            property date fullDate: new Date()

            readOnly: true

            text: fullDate.toLocaleDateString()
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
