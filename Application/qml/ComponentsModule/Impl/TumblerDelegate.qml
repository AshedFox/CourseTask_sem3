import QtQuick 2.11
import QtQuick.Controls 2.4
import StyleSettings 1.0

Text {
    text: modelData
    color: Style.textColor
    font.pixelSize: Style.textSize/2
    opacity: Style.emphasisOpacity - Math.abs(Tumbler.displacement) / (Tumbler.tumbler.visibleItemCount / 2)
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
}
