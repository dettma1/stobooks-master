#ifndef STUDENT_H
#define STUDENT_H
#include <vector>
#include <QString>
#include "book.h"

using namespace std;

class Student
{
public:
    QString username;
    QString phone_number;
    QString first_name;
    QString last_name;
    //A List Containing the ISBN of the books the Student has for sale;
    vector <Book> booksForSale;
    //Default constructor
    Student()
    {
    username = "";
    phone_number = "";
    first_name = "";
    last_name = "";
    }
    //Get and Set Methods
    QString getUsername () {return username;}
    void setUsername (QString u) {username = u;}
    QString getFirst_name () {return first_name;}
    void setFirst_name (QString fn) {first_name = fn;}
    QString getLast_name () {return last_name;}
    void setLast_name (QString ln) {last_name = ln;}
    QString getPhone_number () {return phone_number;}
    void setPhone_number (QString pn) {phone_number = pn;}
    void setBooksForSale (Book IS) {booksForSale.push_back(IS);}
};

#endif // STUDENT_H
