import QtQml 2.0
import QtQuick 2.14
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import QtQuick.Window 2.11

import ComponentsModule.Base 1.0
import StyleSettings 1.0

BaseDialog {
    id: _alarmDialog

    property date date
    property string dateString: ""

    property alias minutesTumbler: minutesTumbler
    property alias hoursTumbler: hoursTumbler
    property alias dayTumbler: dayTumbler
    property alias monthTumbler: monthTumbler
    property alias yearTumbler: yearTumbler

    function formatNumber(number) {
        return number < 10 && number >= 0 ? "0" + number : number.toString()
    }  

    onAccepted: {
        dateString = formatNumber(hoursTumbler.currentIndex) + " " + formatNumber(minutesTumbler.currentIndex) + " " +
                     formatNumber(dayTumbler.currentIndex + 1) + " " + formatNumber(monthTumbler.currentIndex + 1) + " " +
                     formatNumber(yearTumbler.years[yearTumbler.currentIndex])

        date = Date.fromLocaleString(Qt.locale(), dateString, "hh mm dd MM yyyy")
    }


    contentItem: RowLayout {
        RowLayout {
            id: rowTumbler

            Tumbler {
                id: hoursTumbler
                Layout.fillWidth: true
                model: 24
                delegate: TumblerDelegate {
                    text: formatNumber(modelData)
                }
            }
            Tumbler {
                id: minutesTumbler
                Layout.fillWidth: true
                model: 60
                delegate: TumblerDelegate {

                    text: formatNumber(modelData)
                }
            }
        }

        RowLayout {
            id: datePicker

            Layout.leftMargin: 40
            Layout.preferredWidth: Style.textSize*4
            //spacing: 40


            property alias dayTumbler: dayTumbler
            property alias monthTumbler: monthTumbler
            property alias yearTumbler: yearTumbler

            readonly property var days: [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

            Tumbler {
                id: dayTumbler
                Layout.fillWidth: true

                function updateModel() {
                    var previousIndex = dayTumbler.currentIndex
                    var array = []
                    var newDays = datePicker.days[monthTumbler.currentIndex]
                    for (var i = 1; i <= newDays; ++i)
                        array.push(i)
                    dayTumbler.model = array
                    dayTumbler.currentIndex = Math.min(newDays - 1, previousIndex)
                }

                Component.onCompleted: updateModel()

                delegate: TumblerDelegate {
                    text: formatNumber(modelData)
                }
            }
            Tumbler {
                id: monthTumbler
                Layout.fillWidth: true
                onCurrentIndexChanged: if (dayTumbler.currentIndex > 27) dayTumbler.updateModel()

                model: 12
                delegate: TumblerDelegate {
                    text: locale.standaloneMonthName(modelData, Locale.ShortFormat)
                }
            }
            Tumbler {
                id: yearTumbler

                Layout.fillWidth: true

                readonly property var years: (function() {
                    var currentYear = new Date().getFullYear()
                    return [-1,0, 1, 2,3,4,5,6,7].map(function(value) { return value + currentYear; })
                })()

                model: years
                delegate: TumblerDelegate {
                    text: formatNumber(modelData)
                }
            }
        }
    }
}
