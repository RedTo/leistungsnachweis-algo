#include <random>
#include <set>
#include <unordered_set>
#include "gtest/gtest.h"
#include "../SudokuGitter.h"

//namespace {
//    static set<int> getUniqueSet(set<int> elements) {
//        std::sort(elements.begin(), elements.end());
//        auto last = std::unique(elements.begin(), elements.end());
//        elements.erase(last, elements.end());
//
//        return elements;
//    }
//
//    static bool checkRow(SudokuGitter gitter, const unsigned int size) {
//        for (unsigned int i = 0; i < size; i++) {
//            std::set<int> elements;
//            for (unsigned int j = 0; j < size; j++)
//                elements.insert(gitter.getCell(i, j) - 1);
//
//            elements = getUniqueSet(elements);
//            if (elements.size() != size) {
//                return false;
//            }
//        }
//        return true;
//    }
//
//    static bool checkColumn(SudokuGitter gitter, const unsigned int size) {
//        for (unsigned int i = 0; i < size; i++) {
//            std::set<int> elements;
//            for (unsigned int j = 0; j < size; j++)
//                elements.insert(gitter.getCell(j, i) - 1);
//
//            elements = getUniqueSet(elements);
//            if (elements.size() != size) {
//                return false;
//            }
//        }
//        return true;
//    }
//
//    static bool checkQuad(SudokuGitter gitter, const unsigned int size) {
//        auto quadHeight = static_cast<const unsigned int>(std::sqrt(size));
//        unsigned int quadWidth = size / static_cast<const unsigned int>(std::sqrt(size));
//
//        for (unsigned int quadIndex = 0; quadIndex < size; quadIndex++) {
//            std::set<int> elements;
//
//            unsigned int quadStartColumn = (quadIndex * quadWidth) % size;
//            unsigned int quadStartRow = (quadIndex / quadHeight) * quadHeight;
//
//            for (auto tmpRow = quadStartRow; tmpRow < quadStartRow + quadHeight; tmpRow++) {
//                for (auto tmpCol = quadStartColumn; tmpCol < quadStartColumn + quadWidth; tmpCol++) {
//                    elements.insert(gitter.getCell(tmpRow, tmpCol));
//                }
//            }
//
//            elements = getUniqueSet(elements);
//            if (elements.size() != size) {
//                return false;
//            }
//        }
//        return true;
//    }
//
//
//}
//
//TEST(SudokuGitter_ColRow_Test, Sudoku1_ColRow) {
//    constexpr unsigned int size = 1;
//    SudokuGitter gitter = SudokuGitter(size);
//    gitter.generateNew();
//
//
//    ASSERT_TRUE(checkRow(gitter, size));
//    ASSERT_TRUE(checkColumn(gitter, size));
//    ASSERT_TRUE(checkQuad(gitter, size));
//
//}