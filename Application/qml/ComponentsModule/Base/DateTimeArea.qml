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

//        validator: RegExpValidator {
//            regExp: /^([0-1]?[0-9]|2?[0-3]):([0-5]?[0-9])$/
//        }
    }
    BaseProtoText {
        id: _date
        verticalAlignment: TextInput.AlignVCenter
        horizontalAlignment: TextInput.AlignHCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: Style.textSize/2

//        validator: RegExpValidator {
//            regExp:  /^([1-2]?[0-9]|3?[0-1]|0?[1-9]).(0?[1-9]|1?[0-2]).([1-2]?[0-9]?[0-9]?[0-9])$/
//        }
    }
}
