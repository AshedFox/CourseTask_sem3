import QtQuick 2.0
import StyleSettings 1.0
import QtQuick.Controls 2.0

TextArea {
    id: root
    wrapMode: TextEdit.WrapAtWordBoundaryOrAnywhere

    font.pixelSize: Style.textSize /2
    color: Style.textColor

    selectByMouse: true
}
