import QtQuick
import QtQuick.Layouts
import QtQuick.Shapes

RowLayout {
    // Remove this property - runs indefinitely?
    property var wrapper: main.get_wrapper_object_by_name("HOME")

    ColumnLayout {
        Layout.fillWidth: true
        Layout.fillHeight: true

        Rectangle {
            color: "lightBlue"
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Rectangle {
            color: "gray"

            Layout.fillHeight: true
            Layout.fillWidth: true

            // Remove this shape - runs for 748 iterations (instead of 91)
            Shape {
                ShapePath {
                    strokeWidth: 1
                    strokeColor: "black"
                    fillColor: "lightGray"
                    fillRule: ShapePath.WindingFill
                    
                    PathPolyline {
                        path: [
                            Qt.point(0, 0),
                            Qt.point(0, 1),
                            Qt.point(1, 1),
                            Qt.point(1, 2),
                            Qt.point(2, 2),
                            Qt.point(2, 3),
                            Qt.point(3, 3),
                            Qt.point(3, 4),
                            Qt.point(4, 4),
                            Qt.point(4, 5),
                            Qt.point(5, 5),
                            Qt.point(5, 6),
                            Qt.point(6, 6),
                            Qt.point(6, 7),
                            Qt.point(7, 7),
                            Qt.point(7, 6),
                            Qt.point(8, 6),
                            Qt.point(8, 5),
                            Qt.point(9, 5),
                            Qt.point(9, 4),
                            Qt.point(10, 4),
                            Qt.point(10, 3),
                            Qt.point(11, 3),
                            Qt.point(11, 2),
                            Qt.point(12, 2),
                            Qt.point(12, 1),
                        ]
                    }
                }

                ShapePath {
                    strokeWidth: 2
                    strokeColor: "black"
                    fillColor: "dimgray"
                    fillRule: ShapePath.WindingFill

                    PathPolyline {
                        path: [
                            Qt.point(5, 5),
                            Qt.point(6, 5),
                            Qt.point(6, 6),
                            Qt.point(5, 6),
                            Qt.point(5, 5)
                        ]
                    }
                }
            }
        }
    }
}
