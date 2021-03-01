//
// Created by sinap on 2.03.2021.
//

#ifndef LIBRARY_SYSTEM_APP_LIBRARYSYSTEM_H
#define LIBRARY_SYSTEM_APP_LIBRARYSYSTEM_H

#include <string>
#include "Student.h"
using namespace std;

class LibrarySystem {
public:
    LibrarySystem();
    LibrarySystem(const LibrarySystem &lsToCopy);
    void addStudent(const int studentId, const string studentName);
    void deleteStudent(const int studentId);
    void showStudent(const int studentId) const;
    void addBook(const int bookId, const string bookName, const int bookYear);
    void deleteBook(const int bookId);
    void checkoutBook(const int bookId, const int studentId);
    void returnBook(const int bookId);
    void showAllBooks() const;
    void showBook(const int bookId) const;

    virtual ~LibrarySystem();

private:
    struct Node {
        Student s;
        Node *next;
    };
    Node *head;
    int studentCount;

    struct Node2 {
        Book b;
        Node2 *next;
    };
    Node2* head2;
    int countOfBook;
};



#endif //LIBRARY_SYSTEM_APP_LIBRARYSYSTEM_H
