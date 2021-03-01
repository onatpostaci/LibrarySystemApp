//
// Created by sinap on 2.03.2021.
//

#include "Book.h"
//
// Created by sinap on 16.12.2020.
//

#include <iostream>

Book::Book() {
}

Book::Book(int id, string title, int year) {
    this->id = id;
    this->title = title;
    this->year = year;
    isOccupied = false;
}

Book::~Book() {}

void Book::setID(int id) {
    this->id = id;
}

void Book::setTitle(string title) {
    this->title = title;
}

void Book::setYear(int year) {
    this->year = year;
}

int Book::getID() {
    return id;
}

void Book::setIsOccupied(bool occupation) {
    isOccupied = occupation;
}

void Book::setStudentId(int id) {
    studentId = id;
}

string Book::getTitle() {
    return title;
}

int Book::getYear() {
    return year;
}

bool Book::getIsOccupied() {
    return isOccupied;
}

int Book::getStudentID() {
    return studentId;
}

void Book::displayBook() {
    if (getIsOccupied()){
        cout << id << "     " << title << "     " << year << "      Checked out by " << studentId << endl;
    }
    else{
        cout << id << "     " << title << "     " << year << "      Not checked out." << endl;
    }

}
