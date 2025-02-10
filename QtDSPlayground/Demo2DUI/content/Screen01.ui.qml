

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.5
import QtQuick.Controls 6.5
import Demo2DUI

Rectangle {
    id: rectangleBackground
    width: 1200
    height: 600
    color: "#ffffff"

    Item {
        id: itemRoundButtons
        x: 919
        y: 50
        width: 251
        height: 163
        anchors.right: parent.right
        anchors.rightMargin: 30

        RoundButton {
            id: roundButtonSea
            width: 198
            height: 50
            text: "海洋"
            anchors.top: parent.top
            checkable: true
            autoExclusive: true
            checked: false
            anchors.topMargin: 21
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 15
            font.bold: true
        }

        RoundButton {
            id: roundButtonSpace
            y: 80
            width: 198
            height: 50
            text: "太空"
            anchors.bottom: parent.bottom
            checkable: true
            autoExclusive: true
            checked: false
            anchors.bottomMargin: 21
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
            font.pointSize: 15
        }
    }

    MyRectangleView {
        id: myRectangleView
        x: 352
        y: 167
        width: 844
        height: 526
        anchors.verticalCenterOffset: 0
        anchors.leftMargin: 36
    }

    Item {
        id: itemRadioButtons
        x: 919
        y: 242
        width: 251
        height: 176
        visible: true

        RadioButton {
            id: radioButtonCat
            text: qsTr("猫脸")
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: 127
            anchors.topMargin: 26
        }

        RadioButton {
            id: radioButtonAlien
            y: 112
            text: qsTr("外星人脸")
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.leftMargin: 127
            anchors.bottomMargin: 24
        }

        Image {
            id: image
            width: 75
            height: 72
            anchors.left: parent.left
            anchors.top: parent.top
            source: "images/cat.png"
            anchors.leftMargin: 10
            anchors.topMargin: 10
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image1
            y: 107
            width: 75
            height: 68
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            source: "images/alien.png"
            anchors.leftMargin: 10
            anchors.bottomMargin: 10
            fillMode: Image.PreserveAspectFit
        }
    }

    Item {
        id: itemSwitch
        x: 919
        y: 470
        width: 251
        height: 80

        Switch {
            id: switchGlasses
            x: 127
            text: qsTr("眼镜")
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 26
        }

        Image {
            id: image2
            width: 77
            height: 70
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            source: "images/sunglasses.png"
            anchors.leftMargin: 15
            fillMode: Image.PreserveAspectFit
        }
    }

    states: [
        State {
            name: "clicked"
            when: button.checked
        }
    ]
}
