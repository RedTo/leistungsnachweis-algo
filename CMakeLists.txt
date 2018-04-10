cmake_minimum_required(VERSION 3.9)
project(leistungsnachweis-algo)

set(CMAKE_CXX_STANDARD 11)

add_executable(leistungsnachweis-algo
        main.cpp SudokuGitter.cpp SudokuGitter.h)
