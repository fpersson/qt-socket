#include <QCoreApplication>

#include "websocketclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    WebSocketClient client(QUrl(QString("ws://192.168.43.141:38301")));

    //QObject::connect(&client, &WebSocketClient::closed, &a, &QCoreApplication::quit);
    return a.exec();
}
