cmake_minimum_required(VERSION 3.9)
project(sudoku)

add_subdirectory(test)
add_subdirectory(googletest)
add_subdirectory(visual)

enable_testing()

set(CMAKE_CXX_STANDARD 11 )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x -lpthread")

set(SOURCE_FILES SudokuGitter.cpp SudokuGitter.h visual/ClassicSudokuVisualizer.h visual/ClassicSudokuVisualizer.cpp)
set(TEST_FILES test/test_head.h test/testMain.cpp test/test_SudokuGitterColRow.cpp test/test_SudokuGitter.cpp test/test_SudokuGitterStressTest.cpp test/test_SudokuGitterColRowStressTest.cpp)
#set(VISUAL_FILES )


add_executable(sudoku main.cpp ${SOURCE_FILES})
set_target_properties(sudoku PROPERTIES LINKER_LANGUAGE CXX)

add_executable(sudoku_Test ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(sudoku_Test gtest gtest_main)
add_test(NAME sudoku_Test COMMAND sudoku_Test)

#add_executable(sudoku_visulizer ${SOURCE_FILLES} ${VISUAL_FILES})
#set_target_properties(sudoku_visulizer PROPERTIES LINKER_LANGUAGE CXX)
