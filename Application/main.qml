import QtQuick 2.9
import QtQuick.Window 2.12
import StyleSettings 1.0
import ComponentsModule.Impl 1.0
import QtQuick.Controls 2.12
import ComponentsModule.Base 1.0
import QtGraphicalEffects 1.0
import Notes 1.0

Window {
    id: root
    minimumWidth: 600
    minimumHeight: 600
    visible: true
    width: 600
    height: 600
    title: qsTr("APP")


    Page {
        id: _page

        anchors.fill: parent

        background: Rectangle {
            id: _background
            color: Style.backgroundColor
            opacity: Style.emphasisOpacity
        }
//        ProtoNoteView {
//            id: _notes
//            anchors.left: _overlay.right
//            anchors.right: parent.right
//            anchors.top: parent.top
//            anchors.bottom: parent.bottom
//            anchors.leftMargin: 2

//            ScrollBar.vertical: ScrollBar{}
//        }
        ProtoTasksView{
            id: _tasks
            anchors.left: _overlay.right
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.leftMargin: 2

            ScrollBar.vertical: ScrollBar{}
        }

//        NotesView {
//            id: _notes2
//            anchors.left: _overlay.right
//            anchors.right: parent.right
//            anchors.top: parent.top
//            anchors.bottom: parent.bottom
//            anchors.leftMargin: 2
//           // visible: false
//        }

        CatalogueOverlay{
            id: _overlay
            AddButton {
                id: _addButton
                width: 50
                height: 50
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                property date a: new Date()
                property date b: new Date()
                area.onClicked: {

                   _tasks.viewModel.addElement("", a.toLocaleDateString(), b.toLocaleTimeString())
                }
            }
        }        
    }

    ColorOverlay {
        anchors.fill: parent
        color: Style.backgroundColor
        opacity: Style.minimalOpacity
        antialiasing: true
    }
}
