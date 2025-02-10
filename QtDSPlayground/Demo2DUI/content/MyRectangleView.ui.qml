import QtQuick 6.5
import QtQuick.Controls 6.5
import Demo2DUI

Rectangle {
    id: rectangleView
    width: 640
    height: 380
    color: "#c5c4c4"
    radius: 15
    anchors.verticalCenter: parent.verticalCenter
    anchors.left: parent.left
    state: "默认"
    anchors.leftMargin: 50

    Image {
        id: image
        anchors.fill: parent
        source: "qrc:/qtquickplugin/images/template_image.png"
        anchors.rightMargin: 20
        anchors.leftMargin: 20
        anchors.bottomMargin: 20
        anchors.topMargin: 20
        fillMode: Image.PreserveAspectFit

        Image {
            id: imagePerson
            x: 167
            y: 108
            width: 100
            height: 100
            source: "qrc:/qtquickplugin/images/template_image.png"
            rotation: sliderRotation.value
            scale: sliderScale.value
            fillMode: Image.PreserveAspectFit

            Image {
                id: imageCatFace
                x: 24
                y: 8
                width: 100
                height: 100
                visible: radioButtonCat.checked
                source: "images/cat.png"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: imageAlienFace
                x: 14
                y: 21
                width: 100
                height: 100
                visible: radioButtonAlien.checked
                source: "images/alien.png"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: imageGlasses
                width: 100
                height: 100
                visible: switchGlasses.checked
                source: "images/sunglasses.png"
                fillMode: Image.PreserveAspectFit
            }
        }

        Slider {
            id: sliderScale
            x: 8
            y: 0
            to: 2
            value: 1
        }

        Slider {
            id: sliderRotation
            x: 8
            y: 46
            to: 360
            from: -360
            value: 0
        }
    }
    states: [
        State {
            name: "海洋"
            when: roundButtonSea.checked

            PropertyChanges {
                target: image
                source: "images/lagoon.jpg"
            }

            PropertyChanges {
                target: imagePerson
                x: 133
                y: 60
                width: 145
                height: 183
                source: "images/diver.png"
            }

            PropertyChanges {
                target: imageAlienFace
                x: 48
                y: 19
                width: 34
                height: 25
            }

            PropertyChanges {
                target: imageCatFace
                x: 47
                y: 14
                width: 37
                height: 31
            }

            PropertyChanges {
                target: imageGlasses
                x: 48
                y: 8
                width: 34
                height: 37
            }
        },
        State {
            name: "太空"
            when: roundButtonSpace.checked

            PropertyChanges {
                target: image
                source: "images/planet.png"
            }

            PropertyChanges {
                target: imagePerson
                x: 182
                y: 148
                width: 142
                height: 167
                source: "images/spacesuit.png"
            }

            PropertyChanges {
                target: imageAlienFace
                x: 44
                y: 6
                width: 43
                height: 39
            }

            PropertyChanges {
                target: imageCatFace
                x: 35
                y: 2
                width: 62
                height: 45
            }

            PropertyChanges {
                target: imageGlasses
                x: 42
                y: 0
                width: 47
                height: 40
            }
        },
        State {
            name: "默认"
            when: !(roundButtonSea.checked && roundButtonSpace.checked)

            PropertyChanges {
                target: image
                visible: false
            }
        }
    ]
}
