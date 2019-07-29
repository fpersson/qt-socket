#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H

#include <QObject>
#include <QtWebSockets/QWebSocket>

class WebSocketClient : public QObject
{
    Q_OBJECT
public:
    explicit WebSocketClient(const QUrl &url, QObject *parent = nullptr);

signals:
    void closed();

public slots:
    void onGotData(QString data);
    void onConnected();
    void onClose();

private:
    QWebSocket *m_webSocket = nullptr;
    QUrl m_url;
};

#endif // WEBSOCKETCLIENT_H
