/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 6.5
import QtQuick.Controls 6.5
import QtQuick3D 6.5
import Demo3DUI
import Quick3DAssets.Orbiter_Space_Shuttle_OV_103_Discovery_150k_4096 1.0
import QtQuick.Timeline 1.0

Rectangle {
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    View3D {
        id: view3D
        anchors.fill: parent

        environment: sceneEnvironment

        SceneEnvironment {
            id: sceneEnvironment
            antialiasingMode: SceneEnvironment.MSAA
            antialiasingQuality: SceneEnvironment.High
        }

        Node {
            id: scene
            DirectionalLight {
                id: directionalLight
                x: -212.189
                y: 65.135
                shadowMapFar: 4790
                shadowBias: 0.013
                shadowMapQuality: Light.ShadowMapQualityHigh
                shadowFilter: 23
                shadowFactor: 31
                castsShadow: true
                brightness: 4.64
                eulerRotation.z: 31.56753
                eulerRotation.y: -76.14406
                eulerRotation.x: -71.00003
                z: -33.27884
            }

            PerspectiveCamera {
                id: sceneCamera
                x: -55.8
                y: 142.943
                eulerRotation.z: 0.44404
                eulerRotation.y: -9.33681
                eulerRotation.x: -12.98782
                z: 660.41418
            }

            Orbiter_Space_Shuttle_OV_103_Discovery_150k_4096 {
                id: orbiter_Space_Shuttle_OV_103_Discovery_150k_4096
                x: 36.252
                y: -7.11
                eulerRotation.y: slider.value
                z: -8.49435
            }

            Model {
                id: cube
                x: 48.59
                y: -123.275
                source: "#Cube"
                scale.z: 6.90974
                scale.y: 1.175
                scale.x: 11.23117
                z: 33.42127
                materials: defaultMaterial
            }
        }

        Slider {
            id: slider
            opacity: 0
            anchors.fill: parent
            to: 180
            from: -180
            value: 0.5
        }
    }

    Item {
        id: __materialLibrary__
        DefaultMaterial {
            id: defaultMaterial
            objectName: "Default Material"
            diffuseColor: "#4aee45"
        }
    }

    Timeline {
        id: timeline
        animations: [
            TimelineAnimation {
                id: timelineAnimation
                duration: 1000
                loops: 1
                running: true
                to: 1000
                from: 0
            }
        ]
        endFrame: 1000
        startFrame: 0
        enabled: true

        KeyframeGroup {
            target: sceneCamera
            property: "z"
            Keyframe {
                value: 507.20825
                frame: 0
            }

            Keyframe {
                value: 643.09656
                frame: 721
            }
        }

        KeyframeGroup {
            target: sceneCamera
            property: "x"
            Keyframe {
                value: -55.80027
                frame: 0
            }

            Keyframe {
                value: -55.80029
                frame: 721
            }
        }

        KeyframeGroup {
            target: sceneCamera
            property: "y"
            Keyframe {
                value: 142.94305
                frame: 721
            }
        }
    }
}
