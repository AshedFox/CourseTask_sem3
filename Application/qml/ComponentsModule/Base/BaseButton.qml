import QtQuick 2.0
import StyleSettings 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.5

Rectangle {
    id: root

    property alias buttonIcon: _internalImage
    property alias area: _imageArea
    color: "transparent"

    Image {
        id: _internalImage
        anchors.fill: parent
        anchors.margins: Style.mediumOffset
    }
    ColorOverlay {
        id: _overlay
        anchors.fill: _internalImage
        source: buttonIcon
        color: _imageArea.containsMouse ? Style.primaryColor
                                        : Style.themeInvertedColor
        opacity: _imageArea.pressed ? Style.emphasisOpacity
                                    : 1
        antialiasing: true
        smooth: true
    }
    MouseArea {
        id: _imageArea
        anchors.fill: root
        hoverEnabled: true
    }
}
