from PySide6.QtCore import QObject, Property


class QmlFileWrapper(QObject):
    def __init__(self, qml_path) -> None:
        super().__init__(None)
        self._qml_path = qml_path

    @Property(str, constant=True)
    def qml_path(self):
        return self._qml_path
