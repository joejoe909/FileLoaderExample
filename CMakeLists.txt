cmake_minimum_required(VERSION 3.16)
project(FileLoaderExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(FileLoaderExample
    main.cpp
    mainwindow.cpp
    mainwindow.h
    filenotificationdialog.cpp
    filenotificationdialog.h
)

target_link_libraries(FileLoaderExample PRIVATE Qt6::Widgets)
