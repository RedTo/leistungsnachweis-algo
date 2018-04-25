#include "gtest/gtest.h"
#include "../SudokuGitter.h"

TEST(SudokuGitter_Test, Sudoku1_No0) {
    const int elements = 1;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    int countZero = 0;
    for (unsigned int row = 0; row < elements; row++) {
        for (unsigned int col = 0; col < elements; col++) {
            if (gitter.getCell(row, col) == 0)
                countZero++;
        }
    }

    ASSERT_EQ(countZero,0);
}

TEST(SudokuGitter_Test, Sudoku2_No0) {
    const int elements = 2;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    int countZero = 0;
    for (unsigned int row = 0; row < elements; row++) {
        for (unsigned int col = 0; col < elements; col++) {
            if (gitter.getCell(row, col) == 0)
                countZero++;
        }
    }

    ASSERT_EQ(countZero,0);
}

TEST(SudokuGitter_Test, Sudoku3_No0) {
    const int elements = 3;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    int countZero = 0;
    for (unsigned int row = 0; row < elements; row++) {
        for (unsigned int col = 0; col < elements; col++) {
            if (gitter.getCell(row, col) == 0)
                countZero++;
        }
    }

    ASSERT_EQ(countZero,0);
}

TEST(SudokuGitter_Test, Sudoku4_No0) {
    const int elements = 4;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    int countZero = 0;
    for (unsigned int row = 0; row < elements; row++) {
        for (unsigned int col = 0; col < elements; col++) {
            if (gitter.getCell(row, col) == 0)
                countZero++;
        }
    }

    ASSERT_EQ(countZero,0);
}

//TODO Sudoku5_No0
//TEST(SudokuGitter_Test, Sudoku5_No0) {
//    const int elements = 5;
//    SudokuGitter gitter = SudokuGitter(elements);
//    gitter.generateNew();
//
//    int countZero = 0;
//    for (unsigned int row = 0; row < elements; row++) {
//        for (unsigned int col = 0; col < elements; col++) {
//            if (gitter.getCell(row, col) == 0)
//                countZero++;
//        }
//    }
//    cout << countZero << endl;
//    ASSERT_FALSE(countZero == 0);
//}

TEST(SudokuGitter_Test, Sudoku6_No0) {
    const int elements = 6;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    int countZero = 0;
    for (unsigned int row = 0; row < elements; row++) {
        for (unsigned int col = 0; col < elements; col++) {
            if (gitter.getCell(row, col) == 0)
                countZero++;
        }
    }

    ASSERT_EQ(countZero,0);
}

//TODO Sudoku7_No0

TEST(SudokuGitter_Test, Sudoku8_No0) {
    const int elements = 8;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    int countZero = 0;
    for (unsigned int row = 0; row < elements; row++) {
        for (unsigned int col = 0; col < elements; col++) {
            if (gitter.getCell(row, col) == 0)
                countZero++;
        }
    }

    ASSERT_EQ(countZero,0);
}

TEST(SudokuGitter_Test, Sudoku9_No0) {
    const int elements = 9;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    int countZero = 0;
    for (unsigned int row = 0; row < elements; row++) {
        for (unsigned int col = 0; col < elements; col++) {
            if (gitter.getCell(row, col) == 0)
                countZero++;
        }
    }

    ASSERT_EQ(countZero,0);
}

TEST(SudokuGitter_Test, Sudoku12_No0) {
    const int elements = 12;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    int countZero = 0;
    for (unsigned int row = 0; row < elements; row++) {
        for (unsigned int col = 0; col < elements; col++) {
            if (gitter.getCell(row, col) == 0)
                countZero++;
        }
    }

    ASSERT_EQ(countZero,0);
}

TEST(SudokuGitter_Test, Sudoku15_No0) {
    const int elements = 15;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    int countZero = 0;
    for (unsigned int row = 0; row < elements; row++) {
        for (unsigned int col = 0; col < elements; col++) {
            if (gitter.getCell(row, col) == 0)
                countZero++;
        }
    }

    ASSERT_EQ(countZero,0);
}

TEST(SudokuGitter_Test, Sudoku16_No0) {
    const int elements = 16;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    int countZero = 0;
    for (unsigned int row = 0; row < elements; row++) {
        for (unsigned int col = 0; col < elements; col++) {
            if (gitter.getCell(row, col) == 0)
                countZero++;
        }
    }

    ASSERT_EQ(countZero,0);
}
