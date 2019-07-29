#include "websocketclient.h"

WebSocketClient::WebSocketClient(const QUrl &url, QObject *parent) : QObject(parent){
    qDebug() << "Starting websocket " << url;
    m_webSocket = new QWebSocket();
    connect(m_webSocket, &QWebSocket::connected, this, &WebSocketClient::onConnected);
    connect(m_webSocket, &QWebSocket::textMessageReceived, this, &WebSocketClient::onGotData);
    //connect(&m_webSocket, &QWebSocket::close, this, &WebSocketClient::onClose);
    m_webSocket->open(url);
}

void WebSocketClient::onConnected(){
    qDebug() << "got connection";
}

void WebSocketClient::onGotData(QString data){
    qDebug() << data;
}

void WebSocketClient::onClose(){
    qDebug() << "Lost connection";
    closed();
}
