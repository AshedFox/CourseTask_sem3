import QtQuick 2.0
import QtQuick.Layouts 1.11
import ComponentsModule.Base 1.0
import StyleSettings 1.0

BaseDialog {
    contentItem: RowLayout {
        Text {
            font.pixelSize: Style.textSize
            color: Style.textColor
            text: "Confirm deletion?"
        }
    }
}
