#ifndef TESTPROJECT_SUDOKUGITTER_H
#define TESTPROJECT_SUDOKUGITTER_H

#include <vector>
#include <list>

using namespace std;

struct cell {
    int rowIndex;
    int colIndex;
    unsigned int value;
    bool isStatic = false;

    cell() {
        cell(0, 0);
    }

    cell(int row, int col) {
        rowIndex = row;
        colIndex = col;
        value = 0;
    }

    cell(cell c, bool s) {
        rowIndex = c.rowIndex;
        colIndex = c.colIndex;
        value = c.value;
        isStatic = s;
    }

    cell(int row, int col, unsigned int v) {
        rowIndex = row;
        colIndex = col;
        value = v;
    }

    cell(int row, int col, unsigned int v, bool s) {
        rowIndex = row;
        colIndex = col;
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

private:

    const unsigned int getElements() { return elements; }

    const unsigned int getQuadWidth() { return quadWidth; }

    const unsigned int getQuadHeight() { return quadHeight; }

    friend class ClassicSudokuVisualizer;

    friend class SudokuGenerator;

    vector<vector<cell *>> getQuad(unsigned int hoehenIndex, unsigned int breitenInxted);

    cell getCell(unsigned int row, unsigned int column);
};

#endif //TESTPROJECT_SUDOKUGITTER_H
