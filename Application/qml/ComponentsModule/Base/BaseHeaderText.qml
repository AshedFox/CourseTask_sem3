import QtQuick 2.0
import StyleSettings 1.0

BaseProtoText {
    id: root
     function fillText() {
        metrics.text = text
        font.pixelSize = Style.textSize
        metrics.font.pixelSize = font.pixelSize
        if (metrics.width > width - font.pixelSize && font.pixelSize > 20) {
            while (metrics.width > width - font.pixelSize && font.pixelSize > 20) {
                metrics.font.pixelSize = --font.pixelSize
            }
        }
        if (metrics.width < width - 4 * font.pixelSize && font.pixelSize < Style.textSize) {
            while (metrics.width < width - 4*font.pixelSize && font.pixelSize < Style.textSize) {
                metrics.font.pixelSize = ++font.pixelSize
            }
        }
    }

    function delay(delayTime, cb) {
        function Timer() {
            return Qt.createQmlObject("import QtQuick 2.0; Timer {}", root);
        }

        var timer = new Timer();
        timer.interval = 1;
        timer.repeat = true;
        timer.triggered.connect(function release () {
            timer.triggered.disconnect(cb);
            timer.triggered.disconnect(release);
        });

        timer.start();
    }

    onTextChanged: {
        if (!parent.width)
            delay(20, fillText)
        else
            fillText()
    }
    onWidthChanged: {
        if (!parent.width)
            delay(20, fillText)
        else
            fillText()
    }
}
