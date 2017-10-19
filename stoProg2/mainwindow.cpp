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
#include <QTableWidgetItem>
#include<QChar>
#include<QFile>
#include<QTextStream>
#include<QFileDialog>
#include<QTextStream>
#include <QDebug>
#include <QRadioButton>

//const QChar DELIM =  '%';

using namespace std;
QString usefulTitle;
QString usefulOwner;

bool searchStudent(QString user);

//Keep track of the current user
QString currentUser;
stuOwner currentOwner;
Student * currentStudent;

//Container to hold all of the student profiles
vector <Student> students;
//Function to append a Student object onto our vector of students
void addStudent(Student* stu){students.push_back(*stu);}

//Container to hold all of the books
vector <Book> allBooks;
vector <Book> userBooks;

//struct for message requests
class request {
    QString title;
    QString user;
    QString message;
    QString userOwner;
public:
    void setRequest(QString t, QString u, QString m, QString uo) {title = t; user = u; message = m; userOwner = uo;}
    QString getTitle(){return title;}
    QString getUser() {return user;}
    QString getMessage() {return message;}
    QString getUserOwner() {return userOwner;}
};

vector <request> userRequests;
vector <request> allRequests;

void addRequest(request *r) {allRequests.push_back(*r);}
void addUserRequest(request *r) {userRequests.push_back(*r);}

//Function to append a book object onto our vector of books
void addBook(Book *boo){allBooks.push_back(*boo);}
void addUserBook(Book *boo) {userBooks.push_back(*boo);}

//function to take a student and make it a stuOwner and assign it to a book
//void stuToOwner(Student st, Book bk){
//    stuOwner carl;
//    carl.firstname = st.first_name;
//    carl.lastname = st.last_name;
//    carl.phonenumber = st.phone_number;
//    carl.username= st.username;
//    bk.setOwner2(carl);
//}

//void setCurrentOwner(Student st){
//    stuOwner carl;
//    carl.firstname = st.first_name;
//    carl.lastname = st.last_name;
//    carl.phonenumber = st.phone_number;
//    carl.username= st.username;
//    currentOwner = carl;
//}

vector<QString> splitDelim (QString line)
{
    vector <QString> temp;
    QStringList list = line.split("%");
    for (int i = 0; i < list.length();i++)
    {
    temp.push_back(list[i]);
    }
return temp;
}

//read students function
void readStudents()
{
    vector <QString> temp;
    QString Sline;
    QFile myfile ("/Users/hannahdettmann/Desktop/ourStudents.txt");
    myfile.open(QIODevice::ReadOnly);
  // if (myfile.open(QFile::ReadOnly))
  // {
        while (!myfile.atEnd())
            {
                QString line = myfile.readLine();
                temp = splitDelim(line);
                Student * s = new Student;
                int user = 0; int phone = 1; int first = 2; int last = 3;
                s->setUsername(temp[user]);
                s->setPhone_number(temp[phone]);
                s->setFirst_name(temp[first]);
                s->setLast_name(temp[last]);
                currentStudent = s;
                addStudent(s);
            }
        myfile.close();
 //   }
    //else cout << "Unable to open file, please try again.";
}

//Writing student vector to a text file
void writeStudents ()
{
    //QFile::WriteUser;
    QFile file("/Users/hannahdettmann/Desktop/ourStudents.txt");
/*    QString errMsg;

    QFileDevice::FileError err = QFileDevice::NoError;
    if (!file.open(QIODevice::ReadOnly)) {
        errMsg = file.errorString();
        err = file.error();

    } */
    if (file.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        QTextStream stream(&file);
        for (unsigned long i = 0; i < students.size(); i++)
        {
             stream << students[i].getUsername() << '%'
             << students[i].getPhone_number() << '%'
             << students[i].getFirst_name() << '%'
             << students[i].getLast_name() << '%' << endl;
       }

        //cout << "not working" << endl;
    }
    file.close();
}

//Read in books text file
void MainWindow::readBooks()
{
    vector <QString> temp;
    QString Sline;
    QFile myfile ("/Users/hannahdettmann/Desktop/ourBooks.txt");
    if (myfile.open(QIODevice::ReadOnly))
    {
    //int i = 0,currentRows;
    myfile.open(QIODevice::ReadOnly);
        while (!myfile.atEnd())
            {
                QString line = myfile.readLine();
                temp = splitDelim(line);
                Book * b = new Book;
                int title = 0; int author = 1; int edition = 2; int ISBN = 3;
                int condition = 4; int department = 5; int classNumber = 6;
                int OgPrice = 7; int price = 8; int owner = 9;
                b->setTitle(temp[title]);
                b->setAuthor(temp[author]);
                b->setEdition(temp[edition]);
                b->setISBN(temp[ISBN]);
                b->setCondition(temp[condition]);
                b->setDepartment(temp[department]);
                b->setClassNumber(temp[classNumber]);
                b->setOgPrice(temp[OgPrice]);
                b->setPrice(temp[price]);
                b->setOwner(temp[owner]);
                addBook(b);
            }
        myfile.close();
        cout << "book size: " << allBooks.size() << endl;
    }
   //else cout << "Unable to open file, please try again.";
}
void printBook(Book bk)
{
    if (bk.title == "" && bk.author == "" && bk.edition == "" && bk.ISBN == "" && bk.department == "" && bk.classNumber == "" && bk.OgPrice == "" && bk.price == "" && bk.bookOwner == "")
        cout << "\nNo book information provided" << endl;
    cout << "\nBook Information" << endl;
    cout << "–––––––––––––––––––" << endl;
    if ( bk.title.toStdString() != "")
        cout << "Title: " << bk.title.toStdString() << endl;
    if ( bk.author.toStdString() != "")
        cout << "Author: " << bk.author.toStdString() << endl;
    if ( bk.edition.toStdString() != "")
        cout << "Edition: " << bk.edition.toStdString() << endl;
    if (bk.ISBN.toStdString() != "")
        cout << "ISBN: " << bk.ISBN.toStdString() << endl;
    if ( bk.condition.toStdString() != "")
        cout << "Condition: " << bk.condition.toStdString() << endl;
    if ( bk.department.toStdString() != "")
        cout << "Department: " << bk.department.toStdString() << endl;
    if ( bk.classNumber.toStdString() != "")
        cout << "Class Number: " << bk.classNumber.toStdString() << endl;
    if (bk.OgPrice.toStdString() != "")
        cout << "Original Price: $" << bk.OgPrice.toStdString() << endl;
    if (bk.price.toStdString() != "")
        cout << "Price: $" << bk.price.toStdString() << endl;
    if ( bk.bookOwner.toStdString() != "")
        cout << "Owner's User Name: " << bk.bookOwner.toStdString() << endl;
}

void printStudents(){
    for(unsigned long i = 0; i < students.size(); i++){
        Student s = students[i];
        cout << "First name: " << s.getFirst_name().toStdString()<< endl;
        cout << "Last name: " << s.getLast_name().toStdString() << endl;
        cout << "Username: " << s.getUsername().toStdString() << endl;
        cout << endl;
    }
}

void writeBooks ()
{
    QFile file("/Users/hannahdettmann/Desktop/ourBooks.txt");
    if (file.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        QTextStream stream(&file);
        for (unsigned long i = 0; i < allBooks.size(); i++)
        {
            stream << allBooks[i].title << '%'
            << allBooks[i].author << '%'
            << allBooks[i].edition << '%'
            << allBooks[i].ISBN << '%'
            << allBooks[i].condition << '%'
            << allBooks[i].department << '%'
            << allBooks[i].classNumber << '%'
            << allBooks[i].OgPrice << '%'
            << allBooks[i].price << '%'
            << allBooks[i].bookOwner << '%'<< endl;
        }
    }
}

void readRequests()
{
    vector <QString> temp;
    QString Sline;
    QFile myfile ("/Users/hannahdettmann/Desktop/ourRequests.txt");
    myfile.open(QIODevice::ReadOnly);
        while (!myfile.atEnd())
            {
                QString line = myfile.readLine();
                temp = splitDelim(line);
                request * s = new request;
                int title = 0; int user = 1; int message = 2; int userOwner = 3;
                s->setRequest(temp[title], temp[user], temp[message], temp[userOwner]);
                addRequest(s);
            }
        myfile.close();
}

void writeRequests ()
{

    QFile file("/Users/hannahdettmann/Desktop/ourRequests.txt");
    if (file.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        QTextStream stream(&file);
        for (unsigned long i = 0; i < allRequests.size(); i++)
        {
             stream << allRequests[i].getTitle() << '%'
             << allRequests[i].getUser() << '%'
             << allRequests[i].getMessage() << '%'
             << allRequests[i].getUserOwner() << '%' << endl;
       }

    }
    file.close();
}

//Search Method (this needs to be altered)
//void searchBook(QString data, char type)
//{
//    if (type == 'i')
//    {
//    for (int i = 0; i < books.size(); i++)
//        {
//            if (books[i].ISBN == data)
//            {
//                printBook(books[i]);
//            }
//        }
//    }
//    else
//    {
//    for (int i = 0; i < books.size(); i++)
//        {
//            if (books[i].bookOwner == data)
//            {
//                printBook(books[i]);
//            }
//        }
//    }
//}
void addBooksForSale ()
{
    for (unsigned long j = 0; j < students.size(); j++)
    {
        for (unsigned long i = 0; i < allBooks.size(); i++)
        {
            if (allBooks[i].bookOwner == students[j].username)
            {
                students[j].setBooksForSale(allBooks[i]);
            }
        }
    }
}


//Search Method (make sure to read in students first)
bool searchStudent(QString user)
{
    for (unsigned long j = 0; j < students.size(); j++)
    {
        if (students[j].username == user)
        {
            return true;
        }
    }
    return false;
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readStudents();
    printStudents();
    ui->stackedWidget->setCurrentIndex(0);
    //connect(ui->buyerButton, SIGNAL(clicked(bool)), this, SLOT (on_buyerButton_clicked()));
    previousPageIndex = 0;
    ui->back2->setVisible(false);
    ui->pushButton_2->setVisible(false);
    QString tempCondition = "";
    //writeStudents();

}


MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_buyerButton_clicked()
{
    //changes page
    ui->stackedWidget->setCurrentIndex(2);
    ui->back2->setVisible(true);

    //tries to adds books
    int currentRows;
    cout << allBooks.size() << endl;
    if (allBooks.size() > 0)
    {
        ui->tableWidget_4->setRowCount(0);
    for(unsigned long i = 0; i < allBooks.size(); i++)
        {
           // printBook(allBooks[i]);
            //adds book to row of all books
            //int i = 1;
            //cout << ui->tableWidget_4->currentRow();
            currentRows = ui->tableWidget_4->rowCount();
            ui->tableWidget_4->insertRow(ui->tableWidget_4->currentRow());
            ui->tableWidget_4->setRowCount(currentRows +1);
            ui->tableWidget_4->setItem(currentRows,0,new QTableWidgetItem(allBooks[i].bookOwner));
            ui->tableWidget_4->setItem(currentRows,1,new QTableWidgetItem(allBooks[i].title));
            ui->tableWidget_4->setItem(currentRows,2, new QTableWidgetItem(allBooks[i].author));
            ui->tableWidget_4->setItem(currentRows, 3, new QTableWidgetItem(allBooks[i].edition));
            ui->tableWidget_4->setItem(currentRows,4, new QTableWidgetItem(allBooks[i].ISBN));
            ui->tableWidget_4->setItem(currentRows, 5, new QTableWidgetItem("$" + allBooks[i].OgPrice));
            ui->tableWidget_4->setItem(currentRows, 6, new QTableWidgetItem("$" + allBooks[i].price));
            ui->tableWidget_4->setItem(currentRows, 7, new QTableWidgetItem(allBooks[i].condition));

        }
    }

    previousPageIndex = 1;

}

//Create Account Button
void MainWindow::on_createAccountButton_clicked()
{
    //QString username = ui->unameTE->text();
    ui->unameTE->setText(currentUser);
    ui->welcomeLabel->setText("Welcome, " + currentUser);
    //currentUser = username;

    //adds student
       Student * s = new Student;

     //updates student information
     s->setUsername(currentUser);
     s->setFirst_name(ui->fnTE->text());
     s->setLast_name(ui->lnTE->text());
     s->setPhone_number(ui->phTE->text());
     addStudent(s);


     //changes page
     ui->stackedWidget->setCurrentIndex(1);

}



void MainWindow::on_exitButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_submitButton_clicked()
{

    //creates new book
    Book * newBook = new Book;

    //pulls information
    QString t = ui->titleTextBox->text();
    QString a = ui->AuthorTextBox->text();
    QString is = ui->isbnTextBox->text();
    QString ogp = ui->ogPriceTextBox->text();
    QString ap = ui->askPriceTextBox->text();
    QString ed = ui->editionTextBox->text();
    QString dep = ui->departmentTextBox->text();
    QString cl = ui->classNumTextBox->text();

    //Radio Buttons
    if(ui->likeNewRB->isChecked()){
        newBook->setCondition("Like New");
    }
    if(ui->goodRB->isChecked()){
        newBook->setCondition("Good");
    }
    if(ui->okRB->isChecked()){
        newBook->setCondition("Some Damage");
    }


    //sets information
    newBook->setTitle(t);
    newBook->setAuthor(a);
    newBook->setISBN(is);
    newBook->setPrice(ap);
    newBook->setOgPrice(ogp);
    newBook->setEdition(ed);
    newBook->setDepartment(dep);
    newBook->setClassNumber(cl);
    newBook->setOwner(currentUser);
    newBook->setOwner2(currentOwner);
    cout << "current owner first name: " << currentOwner.firstname.toStdString() << endl;


    //adds book to vector
    addUserBook(newBook);
    addBook(newBook);
   // printBook(*newBook);

    //empties outputs
    ui->titleTextBox->setText("");
    ui->AuthorTextBox->setText("");
    ui->isbnTextBox->setText("");
    ui->ogPriceTextBox->setText("");
    ui->askPriceTextBox->setText("");
    ui->editionTextBox->setText("");
    ui->classNumTextBox->setText("");
    ui->departmentTextBox->setText("");

    //empties radio button
    ui->okRB->setChecked(false);
    ui->goodRB->setChecked(false);
    ui->likeNewRB->setChecked(false);

    //adds book to row of all books
    int currentRows = ui->tableWidget_3->rowCount();
    ui->tableWidget_3->setRowCount(currentRows +1);
    ui->tableWidget_3->setItem(currentRows,0,new QTableWidgetItem(currentUser));
    ui->tableWidget_3->setItem(currentRows,1,new QTableWidgetItem(newBook->getTitle()));
    ui->tableWidget_3->setItem(currentRows,2, new QTableWidgetItem(newBook->getAuthor()));
    ui->tableWidget_3->setItem(currentRows, 3, new QTableWidgetItem(newBook->getEdition()));
    ui->tableWidget_3->setItem(currentRows,4, new QTableWidgetItem(newBook->getISBN()));
    ui->tableWidget_3->setItem(currentRows, 5, new QTableWidgetItem("$" + newBook->getOgPrice()));
    ui->tableWidget_3->setItem(currentRows, 6, new QTableWidgetItem("$" + newBook->getPrice()));
    ui->tableWidget_3->setItem(currentRows, 7, new QTableWidgetItem(newBook->getCondition()));

    //changes page back
    ui->stackedWidget->setCurrentIndex(6);
    ui->update->setVisible(false);
    ui->remove->setVisible(false);
}

void MainWindow::on_submitButton_2_clicked()
{
    //reads books in
    readBooks();
    addBooksForSale();

    //reads in requests
    readRequests();

    //sets welcome banner to know who is logged in
    QString username = ui->usernameTextBoxNEW->text();
    currentUser = username;
    ui->back2->setVisible(false);

    if(searchStudent(currentUser))
    {

        //welcomes user
        ui->welcomeLabel->setText("Welcome, " + username);
        currentUser = username;
         //changes page
         ui->stackedWidget->setCurrentIndex(1);

         //adds book to current user vector
         for(int i = 0; i < allBooks.size(); i++){
             Book * mybook = &allBooks[i];
             if (mybook->bookOwner == currentUser){
                 addUserBook(mybook);
             }
         }

    }
    else
    {
        ui->stackedWidget->setCurrentIndex(12);
        ui->unameTE->setText(currentUser);
        ui->fnTE->setFocus();

    }


    //addStudent(currentStudent);

    //advances to next page

    previousPageIndex = 0;
}

/*void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}*/

void MainWindow::on_search2_clicked()
{
  // ui->stackedWidget->setCurrentIndex(10);
  // previousPageIndex = 2;

    //find out which radio button was selected
    QString searchmethod;
    if(ui->radioButton->isChecked()){
        ui->tableWidget_4->setRowCount(0);
        for(int i = 0; i < userBooks.size(); i++){
            if(allBooks[i].title == ui->searchLineEdit->text())
            {
                int currentRows = ui->tableWidget_4->rowCount();
                ui->tableWidget_4->insertRow(ui->tableWidget_4->currentRow());
                ui->tableWidget_4->setRowCount(currentRows +1);
                Book* mybook;
                mybook = &allBooks[i];
                ui->tableWidget_4->setItem(currentRows,0,new QTableWidgetItem(mybook->getOwner()));
                ui->tableWidget_4->setItem(currentRows,1,new QTableWidgetItem(mybook->getTitle()));
                ui->tableWidget_4->setItem(currentRows,2, new QTableWidgetItem(mybook->getAuthor()));
                ui->tableWidget_4->setItem(currentRows, 3, new QTableWidgetItem(mybook->getEdition()));
                ui->tableWidget_4->setItem(currentRows,4, new QTableWidgetItem(mybook->getISBN()));
                ui->tableWidget_4->setItem(currentRows, 5, new QTableWidgetItem("$" + mybook->getOgPrice()));
                ui->tableWidget_4->setItem(currentRows, 6, new QTableWidgetItem("$" + mybook->getPrice()));
                ui->tableWidget_4->setItem(currentRows, 7, new QTableWidgetItem(mybook->getCondition()));
            }

        }

    }
    if(ui->radioButton_2->isChecked()){
        searchmethod = "author";
        ui->tableWidget_4->setRowCount(0);
        for(int i =0; i < allBooks.size(); i++) {
        if(allBooks[i].author == ui->searchLineEdit->text())
        {
            int currentRows = ui->tableWidget_4->rowCount();
            ui->tableWidget_4->insertRow(ui->tableWidget_4->currentRow());
            ui->tableWidget_4->setRowCount(currentRows +1);
            Book* mybook;
            mybook = &allBooks[i];
            ui->tableWidget_4->setItem(currentRows,0,new QTableWidgetItem(mybook->getOwner()));
            ui->tableWidget_4->setItem(currentRows,1,new QTableWidgetItem(mybook->getTitle()));
            ui->tableWidget_4->setItem(currentRows,2, new QTableWidgetItem(mybook->getAuthor()));
            ui->tableWidget_4->setItem(currentRows, 3, new QTableWidgetItem(mybook->getEdition()));
            ui->tableWidget_4->setItem(currentRows,4, new QTableWidgetItem(mybook->getISBN()));
            ui->tableWidget_4->setItem(currentRows, 5, new QTableWidgetItem("$" + mybook->getOgPrice()));
            ui->tableWidget_4->setItem(currentRows, 6, new QTableWidgetItem("$" + mybook->getPrice()));
            ui->tableWidget_4->setItem(currentRows, 7, new QTableWidgetItem(mybook->getCondition()));
        }
    }
    }
    if(ui->radioButton_3->isChecked()){
        searchmethod = "isbn";
                ui->tableWidget_4->setRowCount(0);
        for(int i = 0; i < allBooks.size(); i++) {
                if(allBooks[i].ISBN == ui->searchLineEdit->text())
                {
                    int currentRows = ui->tableWidget_4->rowCount();
                    ui->tableWidget_4->insertRow(ui->tableWidget_4->currentRow());
                    ui->tableWidget_4->setRowCount(currentRows +1);
                    Book* mybook;
                    mybook = &allBooks[i];
                    ui->tableWidget_4->setItem(currentRows,0,new QTableWidgetItem(mybook->getOwner()));
                    ui->tableWidget_4->setItem(currentRows,1,new QTableWidgetItem(mybook->getTitle()));
                    ui->tableWidget_4->setItem(currentRows,2, new QTableWidgetItem(mybook->getAuthor()));
                    ui->tableWidget_4->setItem(currentRows, 3, new QTableWidgetItem(mybook->getEdition()));
                    ui->tableWidget_4->setItem(currentRows,4, new QTableWidgetItem(mybook->getISBN()));
                    ui->tableWidget_4->setItem(currentRows, 5, new QTableWidgetItem("$" + mybook->getOgPrice()));
                    ui->tableWidget_4->setItem(currentRows, 6, new QTableWidgetItem("$" + mybook->getPrice()));
                    ui->tableWidget_4->setItem(currentRows, 7, new QTableWidgetItem(mybook->getCondition()));
                }
        }
    }


    //update table widget with serch results
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->bookHereLabel->setText(usefulTitle);
    ui->stackedWidget->setCurrentIndex(4);
    previousPageIndex = 2;
}

void MainWindow::on_postingButton_clicked()
{
    ui->tableWidget_3->setRowCount(0);

    //adds in new books
    for(int i = 0; i < userBooks.size(); i++){
            int currentRows = ui->tableWidget_3->rowCount();
            ui->tableWidget_3->insertRow(ui->tableWidget_3->currentRow());
            ui->tableWidget_3->setRowCount(currentRows +1);
            Book* mybook;
            mybook = &userBooks[i];
            ui->tableWidget_3->setItem(currentRows,0,new QTableWidgetItem(mybook->getOwner()));
            ui->tableWidget_3->setItem(currentRows,1,new QTableWidgetItem(mybook->getTitle()));
            ui->tableWidget_3->setItem(currentRows,2, new QTableWidgetItem(mybook->getAuthor()));
            ui->tableWidget_3->setItem(currentRows, 3, new QTableWidgetItem(mybook->getEdition()));
            ui->tableWidget_3->setItem(currentRows,4, new QTableWidgetItem(mybook->getISBN()));
            ui->tableWidget_3->setItem(currentRows, 5, new QTableWidgetItem("$" + mybook->getOgPrice()));
            ui->tableWidget_3->setItem(currentRows, 6, new QTableWidgetItem("$" + mybook->getPrice()));
            ui->tableWidget_3->setItem(currentRows, 7, new QTableWidgetItem(mybook->getCondition()));

    }
    ui->stackedWidget->setCurrentIndex(6);
    previousPageIndex = 5;
    ui->update->setVisible(false);
    ui->remove->setVisible(false);
}

void MainWindow::on_requestButton_clicked()
{
    //search throuh all requests and adds them to your vector
    ui->requestWidget->setRowCount(0);
    ui->requestWidget->setColumnWidth(2,100);
    for(int i =0; i < allRequests.size(); i++){
        if(allRequests[i].getUserOwner() == currentUser){
            int currentRows = ui->requestWidget->rowCount();
            ui->requestWidget->insertRow(ui->requestWidget->currentRow());
            ui->requestWidget->setRowCount(currentRows +1);
            ui->requestWidget->setItem(currentRows,0,new QTableWidgetItem(allRequests[i].getTitle()));
            ui->requestWidget->setItem(currentRows,1,new QTableWidgetItem(allRequests[i].getUser()));
            ui->requestWidget->setItem(currentRows,2, new QTableWidgetItem(allRequests[i].getMessage()));
        }
    }
    ui->stackedWidget->setCurrentIndex(7);
    previousPageIndex = 5;

}



void MainWindow::on_pushButton_14_clicked()
{ 
    //clears radio button output again for good measure
    ui->okRB->setChecked(false);
    ui->goodRB->setChecked(false);
    ui->likeNewRB->setChecked(false);

    //sets focus
    ui->titleTextBox->setFocus();

     //changes page
    ui->stackedWidget->setCurrentIndex(8);
    previousPageIndex = 6;
}

void MainWindow::on_submitButton_5_clicked()
{
    //finds selected row
     int selectedRow = ui->tableWidget_3->currentRow();
     Book newBook = userBooks[selectedRow];

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
     newBook.setOgPrice(ogp);
     newBook.setEdition(ed);
     newBook.setDepartment(dep);
     newBook.setClassNumber(cl);


     //pulls radio button information
     if(ui->likeNewRB_3->isChecked()){
         newBook.setCondition("Like New");
     }
     if(ui->goodRB_3->isChecked()){
         newBook.setCondition("Good");
     }
     if(ui->okRB_3->isChecked()){
         newBook.setCondition("Some Damage");
     }



    //update the tableWidget
    ui->tableWidget_3->setItem(selectedRow,0,new QTableWidgetItem(currentUser));
    ui->tableWidget_3->setItem(selectedRow,1,new QTableWidgetItem(newBook.getTitle()));
    ui->tableWidget_3->setItem(selectedRow,2, new QTableWidgetItem(newBook.getAuthor()));
    ui->tableWidget_3->setItem(selectedRow, 3, new QTableWidgetItem(newBook.getEdition()));
    ui->tableWidget_3->setItem(selectedRow,4, new QTableWidgetItem(newBook.getISBN()));
    ui->tableWidget_3->setItem(selectedRow, 5, new QTableWidgetItem("$" + newBook.getOgPrice()));
    ui->tableWidget_3->setItem(selectedRow, 6, new QTableWidgetItem("$" + newBook.getPrice()));
    ui->tableWidget_3->setItem(selectedRow, 7, new QTableWidgetItem(newBook.getCondition()));

    //clears old form
    ui->AuthorTextEdit2->setText("");
    ui->TitleTextEdit2->setText("");
    ui->isbnTextEdit2->setText("");
    ui->ogPriceTextEdit2->setText("");
    ui->askPriceTextEdit2->setText("");
    ui->departmentTextBox2->setText("");
    ui->classNumTextBox2->setText("");
    ui->editionTextEdit2->setText("");

    //clears old radio buttons
    ui->likeNewRB_3->setChecked(false);
    ui->okRB_3->setChecked(false);
    ui->goodRB_3->setChecked(false);

    //changes page
    ui->stackedWidget->setCurrentIndex(6);
    ui->update->setVisible(false);
    ui->remove->setVisible(false);
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
    //ui->stackedWidget->setCurrentIndex(previousPageIndex);
    if(previousPageIndex == ui->stackedWidget->currentIndex()){
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()-1);
        if(ui->stackedWidget->currentIndex() == 5){
            previousPageIndex = 1;
            ui->stackedWidget->setCurrentIndex(previousPageIndex);
        }
        if(ui->stackedWidget->currentIndex() == 0){
            previousPageIndex = 2;
            ui->stackedWidget->setCurrentIndex(previousPageIndex);
        }
        if(ui->stackedWidget->currentIndex() == 7){
            previousPageIndex = 5;
            ui->stackedWidget->setCurrentIndex(previousPageIndex);
        }
        if(ui->stackedWidget->currentIndex() == 8){
            previousPageIndex = 6;
            ui->stackedWidget->setCurrentIndex(previousPageIndex);
        }
        if(ui->stackedWidget->currentIndex() == 13){
            previousPageIndex = 6;
            ui->stackedWidget->setCurrentIndex(previousPageIndex);
        }
        if(ui->stackedWidget->currentIndex() == 12){
            ui->back2->setVisible(false);
            previousPageIndex = 1;
            ui->stackedWidget->setCurrentIndex(previousPageIndex);
        }
        if(ui->stackedWidget->currentIndex() == 1){
            ui->back2->setVisible(false);
        }


    }
    else{
        ui->stackedWidget->setCurrentIndex(previousPageIndex);
        if(ui->stackedWidget->currentIndex() == 0){
        ui->back2->setVisible(false);
        }
        else ui->back2->setVisible(true);
    }
}

void MainWindow::on_updateButton_clicked()
{
   ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_buyerButton_2_clicked()
{

    ui->stackedWidget->setCurrentIndex(5);

    ui->tableWidget_3->setRowCount(0);

    //adds in new books
    for(int i = 0; i < userBooks.size(); i++){
            int currentRows = ui->tableWidget_3->rowCount();
            ui->tableWidget_3->insertRow(ui->tableWidget_3->currentRow());
            ui->tableWidget_3->setRowCount(currentRows +1);
            Book* mybook;
            mybook = &userBooks[i];
            ui->tableWidget_3->setItem(currentRows,0,new QTableWidgetItem(mybook->getOwner()));
            ui->tableWidget_3->setItem(currentRows,1,new QTableWidgetItem(mybook->getTitle()));
            ui->tableWidget_3->setItem(currentRows,2, new QTableWidgetItem(mybook->getAuthor()));
            ui->tableWidget_3->setItem(currentRows, 3, new QTableWidgetItem(mybook->getEdition()));
            ui->tableWidget_3->setItem(currentRows,4, new QTableWidgetItem(mybook->getISBN()));
            ui->tableWidget_3->setItem(currentRows, 5, new QTableWidgetItem("$" + mybook->getOgPrice()));
            ui->tableWidget_3->setItem(currentRows, 6, new QTableWidgetItem("$" + mybook->getPrice()));
            ui->tableWidget_3->setItem(currentRows, 7, new QTableWidgetItem(mybook->getCondition()));

    }
   // previousPageIndex = 5;
    ui->update->setVisible(false);
    ui->remove->setVisible(false);


    ui->back2->setVisible(true);
    previousPageIndex = 1;
}

void MainWindow::on_remove_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}



void MainWindow::on_confirmButton_clicked()
{
    int selectedRow = ui->tableWidget_3->currentRow();
    cout << ui->tableWidget_3->currentRow();
    ui->tableWidget_3->removeRow(selectedRow);
    //delete books[selectedRow];
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_update_clicked()
{
    //find selected index
    int selectedRow = ui->tableWidget_3->currentRow();
    Book mybook = userBooks[selectedRow];

    //sets fields for next page
    ui->AuthorTextEdit2->setText(mybook.getAuthor());
    ui->TitleTextEdit2->setText(mybook.getTitle());
    ui->isbnTextEdit2->setText(mybook.getISBN());
    ui->ogPriceTextEdit2->setText(mybook.getOgPrice());
    ui->askPriceTextEdit2->setText(mybook.getPrice());
    ui->departmentTextBox2->setText(mybook.getDepartment());
    ui->classNumTextBox2->setText(mybook.getClassNumber());
    ui->editionTextEdit2->setText(mybook.getEdition());

    //sets radio button
    if(mybook.getCondition() == "Good"){
        ui->goodRB_3->setChecked(true);
    }
    if(mybook.getCondition() == "Some Damage"){
        ui->okRB_3->setChecked(true);
    }
    if(mybook.getCondition() == "Like New"){
        ui->likeNewRB_3->setChecked(true);
    }


    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_tableWidget_3_cellClicked(int row, int column)
{
    ui->remove->setVisible(true);
    ui->update->setVisible(true);
}

void MainWindow::on_noThanksButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_tableWidget_4_cellClicked(int row, int column)
{
    ui-> pushButton_2 ->setVisible(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    //sets up next page with correct information
    int selectedRow = ui->tableWidget_4->currentRow();
    QString own = allBooks[selectedRow].bookOwner;
    //finds student in student vector
    for(unsigned long i =0; i < students.size(); i++){
        if(students[i].username == own)
            currentStudent = &students[i];
    }

    usefulTitle = allBooks[selectedRow].title;
    usefulOwner = currentStudent->username;
    ui->BookLabel->setText(allBooks[selectedRow].title);
    ui->NameLabel->setText(currentStudent->first_name + " " + currentStudent->last_name);
    ui->EmailLabel->setText(currentStudent->username + "@stolaf.edu");
    ui->Phonelabel->setText(currentStudent->phone_number);

    //changes page
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_exitButton_clicked()
{
    writeStudents();
    writeBooks();
    writeRequests();
}




void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->radioButton->setVisible(true);
    ui->radioButton_2->setVisible(true);
    ui->radioButton_3->setVisible(true);
}

void MainWindow::on_sendRequest_clicked()
{
    QString message = ui->messageReques->toPlainText();
    QString user = currentUser;
    QString title = usefulTitle;
    QString uo = usefulOwner;
    request * r = new request;
    r->setRequest(title,user,message,uo);
    addRequest(r);
    cout << "Request message: " << r->getMessage().toStdString() << endl;
    ui->messageReques->setText("");
    ui->stackedWidget->setCurrentIndex(2);
}
