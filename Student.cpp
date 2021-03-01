//
// Created by sinap on 2.03.2021.
//

#include "Student.h"
//
// Created by sinap on 16.12.2020.
//

#include <iostream>

Student::Student() {
    head = NULL;
    bookCount = 0;
}

Student::Student(int id, string name) {
    this->id = id;
    this->name = name;
    head = NULL;
    bookCount = 0;
}

Student::Student(const Student &copy) {}

int Student::getID() {
    return id;
}

string Student::getName() {
    return name;
}

void Student::setID(int id) {
    this->id = id;
}

void Student::setName(string name) {
    this->name = name;
}

void Student::showStudent() {
    cout << "Student id: " << getID() << " student name: " << getName();
}

void Student::addBookForStudent(const int bookId, const string bookName, const int bookYear) {
    bool control = true;
    for (Node2 *curr = head; curr != NULL; curr = curr->next) {
        if (curr->b.getID() == bookId) {
            control = false;
        }
    }
    if (control){
        if (head == NULL){
            head = new Node2;
            head->b.setID(bookId);
            head->b.setTitle(bookName);
            head->b.setYear(bookYear);
            head->b.setIsOccupied(true);
            head->b.setStudentId(id);
            head->next = NULL;
            bookCount++;
            cout<< "Book " << bookId << " has been checked out for student " << id << endl;
        }
        else{
            Node2 *curr = head;
            while (curr->next != NULL){
                curr = curr->next;
            }
            curr->next = new Node2;
            curr = curr->next;
            curr->b.setTitle(bookName);
            curr->b.setID(bookId);
            curr->b.setYear(bookYear);
            curr->next = NULL;
            bookCount++;
            cout << "Book " << bookId << " has been checked out for student "<< id << endl;
        }
    }
    else{
        cout << "Book " << bookId << " has already been checked out by student " << id << endl;
    }
}

void Student::deleteBookForStudent(const int bookId) {
    Node2* rem;
    bool control = false;
    for (Node2* curr = head;  curr!= NULL ; curr = curr->next) {
        if (curr->b.getID()==bookId){
            rem = curr;
            control = true;
            break;
        }
    }

    if(!control){
        cout << "Book " << bookId << " has not been checked out" << endl;
    }

    else{
        Node2* prev = head;
        if (prev->next == NULL && prev == rem){
            delete prev;
            head = NULL;

            cout << "Book " << bookId << " has been returned." << endl;
        }
        else{
            for (Node2* curr = head->next; curr!=NULL ; curr = curr->next) {
                if (curr == rem){
                    Node2* tmp = curr->next;
                    prev->next = tmp;
                    curr->b.setIsOccupied(false);
                    delete curr;

                }
                else if(prev == rem){
                    Node2* tmp = prev->next;
                    head = tmp;
                    delete prev;

                }

                prev = prev->next;
            }
            bookCount--;
            cout << "Book " << bookId << " has been returned." << endl;
        }
    }
}



Student::~Student() {}
