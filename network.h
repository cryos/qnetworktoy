#pragma once

#include <QObject>

#include <QString>

class QNetworkAccessManager;
class QNetworkReply;

class Network : public QObject
{
    Q_OBJECT

public:
    Network(QObject *p = nullptr);
    ~Network() override;

    void setType(int type) { m_type = type; }

    void makeRequest(const QString &url);

    QString data() { return m_data; }

public slots:
    void replyFinished(QNetworkReply *r);

signals:
    void reply(QString data);

private:
    QNetworkAccessManager *m_manager;
    QString m_data;
    int m_type = 3;
};
