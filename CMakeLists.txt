cmake_minimum_required(VERSION 3.20)
project(E10ToDoList)

set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

add_executable(E10ToDoList Task.cpp Task.h main.cpp MainFrame.cpp MainFrame.h MyApp.cpp MyApp.h)
target_link_libraries(E10ToDoList ${wxWidgets_LIBRARIES})