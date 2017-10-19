#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include<iostream>
#include<QObject>
#include<QWidget>
#include<fstream>
#include<QString>
#include<vector>
#include<sstream>

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
    void on_exitButton_2_clicked();
    void on_submitButton_clicked();
    void on_submitButton_2_clicked();

    void on_search2_clicked();

    void on_pushButton_13_clicked();

    void on_postingButton_clicked();

    void on_requestButton_clicked();

    void on_pushButton_14_clicked();

    void on_submitButton_5_clicked();

    void on_pushButton_clicked();


    void on_back2_clicked();


    //void on_pushButton_19_clicked();

    void on_updateButton_clicked();
    //Create account page
    void on_createAccountButton_clicked();

    void on_buyerButton_2_clicked();




    void on_remove_clicked();



    void on_confirmButton_clicked();

    void on_update_clicked();

    void on_tableWidget_3_cellClicked(int row, int column);

    void on_noThanksButton_clicked();

    void on_tableWidget_4_cellClicked(int row, int column);

    void on_pushButton_2_clicked();

    void on_exitButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_sendRequest_clicked();

public:
    Ui::MainWindow *ui;
    QPushButton * buyerButton;
    int previousPageIndex;
    void readBooks();

};

#endif // MAINWINDOW_H
