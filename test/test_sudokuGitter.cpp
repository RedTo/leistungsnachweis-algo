#include "gtest/gtest.h"
#include "../SudokuGitter.h"

namespace {
    static int countZeros(SudokuGitter gitter, int size) {
        int countZero = 0;
        for (unsigned int row = 0; row < size; row++) {
            for (unsigned int col = 0; col < size; col++) {
                if (gitter.getCell(row, col) == 0)
                    countZero++;
            }
        }
        return countZero;
    }
}

TEST(SudokuGitter_Test, Sudoku1_No0) {
    const int elements = 1;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    ASSERT_EQ(countZeros(gitter, elements), 0);
}

TEST(SudokuGitter_Test, Sudoku2_No0) {
    const int elements = 2;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    ASSERT_EQ(countZeros(gitter, elements), 0);
}

TEST(SudokuGitter_Test, Sudoku3_No0) {
    const int elements = 3;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    ASSERT_EQ(countZeros(gitter, elements), 0);
}

TEST(SudokuGitter_Test, Sudoku4_No0) {
    const int elements = 4;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    ASSERT_EQ(countZeros(gitter, elements), 0);
}

TEST(SudokuGitter_Test, Sudoku6_No0) {
    const int elements = 6;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    ASSERT_EQ(countZeros(gitter, elements), 0);
}

TEST(SudokuGitter_Test, Sudoku8_No0) {
    const int elements = 8;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    ASSERT_EQ(countZeros(gitter, elements), 0);
}

TEST(SudokuGitter_Test, Sudoku9_No0) {
    const int elements = 9;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    ASSERT_EQ(countZeros(gitter, elements), 0);
}

TEST(SudokuGitter_Test, Sudoku12_No0) {
    const int elements = 12;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    ASSERT_EQ(countZeros(gitter, elements), 0);
}

TEST(SudokuGitter_Test, Sudoku15_No0) {
    const int elements = 15;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    ASSERT_EQ(countZeros(gitter, elements), 0);
}

//TEST(SudokuGitter_Test, Sudoku16_No0) {
//    const int elements = 16;
//    SudokuGitter gitter = SudokuGitter(elements);
//    gitter.generateNew();
//
//    ASSERT_EQ(countZeros(gitter, elements), 0);
//}
