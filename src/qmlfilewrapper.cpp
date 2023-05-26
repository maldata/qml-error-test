#include "qmlfilewrapper.h"

QmlFileWrapper::QmlFileWrapper(QString qml_path, QObject *parent)
    : QObject{parent},
      m_qmlPath(qml_path)
{

}

const QString &QmlFileWrapper::qmlPath() const
{
    return m_qmlPath;
}

void QmlFileWrapper::setQmlPath(const QString &newQmlPath)
{
    if (m_qmlPath == newQmlPath)
        return;
    m_qmlPath = newQmlPath;
    emit qmlPathChanged();
}
