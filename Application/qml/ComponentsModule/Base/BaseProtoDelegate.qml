import QtQuick 2.0
import StyleSettings 1.0

Rectangle {
    id: root
    color: Style.backgroundColor
    layer.enabled: true
    opacity: _delegateArea.pressed ? Style.secondaryOpacity
                                   : 1
    MouseArea {
        id: _delegateArea
        anchors.fill: root
    }
}
