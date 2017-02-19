
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sockettest.h"
#include <QtDebug>

QStringListModel *model;
QStringList listMessage;
SocketTest mTest;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
    listMessage << "Welcome to my chat app!";
    listMessage.append("All messages will be shown here...\n");
    model->setStringList(listMessage);
    ui->listMessage->setModel(model);
    ui->listMessage->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // connect to Socket, get message...
    connect(&mTest, SIGNAL(signalUpdateUI(QString)), this, SLOT(updateListMessage(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Handle when click connectButton
void MainWindow::on_connectButton_clicked()
{
    QString s = ui->textHost->toPlainText() + " - " + ui->textPort->toPlainText();
    qDebug() << s;
    mTest.setHostPort(ui->textHost->toPlainText(),ui->textPort->toPlainText().toInt());
    mTest.Test();
}

// Handle when click sendButton
void MainWindow::on_sendButton_clicked()
{
    QString mes = ui->yourMessage->toPlainText();
    mTest.sendMessage(mes.toUtf8());
    ui->yourMessage->clear();
}

// Update list message on UI
void MainWindow::updateListMessage(QString message)
{
    listMessage.append(message);
    model->setStringList(listMessage);
    ui->listMessage->setModel(model);
}
