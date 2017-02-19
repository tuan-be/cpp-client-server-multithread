// SocketTest.cpp

#include "sockettest.h"
#include "mainwindow.h"
#include <QTextCodec>

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

    if(!socket->waitForDisconnected(1000))
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

    socket->write("You already joined this chat box!!");
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
    QString message = socket->readAll();
    qDebug() << message;
//    MainWindow *w = new MainWindow();
    // Send signal to UI
//    connect(this, SIGNAL(signalUpdateUI(QString)), w, SLOT(updateListMessage(QString)));
    readyUpdateUI(message);
}

void SocketTest::readyUpdateUI(QString mess)
{
    emit signalUpdateUI(mess);
}

