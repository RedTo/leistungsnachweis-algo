#ifndef TESTPROJECT_SUDOKUGITTER_H
#define TESTPROJECT_SUDOKUGITTER_H

#include <vector>
#include <list>

using namespace std;

/**
 * Klasse für ein n x n Sudoku Gitter
 */
class SudokuGitter {
private:
    vector<vector<unsigned int>> cells;
    const unsigned int elements;
    const unsigned int quadWidth;
    const unsigned int quadHeight;
    list<int> errorInRow;

public:
    explicit SudokuGitter(unsigned int elements);

    unsigned int getCell(unsigned int row, unsigned int column);

    void setCell(unsigned int row, unsigned int column, unsigned int value);

    void generateNew();

    void print();

    SudokuGitter getSolvable();

private:
    const unsigned int getElements() { return elements; }

    const unsigned int getQuadWidth() { return quadWidth; }

    const unsigned int getQuadHeight() { return quadHeight; }

    bool generateCell(unsigned int row, unsigned int column);

    void printVec(vector<unsigned int> vec, string name);

    unsigned int hadErrorInRow(unsigned int row);

    void zerowRow(unsigned int row);
};

#endif //TESTPROJECT_SUDOKUGITTER_H
