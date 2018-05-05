import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Window 2.3

ApplicationWindow {
    id : translationWindow
    width : 1024
    height : 768
    color: "transparent"
    //flags: "Popup"
    visibility: "FullScreen"
    visible: true;
    signal capture(string path)

    MouseArea {
        anchors.fill: parent
        onClicked: translationWindow.capture("/home/ghostman/saveTest.jpg")
    }
}

