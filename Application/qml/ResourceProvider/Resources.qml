pragma Singleton
import QtQuick 2.0

Item {
    property alias notes: _Notes
    QtObject {
        id: _Notes
        readonly property string defaultChangeIcon: "qrc:/qml/Resources/changeIcon.svg"
        readonly property string defaultInfoIcon: "qrc:/qml/Resources/menuIcon.svg"
        readonly property string defaultDeleteIcon: "qrc:/qml/Resources/deleteIcon.svg"
    }
}
