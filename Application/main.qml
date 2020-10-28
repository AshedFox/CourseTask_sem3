import QtQuick 2.12
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
        ProtoView {
            id: _notes
            anchors.left: _overlay.right
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.leftMargin: 2

            ScrollBar.vertical: ScrollBar{}
        }
        CatalogueOverlay{
            id: _overlay
            AddButton {
                width: 50
                height: 50
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                area.onClicked: _notes.viewModel.addElement("")
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
