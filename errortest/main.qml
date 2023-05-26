import QtQuick
import QtQuick.Controls

ApplicationWindow
{
    id: mainWindow
    visible: true
    title: qsTr("Loader test app")
    width: 300
    height: 300
    color: "white"

    Loader {
        id: contentLoader
        anchors.fill: parent

        source: main.main_content_qml
        onStatusChanged: {
            if (contentLoader.status == Loader.Null) {
                console.log("Loader is null... inactive or no QML source set")
                mainWindow.close()
            }
            else if (contentLoader.status == Loader.Ready) console.log("Loader is ready")
            else if (contentLoader.status == Loader.Loading) console.log("Loader is loading")
            else if (contentLoader.status == Loader.Error) console.log("Loader error occurred")
            else console.log("Unknown loader status")
        }
    }
}
