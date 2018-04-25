#ifndef TESTPROJECT_SUDOKUGITTER_H
#define TESTPROJECT_SUDOKUGITTER_H

#include <vector>

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

public:
    explicit SudokuGitter(unsigned int elements);

    unsigned int getCell(unsigned int row, unsigned int column);

    void generateNew();

    void print();

private:
    const unsigned int getElements() { return elements; }

    const unsigned int getQuadWidth() { return quadWidth; }
    const unsigned int getQuadHeight() { return quadHeight; }

    bool generateCell(unsigned int row, unsigned int column);

    void printVec(vector<unsigned int> vec, string name);

};

#endif //TESTPROJECT_SUDOKUGITTER_H
