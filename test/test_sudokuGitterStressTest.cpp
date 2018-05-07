#include "gtest/gtest.h"
#include "../SudokuGitter.h"

namespace {
    const unsigned int RUNS = 10;

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

    static void buildAndAssertMultiple(int elements) {
        for (unsigned int run = 0; run < RUNS; run++) {
            SudokuGitter gitter = SudokuGitter(elements);
            gitter.generateNew();

            ASSERT_EQ(countZeros(gitter, elements), 0);
        }
    }
}

TEST(SudokuGitterStressTest_Test, Sudoku1_No0_Multiple) {
    const int elements = 1;
    buildAndAssertMultiple(elements);
}

TEST(SudokuGitterStressTest_Test, Sudoku2_No0_Multiple) {
    const int elements = 2;
    buildAndAssertMultiple(elements);
}

TEST(SudokuGitterStressTest_Test, Sudoku3_No0_Multiple) {
    const int elements = 3;
    buildAndAssertMultiple(elements);
}

TEST(SudokuGitterStressTest_Test, Sudoku4_No0_Multiple) {
    const int elements = 4;
    buildAndAssertMultiple(elements);
}

TEST(SudokuGitterStressTest_Test, Sudoku6_No0_Multiple) {
    const int elements = 6;
    buildAndAssertMultiple(elements);
}

TEST(SudokuGitterStressTest_Test, Sudoku8_No0_Multiple) {
    const int elements = 8;
    buildAndAssertMultiple(elements);
}

TEST(SudokuGitterStressTest_Test, Sudoku9_No0_Multiple) {
    const int elements = 9;
    buildAndAssertMultiple(elements);
}

TEST(SudokuGitterStressTest_Test, Sudoku12_No0_Multiple) {
    const int elements = 12;
    buildAndAssertMultiple(elements);
}

TEST(SudokuGitterStressTest_Test, Sudoku15_No0_Multiple) {
    const int elements = 15;
    buildAndAssertMultiple(elements);
}

//TEST(SudokuGitterStressTest_Test, Sudoku16_No0_Multiple) {
//    const int elements = 16;
//    buildAndAssertMultiple(elements);
//}