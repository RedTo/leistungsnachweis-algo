#ifndef SUDOKU_TEST_HEAD_H
#define SUDOKU_TEST_HEAD_H

#include <random>
#include <set>
#include <unordered_set>
#include <math.h>
#include "gtest/gtest.h"
#include "../SudokuGitter.h"
#include "../visual/ClassicSudokuVisualizer.h"
#include "../generate/SudokuGenerator.h"
#include "../visual/BigSudokuVisualizer.h"

namespace {
    static bool checkRows(SudokuGitter gitter, const unsigned int size) {
        for (unsigned int row = 0; row < size; row++) {
            std::set<unsigned int> elements;
            for (unsigned int column = 0; column < size; column++) {
                cell item = gitter.getCell(row, column);
                if (item.value != 0)
                    elements.insert(item.value);
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
                if (item.value != 0)
                    elements.insert(item.value);
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
                    if (item.value != 0)
                        elements.insert(item.value);
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
                if (gitter.getCell(row, col).value == 0)
                    countZero++;
            }
        }
        return countZero;
    }

    static void buildAndAssert_NoZero(int elements) {
        SudokuGenerator generator = SudokuGenerator(elements);
        SudokuGitter gitter = generator.generateNew();

        ASSERT_EQ(countZeros(gitter, elements), 0);
    }

    static void buildAndAssert_Elements(int size) {
        SudokuGenerator generator = SudokuGenerator(size);
        SudokuGitter gitter = generator.generateNew();

        ASSERT_TRUE(checkRows(gitter, size));
        ASSERT_TRUE(checkColumns(gitter, size));
        ASSERT_TRUE(checkQuad(gitter, size));
    }

    static void buildAndAssert_Solvable(int size) {
        SudokuGenerator generator = SudokuGenerator(size);
        SudokuGitter gitter = generator.generateNew();
        SudokuGitter solvable = gitter.getSolvable();

        ASSERT_EQ(countZeros(solvable, size), (size * size) - ceil((size * size) * 0.30));
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

    static void startVisualizer(int size) {
        SudokuGenerator generator = SudokuGenerator(size);
        SudokuGitter gitter = generator.generateNew();
        SudokuGitter solvable = gitter.getSolvable();

        ClassicSudokuVisualizer visualizer = ClassicSudokuVisualizer(solvable);
        visualizer.createHTML("output/sudoku" + std::to_string(size) + ".html");
    }

    static void startBigVisualizer(int size) {
        SudokuGenerator generator = SudokuGenerator(size);
        SudokuGitter gitter1 = generator.generateNew().getSolvable();
        SudokuGitter gitter2 = generator.generateNew().getSolvable();
        tuple<SudokuGitter, SudokuGitter> bigGitter = std::make_tuple(gitter1, gitter2);

        BigSudokuVisualizer visualizer = BigSudokuVisualizer(bigGitter);
        visualizer.createHTML("output/big_sudoku" + std::to_string(size) + ".html");
    }
}

#endif //SUDOKU_TEST_HEAD_H
