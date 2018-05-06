#include <random>
#include <set>
#include <unordered_set>
#include "gtest/gtest.h"
#include "../SudokuGitter.h"

namespace {
    static bool checkRows(SudokuGitter gitter, const unsigned int size) {
        for (unsigned int row = 0; row < size; row++) {
            std::set<int> elements;
            for (unsigned int column = 0; column < size; column++) {
                auto item = gitter.getCell(row, column);
                if(item != 0)
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
                if(item != 0)
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
                    if(item != 0)
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


}

TEST(SudokuGitter_ColRow_Test, Sudoku1_ColRow) {
    constexpr unsigned int size = 1;
    SudokuGitter gitter = SudokuGitter(size);
    gitter.generateNew();

    ASSERT_TRUE(checkRows(gitter, size));
    ASSERT_TRUE(checkColumns(gitter, size));
    ASSERT_TRUE(checkQuad(gitter, size));

}

TEST(SudokuGitter_ColRow_Test, Sudoku2_ColRow) {
    constexpr unsigned int size = 2;
    SudokuGitter gitter = SudokuGitter(size);
    gitter.generateNew();

    ASSERT_TRUE(checkRows(gitter, size));
    ASSERT_TRUE(checkColumns(gitter, size));
    ASSERT_TRUE(checkQuad(gitter, size));
}

TEST(SudokuGitter_ColRow_Test, Sudoku3_ColRow) {
    constexpr unsigned int size = 3;
    SudokuGitter gitter = SudokuGitter(size);
    gitter.generateNew();

    ASSERT_TRUE(checkRows(gitter, size));
    ASSERT_TRUE(checkColumns(gitter, size));
    ASSERT_TRUE(checkQuad(gitter, size));
}

TEST(SudokuGitter_ColRow_Test, Sudoku4_ColRow) {
    constexpr unsigned int size = 4;
    SudokuGitter gitter = SudokuGitter(size);
    gitter.generateNew();

    ASSERT_TRUE(checkRows(gitter, size));
    ASSERT_TRUE(checkColumns(gitter, size));
    ASSERT_TRUE(checkQuad(gitter, size));
}

TEST(SudokuGitter_ColRow_Test, Sudoku6_ColRow) {
    constexpr unsigned int size = 6;
    SudokuGitter gitter = SudokuGitter(size);
    gitter.generateNew();

    ASSERT_TRUE(checkRows(gitter, size));
    ASSERT_TRUE(checkColumns(gitter, size));
    ASSERT_TRUE(checkQuad(gitter, size));
}

TEST(SudokuGitter_ColRow_Test, Sudoku8_ColRow) {
    constexpr unsigned int size = 8;
    SudokuGitter gitter = SudokuGitter(size);
    gitter.generateNew();

    ASSERT_TRUE(checkRows(gitter, size));
    ASSERT_TRUE(checkColumns(gitter, size));
    ASSERT_TRUE(checkQuad(gitter, size));
}

TEST(SudokuGitter_ColRow_Test, Sudoku9_ColRow) {
    constexpr unsigned int size = 9;
    SudokuGitter gitter = SudokuGitter(size);
    gitter.generateNew();

    ASSERT_TRUE(checkRows(gitter, size));
    ASSERT_TRUE(checkColumns(gitter, size));
    ASSERT_TRUE(checkQuad(gitter, size));
}

TEST(SudokuGitter_ColRow_Test, Sudoku12_ColRow) {
    constexpr unsigned int size = 12;
    SudokuGitter gitter = SudokuGitter(size);
    gitter.generateNew();

    ASSERT_TRUE(checkRows(gitter, size));
    ASSERT_TRUE(checkColumns(gitter, size));
    ASSERT_TRUE(checkQuad(gitter, size));
}

TEST(SudokuGitter_ColRow_Test, Sudoku15_ColRow) {
    constexpr unsigned int size = 15;
    SudokuGitter gitter = SudokuGitter(size);
    gitter.generateNew();

    ASSERT_TRUE(checkRows(gitter, size));
    ASSERT_TRUE(checkColumns(gitter, size));
    ASSERT_TRUE(checkQuad(gitter, size));
}

TEST(SudokuGitter_ColRow_Test, Sudoku16_ColRow) {
    constexpr unsigned int size = 16;
    SudokuGitter gitter = SudokuGitter(size);
    gitter.generateNew();

    ASSERT_TRUE(checkRows(gitter, size));
    ASSERT_TRUE(checkColumns(gitter, size));
    ASSERT_TRUE(checkQuad(gitter, size));
}