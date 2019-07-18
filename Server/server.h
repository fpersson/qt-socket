#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

signals:

public slots:
    void onNewConnection();
    void readData();

private:
    QTcpServer *mTcpServer;
    QTcpSocket *mTcpSocket;
};

#endif // SERVER_H
