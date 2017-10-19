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
    void on_exitButton_2_clicked();
    void on_titleBox_textChanged();
    void on_submitButton_clicked();
    void on_submitButton_2_clicked();

    void on_add1_clicked();
    void on_add2_clicked();
    void on_add3_clicked();
    void on_add4_clicked();

    void on_search2_clicked();

    void on_pushButton_13_clicked();

    void on_postingButton_clicked();

    void on_requestButton_clicked();

    void on_remove1_clicked();
    void on_remove2_clicked();
    void on_remove3_clicked();
    void on_remove4_clicked();

    void on_details1_clicked();
    void on_details2_clicked();
    void on_details3_clicked();
    void on_details4_clicked();

    void on_pushButton_14_clicked();

    void on_submitButton_5_clicked();

    void on_pushButton_clicked();


    void on_back2_clicked();
    void on_back3_clicked();
    void on_back4_clicked();
    void on_back5_clicked();
    void on_back6_clicked();
    void on_back7_clicked();
    void on_back8_clicked();
    void on_back9_clicked();
    void on_back10_clicked();
    void on_back11_clicked();

    //void on_pushButton_19_clicked();

    void on_updateButton_clicked();
    //Create account page
    void on_createAccountButton_clicked();

    void on_buyerButton_2_clicked();

    void on_buyerButton_3_clicked();


    void on_remove_clicked();

    void on_pushButton_3_clicked();

    void on_confirmButton_clicked();

    void on_update_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton * buyerButton;
    int previousPageIndex;

};

#endif // MAINWINDOW_H
