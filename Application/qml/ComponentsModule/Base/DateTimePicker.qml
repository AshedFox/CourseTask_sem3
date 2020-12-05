import QtQuick 2.12
import StyleSettings 1.0
import ResourceProvider 1.0
import QtQuick.Controls 2.12

Popup {
    id: root
    modal: true
    background: Rectangle{
        color: Style.primaryColor
    }
    Overlay.modal:
    Row {
        Column {
            Tumbler {
                model: 24
                visibleItemCount: 3
                delegate: Rectangle {
                    width: 20
                    height: 20
                    Text {
                        anchors.fill: parent
                        text: index
                    }
                }
            }
            Tumbler {
                model: 60
                visibleItemCount: 3
                delegate: Rectangle {
                    width: 20
                    height: 20
                    Text {
                        anchors.fill: parent
                        text: index
                    }
                }
            }
        }
        Column {
            Tumbler {
                model: 31
                visibleItemCount: 3
                delegate: Rectangle {
                    width: 20
                    height: 20
                    Text {
                        anchors.fill: parent
                        text: index
                    }
                }
            }
            Tumbler {
                model: 12
                visibleItemCount: 3
                delegate: Rectangle {
                    width: 20
                    height: 20
                    Text {
                        anchors.fill: parent
                        text: index
                    }
                }
            }
            Tumbler {
                model: 50
                visibleItemCount: 3
                delegate: Rectangle {
                    width: 20
                    height: 20
                    Text {
                        anchors.fill: parent
                        text: index+Date().getFullYear
                    }
                }
            }
        }
    }
}
