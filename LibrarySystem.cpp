//
// Created by sinap on 2.03.2021.
//

#include "LibrarySystem.h"
//
// Created by sinap on 16.12.2020.
//

#include <iostream>
#include <string>
#include "Student.h"

using namespace std;


LibrarySystem::LibrarySystem() {
    head = NULL;
    studentCount = 0;
    head2 = NULL;
    countOfBook = 0;
}

LibrarySystem::~LibrarySystem() {
    if( head != NULL ){
        Node* current  = head;
        Node* next;
        while ( current != NULL ){
            next = current->next;
            delete current;
            current = next;
        }
    }
}

void LibrarySystem::addStudent(const int studentId, const string studentName) {
    bool control = true;
    for (Node *curr = head; curr != NULL; curr = curr->next) {
        if (curr->s.getID() == studentId) {
            control = false;
        }
    }
    if (control){
        if (head == NULL) {
            head = new Node;
            head->s.setID(studentId);
            head->s.setName(studentName);
            head->next = NULL;
            cout << "Student " << studentId << " has been added." << endl;
            studentCount++;
        }
        else {
            Node *curr = head;
            while (curr->next != NULL){
                curr = curr->next;
            }
            curr->next = new Node;
            curr = curr->next;
            curr->s.setName(studentName);
            curr->s.setID(studentId);
            curr->next = NULL;


            studentCount++;
            cout << "Student " << studentId << " has been added." << endl;
        }
    }
    else{
        cout << "Student " << studentId << " already exists" << endl;
    }

}

void LibrarySystem::deleteStudent(const int studentId) {
    Node* rem;
    bool control = false;
    for (Node* curr = head;  curr!= NULL ; curr = curr->next) {
        if (curr->s.getID()==studentId){
            rem = curr;
            control = true;
            break;
        }
    }

    if(!control){
        cout << "Student " << studentId << " does not exist" << endl;
    }

    else{
        Node* prev = head;
        if (prev->next == NULL && prev == rem){
            delete prev;
            head = NULL;

            cout << "Student " << studentId << " has been deleted." << endl;
        }
        else{
            for (Node* curr = head->next; curr!=NULL ; curr = curr->next) {
                if (curr == rem){
                    Node* tmp = curr->next;
                    prev->next = tmp;
                    delete curr;
                    break;

                }
                else if(prev == rem){
                    Node* tmp = prev->next;
                    head = tmp;
                    delete prev;
                    break;
                }

                prev = prev->next;
            }
            studentCount--;
            cout << "Student " << studentId << " has been deleted." << endl;
        }
    }
}

void LibrarySystem::showStudent(const int studentId) const {
    if (head == NULL){
        cout << "No Student exists." << endl;
    }
    else {
        Node *student;
        bool control = false;
        for (Node *curr = head; curr != NULL; curr = curr->next) {
            if (curr->s.getID() == studentId) {
                student = curr;
                control = true;
            }
        }
        if (control){
            student->s.showStudent();
            cout << endl;
        }
        else{
            cout << "Student " << studentId << " does not exist." << endl;
        }
    }
}

void LibrarySystem::addBook(const int bookId, const string bookName, const int bookYear) {
    bool control = true;
    for (Node2 *curr = head2; curr != NULL; curr = curr->next) {
        if (curr->b.getID() == bookId) {
            control = false;
        }
    }
    if (control){
        if (head2 == NULL){
            head2 = new Node2;
            head2->b.setID(bookId);
            head2->b.setTitle(bookName);
            head2->b.setYear(bookYear);
            head2->next = NULL;
            countOfBook++;
            cout<< "Book " << bookId << " has been added." << endl;
        }
        else{
            Node2 *curr = head2;
            while (curr->next != NULL){
                curr = curr->next;
            }
            curr->next = new Node2;
            curr = curr->next;
            curr->b.setTitle(bookName);
            curr->b.setID(bookId);
            curr->b.setYear(bookYear);
            curr->next = NULL;
            countOfBook++;
            cout << "Book " << bookId << " has been added." << endl;
        }
    }
    else{
        cout << "Book " << bookId << " already exists." << endl;
    }
}

void LibrarySystem::deleteBook(const int bookId) {
    bool control = true;
    Node2* rem;
    for (Node2 *curr = head2; curr != NULL; curr = curr->next) {
        if (curr->b.getID() == bookId) {
            rem = curr;
            control = false;
        }
    }
    if(control){
        cout << "Book " << bookId << " does not exist" << endl;
    }
    else {
        Node2 *prev = head2;
        if (prev->next == NULL && prev == rem) {
            delete prev;
            head = NULL;

            cout << "Book " << bookId << " has been deleted." << endl;
        } else {
            for (Node2 *curr = head2->next; curr != NULL; curr = curr->next) {
                if (curr == rem) {
                    Node2 *tmp = curr->next;
                    prev->next = tmp;
                    delete curr;
                    break;

                } else if (prev == rem) {
                    Node2 *tmp = prev->next;
                    head2 = tmp;
                    delete prev;
                    break;
                }

                prev = prev->next;
            }
            countOfBook--;
            cout << "Book " << bookId << " has been deleted." << endl;
        }
    }
}

void LibrarySystem::showBook(const int bookId) const {
    cout << "Book id     Book name       Year        Status" << endl;
    for (Node2 *curr = head2; curr != NULL; curr = curr->next) {
        if (curr->b.getID() == bookId) {
            curr->b.displayBook();
        }
    }
}

void LibrarySystem::showAllBooks() const {
    cout << "Book id     Book name       Year        Status" << endl;
    for (Node2 *curr = head2; curr != NULL; curr = curr->next) {
        curr->b.displayBook();
    }
}

void LibrarySystem::checkoutBook(const int bookId, const int studentId) {
    Node* student;
    for (Node *curr = head; curr != NULL; curr = curr->next) {
        if (curr->s.getID() == studentId) {
            student = curr;
        }
    }
    Node2* book;
    for (Node2 *curr = head2; curr != NULL; curr = curr->next) {
        if (curr->b.getID() == bookId) {
            book = curr;
        }
    }
    student->s.addBookForStudent(bookId, book->b.getTitle(), book->b.getYear());

}

void LibrarySystem::returnBook(const int bookId) {
    Node2* book;
    int studentId = 0;
    for (Node2 *curr = head2; curr != NULL; curr = curr->next) {
        if (curr->b.getID() == bookId) {
            book = curr;
            studentId = curr->b.getStudentID();
        }
    }
    Node* student;
    for (Node *curr = head; curr != NULL; curr = curr->next) {
        if (curr->s.getID() == studentId) {
            student = curr;
        }
    }

    student->s.deleteBookForStudent(book->b.getID());


}
