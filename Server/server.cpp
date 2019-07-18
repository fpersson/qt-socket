#include "server.h"
#include <QDebug>
#include <QAbstractSocket>

Server::Server(QObject *parent) : QObject(parent), mTcpServer(new QTcpServer(this)){

    connect(mTcpServer, &QTcpServer::newConnection, this, &Server::onNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 1234)){
        qDebug() << "Server listen [Failed]";
    }else{
        qDebug() << "Server is listening to port 1234";
    }

}

void Server::onNewConnection(){
    mTcpSocket = mTcpServer->nextPendingConnection();
    connect(mTcpSocket, &QTcpSocket::readyRead, this, &Server::readData);
    qDebug() << "got connection";
}

void Server::readData(){
    QByteArray data;
    data = mTcpSocket->readAll();
    qDebug() << "data size: " << data.size();
}
