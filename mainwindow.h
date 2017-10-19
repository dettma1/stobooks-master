#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include<iostream>
#include<QObject>
#include<QWidget>
using namespace std;

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
    // openNewWindow();

private slots:
    void on_buyerButton_clicked();
    void on_sellerButton_clicked();

    void on_exitButton_2_clicked();

    void on_submitButton_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton * buyerButton;

};

#endif // MAINWINDOW_H
