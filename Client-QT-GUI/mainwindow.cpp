
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sockettest.h"
#include <QtDebug>
#include <QDir>
#include <QFileDialog>

QStringListModel *model;
QStringList listMessage;
SocketTest mTest;
int connectionStatus = 0;

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

    // connect to Socket, get connection status
    connect(&mTest, SIGNAL(signalUpdateStatus(int)), this, SLOT(updateConnectionStatus(int)));
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
    // Check connection status
    if (connectionStatus == 1) {
        QString mes = ui->yourMessage->toPlainText();
        mTest.sendMessage(mes.toUtf8());
        ui->yourMessage->clear();
    } else if (connectionStatus == 0){
        updateListMessage("Please Click on Connect button...");
    } else {
        updateListMessage("Something when wrong :( ");
    }
}

// Handle addFileButton
void MainWindow::on_addFileButton_clicked()
{
    QString pathFile =  openFile();
    if (pathFile != NULL)
    {
        ui->yourMessage->setText(pathFile);
    } else {
        updateListMessage("Can't get your file!");
    }

}


// Update list message on UI
void MainWindow::updateListMessage(QString message)
{
    listMessage.append(message);
    model->setStringList(listMessage);
    ui->listMessage->setModel(model);
}

// Update Connection status on button
void MainWindow::updateConnectionStatus(int status)
{
    QPalette pal = ui->connectButton->palette();
    ui->connectButton->setAutoFillBackground(true);
    // Disconnected
    if (status == 0) {
        connectionStatus = 0;
        pal.setColor(QPalette::Button, Qt::gray);
        ui->connectButton->setPalette(pal);
        ui->connectButton->setText("Disconnected!");
    }
    // Connected
    if (status == 1) {
        connectionStatus = 1;
        pal.setColor(QPalette::Button, Qt::green);
        ui->connectButton->setPalette(pal);
        ui->connectButton->setText("Connected!");
        ui->connectButton->setDisabled(true);
    }
    // Error
    if (status == 2) {
        connectionStatus = 2;
        pal.setColor(QPalette::Button, Qt::yellow);
        ui->connectButton->setPalette(pal);
        ui->connectButton->setText("Error!");
    }
}

// Choice file, get path file

QString MainWindow::openFile()
{
    QString filename =  QFileDialog::getOpenFileName(
          this,
          "Open Document",
          QDir::currentPath(),
          "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)");

    if( !filename.isNull() )
    {
      qDebug() << "selected file path : " << filename.toUtf8();
      return filename;
    }
    return NULL;
}

