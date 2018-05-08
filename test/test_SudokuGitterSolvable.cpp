#include "test_head.h"

TEST(SudokuGitter_Solvable_Test, Sudoku1_Solvable) {
    const unsigned int size = 1;
    buildAndAssert_Solvable(size);
}

TEST(SudokuGitter_Solvable_Test, Sudoku2_Solvable) {
    constexpr unsigned int size = 2;
    buildAndAssert_Solvable(size);
}

TEST(SudokuGitter_Solvable_Test, Sudoku3_Solvable) {
    constexpr unsigned int size = 3;
    buildAndAssert_Solvable(size);
}

TEST(SudokuGitter_Solvable_Test, Sudoku4_Solvable) {
    constexpr unsigned int size = 4;
    buildAndAssert_Solvable(size);
}

TEST(SudokuGitter_Solvable_Test, Sudoku6_Solvable) {
    constexpr unsigned int size = 6;
    buildAndAssert_Solvable(size);
}

TEST(SudokuGitter_Solvable_Test, Sudoku8_Solvable) {
    constexpr unsigned int size = 8;
    buildAndAssert_Solvable(size);
}

TEST(SudokuGitter_Solvable_Test, Sudoku9_Solvable) {
    constexpr unsigned int size = 9;
    buildAndAssert_Solvable(size);
}

TEST(SudokuGitter_Solvable_Test, Sudoku12_Solvable) {
    constexpr unsigned int size = 12;
    buildAndAssert_Solvable(size);
}

TEST(SudokuGitter_Solvable_Test, Sudoku15_Solvable) {
    constexpr unsigned int size = 15;
    buildAndAssert_Solvable(size);
}

TEST(SudokuGitter_Solvable_Test, Sudoku16_Solvable) {
    constexpr unsigned int size = 16;
    buildAndAssert_Solvable(size);
}