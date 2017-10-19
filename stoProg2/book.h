#ifndef BOOK_H
#define BOOK_H
#include <QString>

struct stuOwner {
    QString firstname;
    QString lastname;
    QString phonenumber;
    QString username;
};



class Book
{
    public:
        QString title;
        QString author;
        QString edition;
        QString ISBN;
        QString department;
        QString classNumber;
        QString condition;
        QString OgPrice;
        QString price;
        QString bookOwner;
        stuOwner otherOwner;
        //Default constructor
        Book()
        {
        title = "";
        author = "";
        edition = "";
        ISBN = "";
        department = "";
        classNumber = "";
        condition = "";
        OgPrice = "";
        price = "";
        bookOwner  = "";
        }
        //Methods for our state variables
        //Title
        QString getTitle () {return title;}
        void setTitle (QString t) {title = t;}
        //Author
        QString getAuthor () {return author;}
        void setAuthor (QString a) {author = a;}
        //Edition
        QString getEdition () {return edition;}
        void setEdition (QString e) {edition = e;}
         //ISBN
        QString getISBN () {return ISBN;}
        void setISBN (QString IS) {ISBN = IS;}
        //Department
        QString getDepartment () {return department;}
        void setDepartment (QString d) {department = d;}
        //Class Number
        QString getClassNumber () {return classNumber;}
        void setClassNumber (QString cN) {classNumber = cN;}
        //Condition
        QString getCondition () {return condition;}
        void setCondition (QString c) {condition = c;}
        //Original Price
        QString getOgPrice () {return OgPrice;}
        void setOgPrice (QString og) {OgPrice = og;}
        //Price
        QString getPrice () {return price;}
        void setPrice (QString p) {price = p;}
        //Set the owner of the book
        void setOwner (QString stu)
        {
            bookOwner = stu;
        }
        QString getOwner (){return bookOwner;}
        //set other owner
        stuOwner getOwner2 () {return otherOwner;}
        void setOwner2 (stuOwner o) {otherOwner = o;}
};
#endif // BOOK_H
