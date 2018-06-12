#include "test_head.h"

TEST(SudokuGitter_ColRow_Test, Sudoku1_ColRow) {
    const unsigned int size = 1;
    buildAndAssert_Elements(size);
}

TEST(SudokuGitter_ColRow_Test, Sudoku2_ColRow) {
    constexpr unsigned int size = 2;
    buildAndAssert_Elements(size);
}

TEST(SudokuGitter_ColRow_Test, Sudoku3_ColRow) {
    constexpr unsigned int size = 3;
    buildAndAssert_Elements(size);
}

TEST(SudokuGitter_ColRow_Test, Sudoku4_ColRow) {
    constexpr unsigned int size = 4;
    buildAndAssert_Elements(size);
}

TEST(SudokuGitter_ColRow_Test, Sudoku6_ColRow) {
    constexpr unsigned int size = 6;
    buildAndAssert_Elements(size);
}

TEST(SudokuGitter_ColRow_Test, Sudoku8_ColRow) {
    constexpr unsigned int size = 8;
    buildAndAssert_Elements(size);
}

TEST(SudokuGitter_ColRow_Test, Sudoku9_ColRow) {
    constexpr unsigned int size = 9;
    buildAndAssert_Elements(size);
}

TEST(SudokuGitter_ColRow_Test, Sudoku12_ColRow) {
    constexpr unsigned int size = 12;
    buildAndAssert_Elements(size);
}
/*
TEST(SudokuGitter_ColRow_Test, Sudoku15_ColRow) {
    constexpr unsigned int size = 15;
    buildAndAssert_Elements(size);
}

TEST(SudokuGitter_ColRow_Test, Sudoku16_ColRow) {
    constexpr unsigned int size = 16;
    buildAndAssert_Elements(size);
}*/