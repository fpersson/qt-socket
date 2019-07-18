#include "client.h"

Client::Client(QObject *parent) : QObject(parent), m_Socket(new QTcpSocket(this)){
    qDebug() << "Connecting to....";
    connect(m_Socket, &QIODevice::readyRead, this, &Client::gotData);
    connect(m_Socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            this, &Client::gotError);
    connect(m_Socket, &QTcpSocket::connected, this, &Client::gotConnection);

    //m_Socket->connectToHost(QHostAddress("192.168.43.48"), 1234);
    //m_Socket->connectToHost("localhost", 1234);
    m_Socket->connectToHost(QHostAddress("10.128.40.88"), 1234);
}

void Client::gotError(QAbstractSocket::SocketError socketError){
    qDebug() << "Got a error";
}

void Client::gotData(){
    qDebug() << "Got data";
}

void Client::gotConnection(){
    qDebug() << "Got connection";
    m_Socket->write("hello, world");
}
