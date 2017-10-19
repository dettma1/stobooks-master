#include <iostream>
#include <QString>
#include "student.h"

Student::Student(QString username)
{
   email = username;
    phone_number = "\0";
    first_name = "\0";
   last_name = "\0";
}


