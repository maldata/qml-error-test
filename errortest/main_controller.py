from PySide6.QtCore import QObject, Property, Slot, Signal, QTimer
from typing import Optional

from .qml_file_wrapper import QmlFileWrapper


class MainController(QObject):
    main_content_qml_changed = Signal()

    def __init__(self, parent=None):
        super().__init__(parent)
        self._app = parent
        self._qml_wrappers = {
            "HOME": QmlFileWrapper('Home.qml'),
            "OTHER": QmlFileWrapper('Other.qml')
        }
        self._active_id = "HOME"
        self._active_wrapper: QmlFileWrapper = self._qml_wrappers[self._active_id]
        self._counter = 0
        self._timer = QTimer()
        self._timer.setInterval(10)
        self._timer.setSingleShot(False)
        self._timer.timeout.connect(self._toggle_screen)

    @Property(str, notify=main_content_qml_changed)
    def main_content_qml(self) -> str:
        return self._active_wrapper.qml_path

    def startup(self):
        self._timer.start()

    def shutdown(self):
        print(f"Stopping after {self._counter} iterations.")

    @Slot(str, result=QmlFileWrapper)
    def get_wrapper_object_by_name(self, screen_name: str) -> Optional[QmlFileWrapper]:
        return self._qml_wrappers[screen_name.upper()]

    @Slot(str)  # QML will only send a string
    def go_to_qml_by_name(self, next_id: str) -> None:
        self._active_wrapper = self.get_wrapper_object_by_name(next_id)
        self.main_content_qml_changed.emit()

    def _toggle_screen(self):
        self._counter = self._counter + 1
        if self._active_id == "HOME":
            self._active_id = "OTHER"
        else:
            self._active_id = "HOME"

        self.go_to_qml_by_name(self._active_id)
