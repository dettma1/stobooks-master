#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "search.h"
#include "QStackedWidget"
#include "QPushButton"
#include "QInputDialog"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->stackedWidget->setCurrentIndex(0);
    connect(ui->buyerButton, SIGNAL(clicked(bool)), this, SLOT (on_buyerButton_clicked()));
}


MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_buyerButton_clicked()
{
    //QWindow *search = new QWindow;
   // ui->stackedWidget * receivers() = new receivers()
    //ButtonReceiver * receiver = new ButtonReceiver(this);
    ui->stackedWidget->setCurrentIndex(2);
    //ui->buyerButton->setText("clicked");
    //cout << "clicked buyer";


}

//void MainWindow::openNewWindow()
//{
  // ui->stackedWidget->setCurrentIndex(0);
//}

void MainWindow::on_sellerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_exitButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_submitButton_clicked()
{
    QString test = ui->authorTextBox->toPlainText();
    ui->AuthorLabel->setText(test);
}
