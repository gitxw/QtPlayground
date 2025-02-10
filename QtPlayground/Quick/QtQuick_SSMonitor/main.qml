import QtQuick
import QtQuick.Controls

ApplicationWindow {
  visible: true
  width: 960
  height: 480
  title: "Casio Style Digital Clock"

  // 背景颜色
  Rectangle {
    anchors.fill: parent
    color: "#bec8be"
  }

  // 时间显示
  Text {
    id: timeText
    anchors.centerIn: parent
    color: "black"
    font.pixelSize: 200
    font.bold: true
    font.family: "digital-7 Mono"
    text: "00:00:00"
  }

  // 日期显示
  Text {
    id: dateText
    anchors {
      horizontalCenter: parent.horizontalCenter
      top: timeText.bottom
      topMargin: 20
    }
    color: "black"
    font.pixelSize: 100
    font.bold: true
    font.family: "digital-7 Mono"
    text: "YYYY-MM-DD"
  }

  // 定时器，每秒更新一次时间
  Timer {
    interval: 1000
    running: true
    repeat: true
    onTriggered: {
      var date = new Date()
      var hours = date.getHours()
      var minutes = date.getMinutes()
      var seconds = date.getSeconds()
      var year = date.getFullYear()
      var month = date.getMonth() + 1
      var day = date.getDate()

      // 格式化时间
      timeText.text = Qt.formatTime(date, "hh:mm:ss")
      // 格式化日期
      dateText.text = Qt.formatDate(date, "yyyy-MM-dd")
    }
  }
}
