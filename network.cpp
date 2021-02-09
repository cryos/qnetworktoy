#include "network.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

Network::Network(QObject *p) : QObject(p)
{
    m_manager = new QNetworkAccessManager(this);
    connect(m_manager, &QNetworkAccessManager::finished,
            this, &Network::replyFinished);
}

Network::~Network()
{
    m_manager->deleteLater();
}

void Network::makeRequest(const QString &url)
{
    m_manager->get(QNetworkRequest(QUrl(url)));
}

template<typename T>
QString stringIt(const T *ptr, size_t length)
{
    QString res;
    for (size_t i = 0; i < length / sizeof(T); ++i) {
        res.append(QString::number(ptr[i])).append("\t");
        if ((i + 1) % 5 == 0)
            res.append("\n");
    }
    res.chop(1);
    return res;
}

void Network::replyFinished(QNetworkReply *r)
{
    auto data = r->readAll();
    qDebug() << "reply:" << data.size() << "->" << data;

    // Convert the bytes to a numeric type - lazy and hardwire for now.
    switch (m_type) {
        case 0: {
            auto ptr = reinterpret_cast<const char*>(data.constData());
            m_data = stringIt(ptr, data.size());
            break;
        } case 1: {
            auto ptr = reinterpret_cast<const short*>(data.constData());
            m_data = stringIt(ptr, data.size());
            break;
        } case 2: {
            auto ptr = reinterpret_cast<const int*>(data.constData());
            m_data = stringIt(ptr, data.size());
            break;
        } case 3: {
            auto ptr = reinterpret_cast<const float*>(data.constData());
            m_data = stringIt(ptr, data.size());
            break;
        } case 4: {
            auto ptr = reinterpret_cast<const double*>(data.constData());
            m_data = stringIt(ptr, data.size());
            break;
        }
        default:
            // float default
            auto ptr = reinterpret_cast<const float*>(data.constData());
            m_data = QString(data);
    }

    emit reply(m_data);
}
