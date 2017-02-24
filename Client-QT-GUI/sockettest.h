#ifndef SOCKETTEST_H
#define SOCKETTEST_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>


class SocketTest : public QObject
{
    Q_OBJECT
public:
    QString host;
    int port;
    explicit SocketTest(QObject *parent = 0);
    void setHostPort(QString iHost, int port);
    void Test();
    void readyUpdateUI(QString);
    void readyUpdateStatus(int);

signals:
    void signalUpdateUI(QString);
    void signalUpdateStatus(int);

public slots:

    void sendMessage(const char *data);
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

private:
    QTcpSocket *socket;

};
#endif // SOCKETTEST_H
