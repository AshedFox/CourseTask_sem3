import QtQuick 2.0
import ComponentsModule.Base 1.0
import Tasks 1.0

BaseProtoView {
    id: root
    property alias viewModel: _tasksModel

    model: TasksModel {
        id: _tasksModel
    }
    delegate: ProtoTaskDelegate {
        id: _tasks
        width: root.width
        height: 80
    }


}
