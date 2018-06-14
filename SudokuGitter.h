#ifndef TESTPROJECT_SUDOKUGITTER_H
#define TESTPROJECT_SUDOKUGITTER_H

#include <vector>
#include <list>

using namespace std;

struct cell {
    unsigned int value;
    bool isStatic = false;

    cell() {
        value = 0;
    }

    cell(cell c, bool s) {
        value = c.value;
        isStatic = s;
    }

    cell(unsigned int v) {
        value = v;
    }

    cell(unsigned int v, bool s) {
        value = v;
        isStatic = s;
    }
};

/**
 * Klasse für ein n x n Sudoku Gitter
 */
class SudokuGitter {
private:
    vector<vector<cell>> cells;
    unsigned int elements;
    unsigned int quadWidth;
    unsigned int quadHeight;

public:
    explicit SudokuGitter(unsigned int elements);

    unsigned int getCellValue(unsigned int row, unsigned int column);

    void setCell(unsigned int row, unsigned int column, unsigned int value);

    void print();

    SudokuGitter getSolvable();

    static void printCellVec(vector<cell> vec, string name);

    static void printIntVec(vector<unsigned int> vec, string name);

    void setQuadPermanent(unsigned int hoehenIndex, unsigned int breitenInxted, vector<vector<cell *>> quadToSet);

    cell getCell(unsigned int row, unsigned int column);

private:

    const unsigned int getElements() { return elements; }

    const unsigned int getQuadWidth() { return quadWidth; }

    const unsigned int getQuadHeight() { return quadHeight; }

    friend class ClassicSudokuVisualizer;

    friend class BigSudokuVisualizer;

    friend class SudokuGenerator;

    vector<vector<cell *>> getQuad(unsigned int hoehenIndex, unsigned int breitenInxted);

};

#endif //TESTPROJECT_SUDOKUGITTER_H
