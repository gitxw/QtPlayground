import QtQuick

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  Text {
    anchors.centerIn: parent
    text: qsTr("你好，世界！")
    font.pixelSize: 100
  }
}
