import QtQuick 2.0
import StyleSettings 1.0
import QtQuick.Controls 2.0

TextArea {
    id: root
    wrapMode: TextEdit.WrapAtWordBoundaryOrAnywhere

    font.pointSize: 17
    color: Style.textColor
    //focus: true
    selectByMouse: true

}
