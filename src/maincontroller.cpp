#include "maincontroller.h"

MainController::MainController(QObject *parent)
    : QObject{parent},
      m_mainContentQml("Home.qml"),
      m_activeId("HOME"),
      m_counter(0)
{
    m_timer.setInterval(10);
    m_timer.setSingleShot(false);

    // Using these two lines, it runs indefinitely
//    auto h = new QmlFileWrapper("Home.qml", this);
//    auto o = new QmlFileWrapper("Other.qml", this);

    // Using these two lines, it ends after 155 iterations
    auto h = new QmlFileWrapper("Home.qml");
    auto o = new QmlFileWrapper("Other.qml");

    QObject::connect(h, &QObject::destroyed, this, &MainController::onDestroy);
    QObject::connect(o, &QObject::destroyed, this, &MainController::onDestroy);
    m_qmlWrappers.insert(QString("HOME"), h);
    m_qmlWrappers.insert(QString("OTHER"), o);

    m_activeWrapper = get_wrapper_object_by_name(m_activeId);
}

void MainController::onDestroy(QObject* obj)
{
    qDebug("Trashing object at %p", obj);
}

const QString &MainController::mainContentQml() const
{
    return m_activeWrapper->qmlPath();
}

void MainController::startup()
{
    QObject::connect(&m_timer, &QTimer::timeout, this, &MainController::toggleScreen);
    m_timer.start();
}

void MainController::shutdown()
{
    QObject::disconnect(&m_timer, &QTimer::timeout, this, &MainController::toggleScreen);
    m_timer.stop();
    qDebug("Stopping after %d iterations.", m_counter);
}

QmlFileWrapper* MainController::get_wrapper_object_by_name(QString next_id)
{
    auto i = m_qmlWrappers.find(next_id);
    return i.value();
}

void MainController::goToQmlByName(QString next_id)
{
    m_activeWrapper = get_wrapper_object_by_name(next_id);
    emit mainContentQmlChanged();
}

void MainController::toggleScreen()
{
    m_counter++;
    if (m_activeId == QString("HOME")) {
        m_activeId = QString("OTHER");
    }
    else {
        m_activeId = QString("HOME");
    }
    goToQmlByName(m_activeId);
}
