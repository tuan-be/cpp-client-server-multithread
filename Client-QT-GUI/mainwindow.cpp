
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sockettest.h"
#include <QtDebug>

QStringListModel *model;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStringListModel(this);

        QStringList list;

        list << "Some Item";
        list.append("Next item!");

        model->setStringList(list);

    ui->listMessage->setModel(model);
    ui->listMessage->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}
SocketTest mTest;
//QString allMeassage = mTest.readyRead();

void MainWindow::on_connectButton_clicked()
{
    QString s = ui->textHost->toPlainText() + " - " + ui->textPort->toPlainText();
    qDebug() << s;
    mTest.setHostPort(ui->textHost->toPlainText(),ui->textPort->toPlainText().toInt());
    mTest.Test();
}



void MainWindow::on_sendButton_clicked()
{
    QString mes = ui->yourMessage->toPlainText();
    mTest.sendMessage(mes.toUtf8());
    ui->yourMessage->clear();
}
