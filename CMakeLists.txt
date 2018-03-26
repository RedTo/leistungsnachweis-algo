cmake_minimum_required(VERSION 3.9)
project(testProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(testProject
        main.cpp SudokuGitter.cpp SudokuGitter.h)
