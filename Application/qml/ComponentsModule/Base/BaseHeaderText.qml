import QtQuick 2.0

BaseProtoText {
    onContentHeightChanged: {
        if (height > parent.height){
            while (height > parent.height){
                font.pixelSize--
            }
        }
//        if (height < parent.height/3*2){
//            while (height < parent.height-5)
//                font.pixelSize++
//        }
    }
}
