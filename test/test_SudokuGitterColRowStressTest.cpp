#include "test_head.h"

TEST(SudokuGitter_ColRow_StressTest_Test, Sudoku1_ColRow_Multiple) {
    const unsigned int size = 1;
    buildAndAssert_Elements_Multiple(size);
}

TEST(SudokuGitter_ColRow_StressTest_Test, Sudoku2_ColRow_Multiple) {
    constexpr unsigned int size = 2;
    buildAndAssert_Elements_Multiple(size);
}

TEST(SudokuGitter_ColRow_StressTest_Test, Sudoku3_ColRow_Multiple) {
    constexpr unsigned int size = 3;
    buildAndAssert_Elements_Multiple(size);
}

TEST(SudokuGitter_ColRow_StressTest_Test, Sudoku4_ColRow_Multiple) {
    constexpr unsigned int size = 4;
    buildAndAssert_Elements_Multiple(size);
}

TEST(SudokuGitter_ColRow_StressTest_Test, Sudoku6_ColRow_Multiple) {
    constexpr unsigned int size = 6;
    buildAndAssert_Elements_Multiple(size);
}

TEST(SudokuGitter_ColRow_StressTest_Test, Sudoku8_ColRow_Multiple) {
    constexpr unsigned int size = 8;
    buildAndAssert_Elements_Multiple(size);
}

TEST(SudokuGitter_ColRow_StressTest_Test, Sudoku9_ColRow_Multiple) {
    constexpr unsigned int size = 9;
    buildAndAssert_Elements_Multiple(size);
}

TEST(SudokuGitter_ColRow_StressTest_Test, Sudoku12_ColRow_Multiple) {
    constexpr unsigned int size = 12;
    buildAndAssert_Elements_Multiple(size);
}

TEST(SudokuGitter_ColRow_StressTest_Test, Sudoku15_ColRow_Multiple) {
    constexpr unsigned int size = 15;
    buildAndAssert_Elements_Multiple(size);
}

//TEST(SudokuGitter_ColRow_StressTest_Test, Sudoku16_ColRow_Multiple) {
//    constexpr unsigned int size = 16;
//    buildAndAssert_Elements_Multiple(size);
//}