#include "test_head.h"

TEST(SudokuGitter_Test, Sudoku1_No0) {
    const int elements = 1;
    buildAndAssert_NoZero(elements);
}

TEST(SudokuGitter_Test, Sudoku2_No0) {
    const int elements = 2;
    buildAndAssert_NoZero(elements);
}

TEST(SudokuGitter_Test, Sudoku3_No0) {
    const int elements = 3;
    buildAndAssert_NoZero(elements);
}

TEST(SudokuGitter_Test, Sudoku4_No0) {
    const int elements = 4;
    buildAndAssert_NoZero(elements);
}

TEST(SudokuGitter_Test, Sudoku6_No0) {
    const int elements = 6;
    buildAndAssert_NoZero(elements);
}

TEST(SudokuGitter_Test, Sudoku8_No0) {
    const int elements = 8;
    buildAndAssert_NoZero(elements);
}

TEST(SudokuGitter_Test, Sudoku9_No0) {
    const int elements = 9;
    buildAndAssert_NoZero(elements);
}

TEST(SudokuGitter_Test, Sudoku12_No0) {
    const int elements = 12;
    buildAndAssert_NoZero(elements);
}
/*
TEST(SudokuGitter_Test, Sudoku15_No0) {
    const int elements = 15;
    buildAndAssert_NoZero(elements);
}

TEST(SudokuGitter_Test, Sudoku16_No0) {
    const int elements = 16;
    buildAndAssert_NoZero(elements);
}*/