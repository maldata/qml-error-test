import QtQuick
import QtQuick.Layouts

ColumnLayout {
    // Remove this property - runs for 93 iterations (instead of 91)
    property var wrapper: main.get_wrapper_object_by_name("OTHER")

    Rectangle {
        color: "green"
        Layout.fillWidth: true
        Layout.fillHeight: true
    }
}
