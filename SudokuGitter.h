#ifndef TESTPROJECT_SUDOKUGITTER_H
#define TESTPROJECT_SUDOKUGITTER_H

#include <vector>

using namespace std;

/**
 * Class for n x n sudoku gatter
 */
class SudokuGitter {
private:
    vector<vector<unsigned int>> cells;
    const unsigned int elements;
    const unsigned int quadSize;

public:
    explicit SudokuGitter(unsigned int elements);

    unsigned int getCell(unsigned int row, unsigned int column);

    void generateNew();

    void print();

private:
    const unsigned int getElements() { return elements; }

    const unsigned int getQuadSize() { return quadSize; }

    bool generateCell(unsigned int row, unsigned int column);

    void printVec(vector<unsigned int> vec, string name);

};

#endif //TESTPROJECT_SUDOKUGITTER_H
