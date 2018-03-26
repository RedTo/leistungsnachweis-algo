#ifndef TESTPROJECT_SUDOKUGITTER_H
#define TESTPROJECT_SUDOKUGITTER_H

#include <vector>

using namespace std;

/**
 * Class for n x n sudoku gatter
 */
class SudokuGitter {
    int lines[6][6];
    const unsigned int elements;

public:
    explicit SudokuGitter(unsigned int elements);

    int getCell(int row, int column);

    void generateNew();

    void print();
};


#endif //TESTPROJECT_SUDOKUGITTER_H
