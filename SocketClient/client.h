#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

signals:

public slots:
    void gotData();
    void gotError(QAbstractSocket::SocketError socketError);
    void gotConnection();
private:
    QTcpSocket *m_Socket = nullptr;
};

#endif // CLIENT_H
