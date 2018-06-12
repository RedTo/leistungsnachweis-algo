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

    tuple<SudokuGitter, SudokuGitter> generateNewBig();
private:

    bool generateCell(unsigned int row, unsigned int column);

    unsigned int hadErrorInRow(unsigned int row);

    void zerowRow(unsigned int row);

    void printCelVecValPtr(vector<vector<cell *>> vec, string name);

    SudokuGitter solve();

    SudokuGitter generateNewFromRow(unsigned int startRow);
};


#endif //SUDOKU_SUDOKUGENERATOR_H
