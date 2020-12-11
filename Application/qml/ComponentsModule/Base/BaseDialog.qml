import QtQml 2.0
import QtQuick 2.14
import QtQuick.Controls 2.4
import StyleSettings 1.0

Dialog {
    id: root
    modal: true

    onRejected: root.close()


    footer: DialogButtonBox{
        alignment: Qt.AlignBottom
        spacing: 20
        background: Rectangle{
            color: Style.backgroundColor
            radius: 10
        }

        Button{
            DialogButtonBox.buttonRole: DialogButtonBox.RejectRole

            Keys.onEscapePressed: pressed()

            opacity: pressed ? Style.secondaryOpacity : Style.emphasisOpacity
            contentItem: Text {
                font.pixelSize: Style.textSize/2
                color: Style.textColor
                text: qsTr("Cancel");
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            background: Rectangle{
                color: Style.primaryColor
                opacity: Style.emphasisOpacity
                radius: 7
            }
        }
        Button{
            DialogButtonBox.buttonRole: DialogButtonBox.AcceptRole

            opacity: pressed ? Style.secondaryOpacity : Style.emphasisOpacity
            contentItem: Text {
                font.pixelSize: Style.textSize/2
                color: Style.textColor
                text: qsTr("Ok");
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            background: Rectangle{
                color: Style.secondaryColor
                opacity: Style.emphasisOpacity
                radius: 7
            }
        }
    }


    background: Rectangle{
        color: Style.backgroundColor
        radius: 10
    }
}
