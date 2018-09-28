cmake_minimum_required(VERSION 3.12)
project(lab_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab_1
        Figure.h
        main.cpp
        Trapeze.cpp Trapeze.h Rhombus.cpp Rhombus.h Pentagon.cpp Pentagon.h)
