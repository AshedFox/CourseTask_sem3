import QtQuick 2.12
import QtQuick.Window 2.12
import StyleSettings 1.0
import ComponentsModule.Impl 1.0
import QtQuick.Controls 2.12
import ComponentsModule.Base 1.0
import QtGraphicalEffects 1.0
import QtQml 2.12

Window {
    id: root
    minimumWidth: 900
    minimumHeight: 600
    visible: true
    width: 900
    height: 600
    title: qsTr("APP")

    SettingsMenu{
        id: _popup
    }

    Page {
        id: _page

        anchors.fill: parent

        header: Rectangle {
            id: _header
            color: Style.backgroundColor
            opacity: Style.emphasisOpacity
            height: 60
            MenuButton{
                anchors.left: _header.left
                width: parent.height
                height: width
                area.onClicked: {
                    _popup.visible = true
                }
            }
        }

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
                id: _tasksLoader
                sourceComponent: _tasks
                FullTaskView {
                    id: _fullTask
                    visible: false
                }
            }
            Loader {
                id: _notesLoader
                sourceComponent: _notes
                FullNoteView {
                    id: _fullNote
                    visible: false
                }
            }

        }

        footer: Rectangle {
            id: _indicator
            color: Style.backgroundColor
            opacity: Style.emphasisOpacity
            height: 60

            AddButton {
                id: _addButton
                width: parent.height
                height: width
                anchors.left: parent.left

                visible: {
                    if (_list.currentItem.sourceComponent === _tasks && _fullTask.visible) return 0
                    else if (_list.currentItem.sourceComponent === _notes && _fullNote.visible) return 0
                    else return 1
                }

                property date basicTime: new Date()
                property date basicDate: new Date()
                area.onClicked: {
                    _list.currentItem.sourceComponent === _tasks
                        ? _list.currentItem.item.viewModel.addElement("", basicDate.toLocaleDateString(Qt.locale("en_EN"), "dd.MM.yyyy"),
                                                                        basicTime.toLocaleTimeString(Qt.locale(), "hh:mm"))
                        : _list.currentItem.item.viewModel.addElement("")
                }
            }

            PageIndicator{
                count: _list.count
                currentIndex: _list.currentIndex

                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter

                delegate: Rectangle {
                    implicitWidth: 15
                    implicitHeight: 15

                    radius: width / 2

                    color: Style.themeInvertedColor
                    opacity: index === _list.currentIndex ? Style.defaultOpacity : Style.disabledOpacity

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            _list.currentIndex = index
                        }
                    }
                }
            }
        }

        Component {
            id: _notes
            ProtoNoteView {


            }
        }
        Component {
            id: _tasks
            ProtoTasksView{}
        }

    }

}
