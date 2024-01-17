cmake_minimum_required(VERSION 3.20)
project(E10ToDoList)

set(CMAKE_CXX_STANDARD 11)

add_executable(E10ToDoList Task.cpp Task.h main.cpp)
