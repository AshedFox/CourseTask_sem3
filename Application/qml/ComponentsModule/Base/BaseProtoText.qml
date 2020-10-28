import QtQuick 2.9
import StyleSettings 1.0
import QtQuick.Controls 2.5

TextInput {
    id: root   

    font.pointSize: 25
    readOnly: true
    color: Style.textColor
    text: fullText
    onEditingFinished: {
        readOnly = true

    }
}

