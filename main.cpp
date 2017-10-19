#include "mainwindow.h"
#include "dialog.h"
#include "search.h"
#include <QApplication>
#include<QWidget>
#include<iostream>
using namespace  std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //MainWindow
    return a.exec();
}

//void openNewWindow()
//{

//}
