#include <QCoreApplication>
#include <QDebug>

#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Client c;

    return a.exec();
}
