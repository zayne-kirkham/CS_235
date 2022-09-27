cmake_minimum_required(VERSION 3.23)
project(Project_2_exe)

set(CMAKE_CXX_STANDARD 14)

include_directories(./Maps)

add_executable(Project_2_exe
        main.cpp
        graphicsStuff.cpp
        navigation.cpp
        Navigation.h
        NavigationInterface.h)