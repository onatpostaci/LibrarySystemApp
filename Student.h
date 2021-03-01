//
// Created by sinap on 2.03.2021.
//

#ifndef LIBRARY_SYSTEM_APP_STUDENT_H
#define LIBRARY_SYSTEM_APP_STUDENT_H

#include <string>
#include "Book.h"
using namespace std;

class Student{
public:
    Student();
    Student(int id, string name);
    Student(const Student& copy);
    int getID();
    string getName();
    void setID(int id);
    void setName(string name);
    void showStudent();
    void addBookForStudent(const int bookId, const string bookName, const int bookYear);
    void deleteBookForStudent(const int bookId);


    virtual ~Student();


private:
    int id;
    string name;
    int bookCount;
    struct Node2 {
        Book b;
        Node2 *next;
    };
    Node2* head;
};


#endif //LIBRARY_SYSTEM_APP_STUDENT_H
