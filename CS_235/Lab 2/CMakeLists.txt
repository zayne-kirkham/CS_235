cmake_minimum_required(VERSION 3.23)
project(Lab_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab_2
        graphicsStuff.cpp
        main.cpp
        navigation.cpp
        Navigation.h
        NavigationInterface.h)
