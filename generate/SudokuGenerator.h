#ifndef SUDOKU_SUDOKUGENERATOR_H
#define SUDOKU_SUDOKUGENERATOR_H

#include <vector>
#include <list>
#include <string>
#include "../SudokuGitter.h"

using namespace std;

class SudokuGenerator {
private:
    unsigned int elementCount;
    list<int> errorInRow;
    SudokuGitter gitter;

public:
    explicit SudokuGenerator(unsigned int elements) : elementCount(elements), gitter(SudokuGitter(elements)) {}

    SudokuGitter generateNew();

private:
    bool generateCell(unsigned int row, unsigned int column);

    void printVec(vector<unsigned int> vec, string name);

    unsigned int hadErrorInRow(unsigned int row);

    void zerowRow(unsigned int row);
};


#endif //SUDOKU_SUDOKUGENERATOR_H
