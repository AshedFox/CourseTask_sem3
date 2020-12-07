import QtQuick 2.0
import ComponentsModule.Base 1.0
import QtQuick.Controls 2.5
import StyleSettings 1.0

Popup {
    id: _root
    width: 250
    height: parent.height
    modal: true
    visible: false
    background: Rectangle{
        color: Style.backgroundColor
    }

    Column {
        anchors.left: parent.left

        //width: parent.width
        //height: parent.height

        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: Style.mediumSpacing
        spacing: Style.mediumSpacing
        Row{
            BaseProtoText{
                readOnly: true
                text: "SIZE "
                font.pixelSize: 36
            }

            Slider{
                width: 130
                from: 1
                to: 3

                snapMode: Slider.SnapAlways

                stepSize: 1

                value: Style.sizeMode

                onValueChanged: {
                    if (SettingsPromoter)
                        SettingsPromoter.setSizeMode(value)
                }

                height: parent.height

            }
        }
        Row{
            BaseProtoText{
                readOnly: true
                text: "THEME "
                font.pixelSize: 36
            }

            Switch{
                width: 100
                height: parent.height

                checked: Style.isDarkTheme

                onCheckedChanged: {
                    if(SettingsPromoter)
                        SettingsPromoter.setIsDarkTheme(checked)
                }
            }
        }
    }
}
