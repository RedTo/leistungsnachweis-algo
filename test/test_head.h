#ifndef SUDOKU_TEST_HEAD_H
#define SUDOKU_TEST_HEAD_H

#include <random>
#include <set>
#include <unordered_set>
#include "gtest/gtest.h"
#include "../SudokuGitter.h"
#include "../visual/ClassicSudokuVisualizer.h"

namespace {
    static bool checkRows(SudokuGitter gitter, const unsigned int size) {
        for (unsigned int row = 0; row < size; row++) {
            std::set<int> elements;
            for (unsigned int column = 0; column < size; column++) {
                auto item = gitter.getCell(row, column);
                if (item != 0)
                    elements.insert(item);
            }

            if (elements.size() != size) {
                return false;
            }
            elements.clear();
        }
        return true;
    }

    static bool checkColumns(SudokuGitter gitter, const unsigned int size) {
        for (unsigned int column = 0; column < size; column++) {
            std::set<int> elements;
            for (unsigned int row = 0; row < size; row++) {
                auto item = gitter.getCell(row, column);
                if (item != 0)
                    elements.insert(item);
            }

            if (elements.size() != size) {
                return false;
            }
            elements.clear();
        }
        return true;
    }

    static bool checkQuad(SudokuGitter gitter, const unsigned int size) {
        auto quadHeight = static_cast<const unsigned int>(std::sqrt(size));
        unsigned int quadWidth = size / static_cast<const unsigned int>(std::sqrt(size));

        for (unsigned int quadIndex = 0; quadIndex < size; quadIndex++) {
            std::set<int> elements;

            unsigned int quadStartColumn = (quadIndex * quadWidth) % size;
            unsigned int quadStartRow = (quadIndex / quadHeight) * quadHeight;

            for (auto tmpRow = quadStartRow; tmpRow < quadStartRow + quadHeight; tmpRow++) {
                for (auto tmpCol = quadStartColumn; tmpCol < quadStartColumn + quadWidth; tmpCol++) {
                    auto item = gitter.getCell(tmpRow, tmpCol);
                    if (item != 0)
                        elements.insert(item);
                }
            }

            if (elements.size() != size) {
                return false;
            }
            elements.clear();
        }
        return true;
    }

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

    static void buildAndAssert_NoZero(int elements) {
        SudokuGitter gitter = SudokuGitter(elements);
        gitter.generateNew();

        ASSERT_EQ(countZeros(gitter, elements), 0);
    }

    static void buildAndAssert_Elements(int size) {
        SudokuGitter gitter = SudokuGitter(size);
        gitter.generateNew();

        ASSERT_TRUE(checkRows(gitter, size));
        ASSERT_TRUE(checkColumns(gitter, size));
        ASSERT_TRUE(checkQuad(gitter, size));
    }

    const unsigned int RUNS = 10;

    static void buildAndAssert_NoZero_Multiple(int elements) {
        for (unsigned int run = 0; run < RUNS; run++) {
            buildAndAssert_NoZero(elements);
        }
    }

    static void buildAndAssert_Elements_Multiple(int elements) {
        for (unsigned int run = 0; run < RUNS; run++) {
            buildAndAssert_Elements(elements);
        }
    }

    static void startVisualizer(int size){
        SudokuGitter gitter = SudokuGitter(size);
        gitter.generateNew();
        SudokuGitter solvable = gitter.getSolvable();

        ClassicSudokuVisualizer visualizer = ClassicSudokuVisualizer(gitter);
        visualizer.createHTML("../output/sudoku" + std::to_string(size) +  ".html");
    }
}

#endif //SUDOKU_TEST_HEAD_H
