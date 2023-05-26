import sys

from pathlib import Path
from PySide6.QtCore import QTimer, QUrl
from PySide6.QtGui import QGuiApplication
from PySide6.QtQml import QQmlApplicationEngine

from .main_controller import MainController


def main():
    app = QGuiApplication(sys.argv)
    main_controller = MainController(parent=app)

    qml_app_engine = QQmlApplicationEngine()
    qml_context = qml_app_engine.rootContext()
    qml_context.setContextProperty("main", main_controller)
    this_file_path = Path(__file__)
    main_qml_path = this_file_path.parent / 'main.qml'
    qml_app_engine.load(QUrl.fromLocalFile(str(main_qml_path)))
    if len(qml_app_engine.rootObjects()) == 0:
        print('Failed to start the UI.')
        sys.exit(1)

    QTimer.singleShot(0, main_controller.startup)
    app.aboutToQuit.connect(main_controller.shutdown)

    sys.exit(app.exec())
