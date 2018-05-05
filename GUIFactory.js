.import QtQuick 2.0 as QtQuick

var settingsComponent;
var settings;

var translationComponent;
var translation;

function createSettings(sender) {
    if (!settings) {
        createSettingsWindow(sender);
    } else {
        settings.show();
    }
}

function createTranslation(sender) {
    if (!translation) {
        createTranslationWindow(sender);
    } else {
        translation.show();
    }
}

function finishSettingsWindowCreation(sender) {
    if (settingsComponent.status === QtQuick.Component.Ready) {
        settings = settingsComponent.createObject(sender);
        if (!settings) {
            // Error Handling
            console.log("Error creating settings window");
        }
    } else if (settingsComponent.status === QtQuick.Component.Error) {
        // Error Handling
        console.log("Error loading component:",
                    settingsComponent.errorString());
    }
}

function createSettingsWindow(sender) {
    settingsComponent = Qt.createComponent("qrc:/qml/Settings.qml");
    if (settingsComponent.status === QtQuick.Component.Ready) {
        finishSettingsWindowCreation(sender);
    } else {
        settingsComponent.statusChanged.connect(function() {
            finishSettingsWindowCreation(sender);
        });
    }
}

function finishTranslationWindowCreation(sender) {
    if (translationComponent.status === QtQuick.Component.Ready) {
        translation = translationComponent.createObject(sender);
        if (!translation) {
            // Error Handling
            console.log("Error creating translation window");
        }
    } else if (translationComponent.status === QtQuick.Component.Error) {
        // Error Handling
        console.log("Error loading component:",
                    translationComponent.errorString());
    }
}

function createTranslationWindow(sender) {
    translationComponent = Qt.createComponent("qrc:/qml/Screenshot.qml");
    if (translationComponent.status === QtQuick.Component.Ready) {
        finishTranslationWindowCreation(sender);
    } else {
        translationComponent.statusChanged.connect(function() {
            finishTranslationWindowCreation(sender);
        });
    }
}
