#ifndef BOOK_H
#define BOOK_H
#include <QString>



class Book {
	protected: 
        QString price;
        QString OGprice;
		QString ISBN;
		QString title;
		QString author;
		QString edition;
        QString classNumber;
		QString condition;
		QString department;
        //Student bookOwner;

	public:
		//Default constructor
		Book();

        //Methods for our state variables
        //Price
        QString getPrice () {return price;}
        void setPrice (QString p) {price = p;}

        //OG Price
        QString getOGPrice () {return OGprice;}
        void setOGPrice (QString ogp) {OGprice = ogp;}

		//ISBN
		QString getISBN () {return ISBN;}
		void setISBN (QString IS) {ISBN = IS;}

		//Title
		QString getTitle () {return title;}
		void setTitle (QString t) {title = t;}

		//Author
		QString getAuthor () {return author;}
		void setAuthor (QString a) {author = a;}

		//Edition
		QString getEdition () {return edition;}
		void setEdition (QString e) {edition = e;}

		//Class Number
        QString getClassNumber () {return classNumber;}
        void setClassNumber (QString cN) {classNumber = cN;}

		//Condition
		QString getCondition () {return condition;}
		void setCondition (QString c) {condition = c;}

		//Department
		QString getDepartment () {return department;}
		void setDepartment (QString d) {department = d;}
	};
#endif // BOOK_H
