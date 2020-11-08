import QtQuick 2.0
import StyleSettings 1.0

Rectangle {
    id: root
    color: Style.backgroundColor

    opacity: _delegateArea.pressed ? Style.secondaryOpacity
                                   : Style.emphasisOpacity
    radius: 5
    MouseArea {
        id: _delegateArea
        anchors.fill: root
        //hoverEnabled: true
    }
}
