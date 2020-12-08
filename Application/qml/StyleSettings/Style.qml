pragma Singleton
import QtQuick 2.0

QtObject {
    property bool isDarkTheme: SettingsPromoter ? SettingsPromoter.isDarkTheme : 1

    enum ComponentsSizes{
        Small = 1,
        Medium = 2,
        Big = 3
    }

    property int sizeMode: SettingsPromoter ? SettingsPromoter.sizeMode : 1

    readonly property int notesSize: sizeMode == 1 ? 60 : (sizeMode == 2 ? 80 : 100)
    readonly property int textSize: sizeMode == 1 ? 39 : (sizeMode == 2 ? 52 : 65)

    readonly property color primaryColor: isDarkTheme ? "#FF69B4" : "#B00000"
    readonly property color primaryVariantColor: "#3700B3"
    readonly property color secondaryColor: "#03DAC6"
    readonly property color secondaryVariant: isDarkTheme ? "#018786" : secondaryColor
    readonly property color backgroundColor: isDarkTheme ? "#121212" : "#A0A0A0"
    readonly property color errorColor: isDarkTheme ? "#CF6679" : "#B00020"
    readonly property color textColor: isDarkTheme ? "#FFFFFF" : "#000000"
    readonly property color themeDefaultColor: isDarkTheme ? "#101010" : "#FFFFFF"
    readonly property color themeInvertedColor: isDarkTheme ? "#FFFFFF" : "#101010"

    readonly property real defaultOpacity: 1
    readonly property real emphasisOpacity: 0.87
    readonly property real secondaryOpacity: 0.6
    readonly property real disabledOpacity: 0.38
    readonly property real minimalOpacity: 0.1

    readonly property int defaultOffset: 15
    readonly property int mediumOffset: 10
    readonly property int tinyOffset: 5
    readonly property int minimalOffset: 2

    readonly property int bigSpacing: 20
    readonly property int mediumSpacing: 10
    readonly property int smallSpacing: 7
}
