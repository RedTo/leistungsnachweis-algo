cmake_minimum_required(VERSION 3.9)
project(sudoku)
set (gtest_SOURCE_DIR "./googletest")

add_subdirectory(test)
add_subdirectory(googletest)
include_directories(./googletest/include googletest)

enable_testing()

set(CMAKE_CXX_STANDARD 11 )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x -lpthread") # #-std=c++11")

set(SOURCE_FILES SudokuGitter.cpp SudokuGitter.h)

add_executable(sudoku_Test test/testMain.cpp test/test_sudokuGitter.cpp ${SOURCE_FILES} test/test_SudokuGitterColRow.cpp)
target_link_libraries(sudoku_Test gtest gtest_main)
add_test(NAME sudoku_Test COMMAND sudoku_Test)

add_executable(sudoku main.cpp ${SOURCE_FILES})
set_target_properties(sudoku PROPERTIES LINKER_LANGUAGE CXX)