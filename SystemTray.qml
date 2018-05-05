import Qt.labs.platform 1.0
import "GUIFactory.js" as GUIFactory

SystemTrayIcon {
    visible: true
    iconSource: "qrc:/icons/ic_tray.png"
    menu: Menu {
        MenuItem {
            text: qsTr("Translate")
            onTriggered: {
                // Don't create a new object if it exists, just show
                GUIFactory.createTranslation(this);
            }
        }
        MenuSeparator {}
        MenuItem {
            text: qsTr("Settings")
            onTriggered: {
                // Don't create a new object if it exists, just show
                GUIFactory.createSettings(this);
            }
        }
        MenuItem {
            text: qsTr("Quit")
            onTriggered: Qt.quit() // Just hide an existing
        }
    }
}
