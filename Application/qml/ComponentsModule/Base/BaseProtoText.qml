import QtQuick 2.9
import StyleSettings 1.0
import QtQuick.Controls 2.5

TextInput {
    id: root

    property alias metrics: _metrics

    font.pixelSize: Style.textSize

    readOnly: true
    color: Style.textColor

    maximumLength: 30

    TextMetrics{
        id: _metrics
        font.pixelSize: Style.textSize
    }
}

