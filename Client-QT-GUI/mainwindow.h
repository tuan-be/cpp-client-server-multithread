#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateListMessage(QString message);

private slots:
    void on_connectButton_clicked();
    void on_sendButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
