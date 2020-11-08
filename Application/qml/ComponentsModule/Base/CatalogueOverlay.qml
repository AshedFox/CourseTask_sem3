import QtQuick 2.0
import StyleSettings 1.0
import QtGraphicalEffects 1.0

Rectangle {
    id: root
    width: 50
    height: parent.height
    color: Style.backgroundColor

    property alias addButton: _addButton


    Rectangle {
        id: _header
        height: 50
        width: parent.width
        MenuButton {
            height: parent.height
            width: height
            area.onClicked: {
                if (root.width === 200)
                    root.width = 50
                else
                    root.width = 200
            }
        }

        color: Style.backgroundColor
        Rectangle {
            anchors.top: _header.bottom
            width: parent.width
            height: 2
            color: Style.themeInvertedColor
            opacity: Style.emphasisOpacity
        }
    }

    AddButton {
        id: _addButton
        width: 50
        height: 50
        anchors.left: parent.left
        anchors.bottom: parent.bottom
    }

}
