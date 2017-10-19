#ifndef STUDENT_H
#define STUDENT_H
#include <vector>
#include <QString>

#include "book.h"

class Student {
protected:
    QString email;
    QString phone_number;
    QString first_name;
    QString last_name;
    //vector <QString> booksForSale;

public:
    //Get and Set Methods for the corresponding state variables
    Student(QString);
    QString getEmail () {return email;}
    void setEmail (QString e) {email = e;}
    QString getFirst_name () {return first_name;}
    void setFirst_name (QString fn) {first_name = fn;}
    QString getLast_name () {return last_name;}
    void setLast_name (QString ln) {last_name = ln;}
    QString getPhone_number () {return phone_number;}
    void setPhone_number (QString pn) {phone_number = pn;}

};

#endif // STUDENT_H
