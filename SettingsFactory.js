.import QtQuick 2.0 as QtQuick

var component;
var settings;

function create(sender) {
    if (!settings) {
        createSettings(sender);
    } else {
        settings.show();
    }
}

function finishSettingsCreation(sender) {
    if (component.status === QtQuick.Component.Ready) {
        settings = component.createObject(sender);
        if (!settings) {
            // Error Handling
            console.log("Error creating settings");
        }
    } else if (component.status === QtQuick.Component.Error) {
        // Error Handling
        console.log("Error loading component:", component.errorString());
    }
}

function createSettings(sender) {
    component = Qt.createComponent("qrc:/qml/Settings.qml");
    if (component.status === QtQuick.Component.Ready) {
        finishSettingsCreation(sender);
    } else {
        component.statusChanged.connect(function() {
            finishSettingsCreation(sender);
        });
    }
}
