import QtQuick 2.9
import StyleSettings 1.0
import QtQuick.Controls 2.5

Column {
    id: root
    property alias dateComp: _date
    property alias timeComp: _time

    BaseProtoText {
        id: _time
        verticalAlignment: TextInput.AlignVCenter
        horizontalAlignment: TextInput.AlignHCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: Style.textSize/2
    }
    BaseProtoText {
        id: _date
        verticalAlignment: TextInput.AlignVCenter
        horizontalAlignment: TextInput.AlignHCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: Style.textSize/2
    }
}
