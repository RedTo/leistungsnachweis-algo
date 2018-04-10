#ifndef TESTPROJECT_SUDOKUGITTER_H
#define TESTPROJECT_SUDOKUGITTER_H

#include <vector>

using namespace std;

/**
 * Class for n x n sudoku gatter
 */
class SudokuGitter {
private:
    vector<vector<int>> cells;
    const unsigned int elements;
    const int quadSize;

public:
    explicit SudokuGitter(unsigned int elements);

    int getCell(int row, int column);

    void generateNew();

    void print();

private:
    const unsigned int getElements() { return elements; }

    const int getQuadSize() { return quadSize; }

    void generateCell(int row, int column);

    void printVec(vector<int> vec, string name);

};

#endif //TESTPROJECT_SUDOKUGITTER_H
