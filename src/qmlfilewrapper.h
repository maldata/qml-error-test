#ifndef QMLFILEWRAPPER_H
#define QMLFILEWRAPPER_H

#include <QObject>

class QmlFileWrapper : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString qmlPath READ qmlPath WRITE setQmlPath NOTIFY qmlPathChanged)

public:
    explicit QmlFileWrapper(QString qml_path, QObject *parent = nullptr);

    const QString &qmlPath() const;
    void setQmlPath(const QString &newQmlPath);

signals:
    void qmlPathChanged();

private:
    QString m_qmlPath;
};

#endif // QMLFILEWRAPPER_H
