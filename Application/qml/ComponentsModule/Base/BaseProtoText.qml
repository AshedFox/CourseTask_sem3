import QtQuick 2.9
import StyleSettings 1.0
import QtQuick.Controls 2.5

TextInput {
    id: root

    font: _metrics.font
    readOnly: true
    color: Style.textColor
    //wrapMode: TextInput.WrapAtWordBoundaryOrAnywhere

    maximumLength: 40

    TextMetrics{
        id: _metrics
        font.pixelSize: Style.textSize
    }
}

