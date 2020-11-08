import QtQuick 2.12
import QtQuick.Window 2.12
import StyleSettings 1.0
import ComponentsModule.Impl 1.0
import QtQuick.Controls 2.12
import ComponentsModule.Base 1.0
import QtGraphicalEffects 1.0

Window {
    id: root
    minimumWidth: 900
    minimumHeight: 600
    visible: true
    width: 900
    height: 600
    title: qsTr("APP")

//    Popup {
//        id: popup
//        width: 400
//        height: parent.height
//        modal: true
//        visible: true
//        background: Rectangle{
//            color: Style.primaryColor
//        }

//        Overlay.modal: Rectangle {
//            color: "#90121212"
//        }
//    }

    Page {
        id: _page

        anchors.fill: parent

        property alias currentView: _list

        background: Rectangle {
            id: _background
            color: Style.backgroundColor
            opacity: Style.emphasisOpacity
        }


        SwipeView {
            id: _list

            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom

            clip: true

            spacing: Style.minimalOffset
            anchors.margins: Style.minimalOffset

            Loader {
                sourceComponent: _tasks
            }
            Loader {
                sourceComponent: _notes
            }
//            onCurrentItemChanged: {
//                _curCategoryName.text = _curCategoryName.text === "Notes" ? "Tasks" : "Notes"
//            }

        }

//        header: Rectangle {
//            color: Style.backgroundColor
//            opacity: Style.emphasisOpacity
//            height: 80

//            Row {
//                anchors.verticalCenter: parent.verticalCenter
//                anchors.horizontalCenter: parent.horizontalCenter
//                BaseProtoText {

//                    text: "Current category: "
//                }
//                BaseProtoText {
//                    id: _curCategoryName
//                    text: _list.currentItem === _tasks ? "Notes" : "Tasks"
//                    color: Style.primaryColor
//                }
//            }
//        }

        footer: Rectangle {
            id: _indicator
            color: Style.backgroundColor
            opacity: Style.emphasisOpacity
            height: 50

            AddButton {
                id: _addButton
                width: 50
                height: 50
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter

                property date basicTime: new Date()
                property date basicDate: new Date()
                area.onClicked: {
                    _list.currentItem.sourceComponent === _tasks
                            ? _list.currentItem.item.viewModel.addElement("", basicTime.toLocaleDateString("dd/mm/yyyy"),
                                                                          basicTime.toLocaleTimeString("hh:mm AP"))
                            : _list.currentItem.item.viewModel.addElement("")
                 }
            }

            PageIndicator{
                count: _list.count
                currentIndex: _list.currentIndex

                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter

                delegate: Rectangle {
                    implicitWidth: 14
                    implicitHeight: 14

                    radius: width / 2

                    color: Style.primaryColor
                    opacity: index === _list.currentIndex ? Style.defaultOpacity : Style.disabledOpacity

                }
            }
        }

        Component {
            id: _notes
            ProtoNoteView {

                //ScrollBar.vertical: ScrollBar{}
            }
        }
        Component {
            id: _tasks
            ProtoTasksView{}
        }

//        CatalogueOverlay{
//            id: _overlay

//            property date basicTime: new Date()
//            property date basicDate: new Date()
//            addButton.area.onClicked: {
//                _list.currentItem.sourceComponent === _tasks ? _list.currentItem.item.viewModel.addElement("", basicTime.toLocaleDateString(), basicTime.toLocaleTimeString())
//                                                 : _list.currentItem.item.viewModel.addElement("")
//             }
//        }
    }

//    ColorOverlay {
//        anchors.fill: parent
//        color: Style.backgroundColor
//        opacity: Style.minimalOpacity
//        antialiasing: true

//    }
}
