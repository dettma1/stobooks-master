#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "search.h"
#include "QStackedWidget"
#include "QPushButton"
#include "QInputDialog"
#include "QString"
#include <QTableView>
#include "book.h"
#include "student.h"
#include <vector>

//function to add a row to table3widget
/*void addRow(Book newBook){
    int currentRows = ui->tableWidget_3->rowCount();
    ui->tableWidget_3->setRowCount(currentRows +1);
    ui->tableWidget_3->setItem(currentRows,0,new QTableWidgetItem(currentUser));
    ui->tableWidget_3->setItem(currentRows,1,new QTableWidgetItem(newBook.getTitle()));
    ui->tableWidget_3->setItem(currentRows,2, new QTableWidgetItem(newBook.getAuthor()));
    ui->tableWidget_3->setItem(currentRows, 3, new QTableWidgetItem(newBook.getEdition()));
    ui->tableWidget_3->setItem(currentRows,4, new QTableWidgetItem(newBook.getISBN()));
    ui->tableWidget_3->setItem(currentRows, 5, new QTableWidgetItem("$" + newBook.getOGPrice()));
    ui->tableWidget_3->setItem(currentRows, 6, new QTableWidgetItem("$" + newBook.getPrice()));
}
*/

//Container to hold all of the books
vector <Book> books;
QString currentUser;
//Function to append a Student object onto our vector of books
void addBook(Book boo)
{
    books.push_back(boo);
}
//Container to hold all of the student profiles
vector <Student> students;
//Function to append a Student object onto our vector of students
void addStudent(Student stu)
{
    students.push_back(stu);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->stackedWidget->setCurrentIndex(0);
    connect(ui->buyerButton, SIGNAL(clicked(bool)), this, SLOT (on_buyerButton_clicked()));
    previousPageIndex = 0;
}


MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_buyerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    previousPageIndex = 1;

}

//Create Account Button
void MainWindow::on_createAccountButton_clicked()
{
    QString username = ui->unameTE->text();
    ui->welcomeLabel->setText("Welcome, " + username);
    currentUser = username;

    //adds student
     Student currentStudent(username);

     //updates student information
     currentStudent.setEmail(username + "@stolaf.edu");
     currentStudent.setFirst_name(ui->fnTE->text());
     currentStudent.setLast_name(ui->lnTE->text());
     currentStudent.setPhone_number(ui->phTE->text());

     //changes page
     ui->stackedWidget->setCurrentIndex(1);

}



void MainWindow::on_exitButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_titleBox_textChanged()
{
    //QString test = ui->authorTextBox->toPlainText();
    //ui->AuthorLabel->setText(test);
}

void MainWindow::on_submitButton_clicked()
{

    //creates new book
    Book newBook;

    //pulls information
    QString t = ui->titleTextBox->text();
    QString a = ui->AuthorTextBox->text();
    QString is = ui->isbnTextBox->text();
    QString ogp = ui->ogPriceTextBox->text();
    QString ap = ui->askPriceTextBox->text();
    QString ed = ui->editionTextBox->text();
    QString dep = ui->departmentTextBox->text();
    QString cl = ui->classNumTextBox->text();

    //sets information
    newBook.setTitle(t);
    newBook.setAuthor(a);
    newBook.setISBN(is);
    newBook.setPrice(ap);
    newBook.setOGPrice(ogp);
    newBook.setEdition(ed);
    newBook.setDepartment(dep);
    newBook.setClassNumber(cl);

    //adds book to vector
    addBook(newBook);

    //empties outputs
    ui->titleTextBox->setText("");
    ui->AuthorTextBox->setText("");
    ui->isbnTextBox->setText("");
    ui->ogPriceTextBox->setText("");
    ui->askPriceTextBox->setText("");
    ui->editionTextBox->setText("");
    ui->classNumTextBox->setText("");
    ui->departmentTextBox->setText("");

    //adds book to row of all books
    int currentRows = ui->tableWidget_3->rowCount();
    ui->tableWidget_3->setRowCount(currentRows +1);
    ui->tableWidget_3->setItem(currentRows,0,new QTableWidgetItem(currentUser));
    ui->tableWidget_3->setItem(currentRows,1,new QTableWidgetItem(newBook.getTitle()));
    ui->tableWidget_3->setItem(currentRows,2, new QTableWidgetItem(newBook.getAuthor()));
    ui->tableWidget_3->setItem(currentRows, 3, new QTableWidgetItem(newBook.getEdition()));
    ui->tableWidget_3->setItem(currentRows,4, new QTableWidgetItem(newBook.getISBN()));
    ui->tableWidget_3->setItem(currentRows, 5, new QTableWidgetItem("$" + newBook.getOGPrice()));
    ui->tableWidget_3->setItem(currentRows, 6, new QTableWidgetItem("$" + newBook.getPrice()));

    //changes page back
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_submitButton_2_clicked()
{
    //sets welcome banner to know who is logged in
    QString username = ui->usernameTextBoxNEW->text();

    if(username == "dettma1" || username == "son3" || username == "frank" || username == "mccrae1"){

        //welcomes user
        ui->welcomeLabel->setText("Welcome, " + username);
        currentUser = username;

        //adds student
         Student currentStudent(username);

         //changes page
         ui->stackedWidget->setCurrentIndex(1);
    }
    else{
        ui->stackedWidget->setCurrentIndex(12);
    }


    //addStudent(currentStudent);

    //advances to next page

    previousPageIndex = 0;
}

/*void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}*/

void MainWindow::on_add1_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    previousPageIndex = 2;
}

void MainWindow::on_add2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    previousPageIndex = 2;
}

void MainWindow::on_add3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    previousPageIndex = 2;
}
void MainWindow::on_add4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    previousPageIndex = 2;
}

void MainWindow::on_search2_clicked()
{
   ui->stackedWidget->setCurrentIndex(10);
   previousPageIndex = 2;
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    previousPageIndex = 2;
}

void MainWindow::on_postingButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    previousPageIndex = 5;
}

void MainWindow::on_requestButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    previousPageIndex = 5;
}

void MainWindow::on_remove1_clicked()
{
    //ui->stackedWidget->setCurrentIndex(7);
}
void MainWindow::on_remove2_clicked()
{
    //ui->stackedWidget->setCurrentIndex(7);
}
void MainWindow::on_remove3_clicked()
{
    //ui->stackedWidget->setCurrentIndex(7);
}
void MainWindow::on_remove4_clicked()
{
    //ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_details1_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    previousPageIndex = 6;
}
void MainWindow::on_details2_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    previousPageIndex = 6;
}
void MainWindow::on_details3_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    previousPageIndex = 6;
}
void MainWindow::on_details4_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    previousPageIndex = 6;
}

void MainWindow::on_pushButton_14_clicked()
{

    //changes page
    ui->stackedWidget->setCurrentIndex(8);
    previousPageIndex = 6;
}

void MainWindow::on_submitButton_5_clicked()
{
    //finds selected row
     int selectedRow = ui->tableWidget_3->currentRow();
     Book newBook = books[selectedRow];

     //pulls information
     QString t = ui->TitleTextEdit2->text();
     QString a = ui->AuthorTextEdit2->text();
     QString is = ui->isbnTextEdit2->text();
     QString ogp = ui->ogPriceTextEdit2->text();
     QString ap = ui->askPriceTextEdit2->text();
     QString ed = ui->editionTextEdit2->text();
     QString dep = ui->departmentTextBox2->text();
     QString cl = ui->classNumTextBox2->text();


     //updates book
     newBook.setTitle(t);
     newBook.setAuthor(a);
     newBook.setISBN(is);
     newBook.setPrice(ap);
     newBook.setOGPrice(ogp);
     newBook.setEdition(ed);
     newBook.setDepartment(dep);
     newBook.setClassNumber(cl);



    //update the tableWidget
    ui->tableWidget_3->setItem(selectedRow,0,new QTableWidgetItem(currentUser));
    ui->tableWidget_3->setItem(selectedRow,1,new QTableWidgetItem(newBook.getTitle()));
    ui->tableWidget_3->setItem(selectedRow,2, new QTableWidgetItem(newBook.getAuthor()));
    ui->tableWidget_3->setItem(selectedRow, 3, new QTableWidgetItem(newBook.getEdition()));
    ui->tableWidget_3->setItem(selectedRow,4, new QTableWidgetItem(newBook.getISBN()));
    ui->tableWidget_3->setItem(selectedRow, 5, new QTableWidgetItem("$" + newBook.getOGPrice()));
    ui->tableWidget_3->setItem(selectedRow, 6, new QTableWidgetItem("$" + newBook.getPrice()));

    //clears old form
    ui->AuthorTextEdit2->setText("");
    ui->TitleTextEdit2->setText("");
    ui->isbnTextEdit2->setText("");
    ui->ogPriceTextEdit2->setText("");
    ui->askPriceTextEdit2->setText("");
    ui->departmentTextBox2->setText("");
    ui->classNumTextBox2->setText("");
    ui->editionTextEdit2->setText("");

    //changes page
    ui->stackedWidget->setCurrentIndex(6);
    previousPageIndex = 11;
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    previousPageIndex = 10;
}

//Back Buttons

void MainWindow::on_back2_clicked()
{
    ui->stackedWidget->setCurrentIndex(previousPageIndex);
    if(previousPageIndex == 2){
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void MainWindow::on_back3_clicked()
{
   ui->stackedWidget->setCurrentIndex(previousPageIndex);
   if(previousPageIndex == 3){
       ui->stackedWidget->setCurrentIndex(2);
   }
}
void MainWindow::on_back4_clicked()
{
   ui->stackedWidget->setCurrentIndex(previousPageIndex);
   if(previousPageIndex == 4){
       ui->stackedWidget->setCurrentIndex(3);
   }
}
void MainWindow::on_back5_clicked()
{
   ui->stackedWidget->setCurrentIndex(previousPageIndex);
   if(previousPageIndex == 5){
       ui->stackedWidget->setCurrentIndex(1);
   }
}
void MainWindow::on_back6_clicked()
{
   ui->stackedWidget->setCurrentIndex(previousPageIndex);
   if(previousPageIndex == 6){
       ui->stackedWidget->setCurrentIndex(5);
   }
}
void MainWindow::on_back7_clicked()
{
   ui->stackedWidget->setCurrentIndex(previousPageIndex);
   if(previousPageIndex == 7){
       ui->stackedWidget->setCurrentIndex(5);
   }
}
void MainWindow::on_back8_clicked()
{
   ui->stackedWidget->setCurrentIndex(previousPageIndex);
   if(previousPageIndex == 8){
       ui->stackedWidget->setCurrentIndex(6);
   }
}
void MainWindow::on_back9_clicked()
{
   ui->stackedWidget->setCurrentIndex(previousPageIndex);
   if(previousPageIndex == 9){
       ui->stackedWidget->setCurrentIndex(6);
   }
}
void MainWindow::on_back10_clicked()
{
   ui->stackedWidget->setCurrentIndex(previousPageIndex);
   if(previousPageIndex == 10){
       ui->stackedWidget->setCurrentIndex(2);
   }
}
void MainWindow::on_back11_clicked()
{
   ui->stackedWidget->setCurrentIndex(previousPageIndex);
   if(previousPageIndex == 11){
       ui->stackedWidget->setCurrentIndex(9);
   }
}

void MainWindow::on_updateButton_clicked()
{
   ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_buyerButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    previousPageIndex = 1;
}

void MainWindow::on_buyerButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    previousPageIndex = 1;
}


void MainWindow::on_remove_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_confirmButton_clicked()
{
    int selectedRow = ui->tableWidget_3->currentRow();
    cout << ui->tableWidget_3->currentRow();
    ui->tableWidget_3->removeRow(selectedRow);
   //delete books[selectedRow+1];
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_update_clicked()
{
    //find selected index
    int selectedRow = ui->tableWidget_3->currentRow();
    Book mybook = books[selectedRow];

    //sets fields for next page
    ui->AuthorTextEdit2->setText(mybook.getAuthor());
    ui->TitleTextEdit2->setText(mybook.getTitle());
    ui->isbnTextEdit2->setText(mybook.getISBN());
    ui->ogPriceTextEdit2->setText(mybook.getOGPrice());
    ui->askPriceTextEdit2->setText(mybook.getPrice());
    ui->departmentTextBox2->setText(mybook.getDepartment());
    ui->classNumTextBox2->setText(mybook.getClassNumber());
    ui->editionTextEdit2->setText(mybook.getEdition());

    ui->stackedWidget->setCurrentIndex(11);
}
