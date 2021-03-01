cmake_minimum_required(VERSION 3.17)
project(Library_System_App)

set(CMAKE_CXX_STANDARD 14)

add_executable(Library_System_App main.cpp LibrarySystem.cpp LibrarySystem.h Book.cpp Book.h Student.cpp Student.h)