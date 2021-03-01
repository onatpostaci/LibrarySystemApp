//
// Created by sinap on 2.03.2021.
//

#ifndef LIBRARY_SYSTEM_APP_BOOK_H
#define LIBRARY_SYSTEM_APP_BOOK_H


//
// Created by sinap on 16.12.2020.
//

#include <string>
using namespace std;

class Book{

public:
    Book();
    Book(int id, string title, int year);
    void setID(int id);
    void setTitle(string title);
    void setYear(int year);
    void setIsOccupied(bool occupation);
    int getID();
    int getStudentID();
    void setStudentId(int id);
    string getTitle();
    int getYear();
    bool getIsOccupied();
    void displayBook();

    virtual ~Book();

private:
    int id;
    string title;
    int year;
    bool isOccupied;
    int studentId;
};



#endif //LIBRARY_SYSTEM_APP_BOOK_H
