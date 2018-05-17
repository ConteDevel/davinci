import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Window 2.3
import daVinci 1.0

Window {
    id : translationWindow
    width : 1024
    height : 768
    color: "transparent"
    visibility: "FullScreen"
    visible: true;

    GrabWindow {
        id: grabWindow
        window: translationWindow
    }

    MouseArea {
        anchors.fill: parent
        onClicked: grabWindow.capture("/home/ghostman/saveTest.jpg")
    }
}

