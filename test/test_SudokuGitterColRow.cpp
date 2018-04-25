#include <bitset>
#include "gtest/gtest.h"
#include "../SudokuGitter.h"

TEST(SudokuGitter_ColRow_Test, Sudoku1_ColRow) {
    const int elements = 1;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    for (int i = 0; i < elements; i++) {
        std::bitset<elements> filled;
        for (int j = 0; j < elements; j++)
            filled.set(gitter.getCell(i, j) - 1);
        ASSERT_EQ(filled.count(), elements);
    }

    for (int i = 0; i < elements; i++) {
        std::bitset<elements> filled;
        for (int j = 0; j < elements; j++)
            filled.set(gitter.getCell(j, i) - 1);
        ASSERT_EQ(filled.count(), elements);
    }

    //TODO check for each quad
    //for (int i = 0; i < 9; i += 3)
    //    for (int j = 0; j < 9; j += 3) {
    //        std::bitset<9> filled;
    //        for (int k = 0; k < 3; k++)
    //            for (int l = 0; l < 3; l++)
    //                filled.set(gitter.getCell(i, j) - 1);
    //        ASSERT_EQ(filled.count(), 9);
    //    }

}