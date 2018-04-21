import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: window
    visible: true
    width: 320
    height: 480
    title: qsTr("daVinci")
    onClosing: {
        window.hide();
    }

    ToolBar {
        id: toolBar
        position: ToolBar.Footer
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

        Text {
            id: text1
            text: qsTr("ConteDevel, 2018")
            verticalAlignment: Text.AlignVCenter
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }
    }

    ScrollView {
        id: scrollView
        spacing: 0
        contentWidth: 267
        rightPadding: 24
        leftPadding: 24
        bottomPadding: 16
        topPadding: 16
        clip: true
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.bottom: toolBar.top
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottomMargin: 0

        GridLayout {
            id: gridLayout
            x: 0
            width: 0
            height: 100
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.right: parent.right
            anchors.left: parent.left
            flow: GridLayout.LeftToRight
            columns: 2
            anchors.rightMargin: 0
            anchors.leftMargin: 0

            Label {
                id: label
                text: qsTr("Language")
                Layout.columnSpan: 2
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            }

            ComboBox {
                id: cmbLang
                topPadding: 0
                Layout.columnSpan: 2
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            }

            Item {
                id: item1
                width: 200
                height: 8
                Layout.minimumHeight: 8
                Layout.maximumHeight: 8
                Layout.fillHeight: false
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                Layout.columnSpan: 2
                Layout.fillWidth: true
            }

            Label {
                id: label1
                text: qsTr("Hot keys")
                Layout.columnSpan: 2
                Layout.fillWidth: false
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            }

            ComboBox {
                id: cmbHot1
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            }

            ComboBox {
                id: cmbHot2
                Layout.columnSpan: 1
            }

            Item {
                id: item2
                width: 200
                height: 8
                Layout.fillHeight: false
                Layout.fillWidth: true
                Layout.minimumHeight: 8
                Layout.maximumHeight: 8
                Layout.columnSpan: 2
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            }

            CheckBox {
                id: cbAutorun
                text: qsTr("Autorun")
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                Layout.fillWidth: true
                Layout.columnSpan: 2
            }


        }
    }

}
