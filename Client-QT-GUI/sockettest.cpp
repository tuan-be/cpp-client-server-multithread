// SocketTest.cpp

#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) :
    QObject(parent)
{
}

void SocketTest::setHostPort(QString iHost, int iPort ){
    host = iHost;
    port = iPort;
}

void SocketTest::Test()
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
//    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));

    qDebug() << "Connecting,..";

    socket->connectToHost(host, port);

    if(!socket->waitForDisconnected(10000))
    {
        qDebug() << "Error: " << socket->errorString();
    }

}

void SocketTest::sendMessage(const char *data){
     socket->write(data);
}

void SocketTest::connected()
{
    qDebug() << "Connected!";

    socket->write("Hello world!");
}

void SocketTest::disconnected()
{
    qDebug() << "Disconnected!";
}

void SocketTest::bytesWritten(qint64 bytes)
{
    qDebug() << "We wrote: " << bytes;
}

void SocketTest::readyRead()
{
    qDebug() << "Reading...";
    qDebug() << socket->readAll();
}

