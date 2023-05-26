#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QHash>

#include "qmlfilewrapper.h"

class MainController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString main_content_qml READ mainContentQml NOTIFY mainContentQmlChanged)

public:
    explicit MainController(QObject *parent = nullptr);

    const QString &mainContentQml() const;

signals:
    void mainContentQmlChanged();

public slots:
    void startup();
    void shutdown();
    QmlFileWrapper* get_wrapper_object_by_name(QString next_id);

private slots:
    void toggleScreen();
    void onDestroy(QObject* obj);

private:
    QString m_mainContentQml = "Home.qml";
    QString m_activeId = "HOME";
    int m_counter = 0;
    QTimer m_timer;
    QHash<QString, QmlFileWrapper*> m_qmlWrappers;
    QmlFileWrapper* m_activeWrapper;

    void goToQmlByName(QString next_id);
};

#endif // MAINCONTROLLER_H
