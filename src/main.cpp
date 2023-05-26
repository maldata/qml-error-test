#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer>
#include <QQmlContext>

#include "maincontroller.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    auto main_ctrl = MainController();

    QQmlApplicationEngine engine;
    auto qml_context = engine.rootContext();
    qml_context->setContextProperty(QString("main"), &main_ctrl);

    const QUrl url(QStringLiteral("qrc:/errortest/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QTimer::singleShot(0, &main_ctrl, &MainController::startup);
    QObject::connect(&app, &QGuiApplication::aboutToQuit, &main_ctrl, &MainController::shutdown);

    return app.exec();
}
