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

    SudokuGitter generateNewBig();


private:
    void initWithQuad();

    bool generateCell(unsigned int row, unsigned int column);

    bool generateCell(vector<tuple<unsigned int, unsigned int>> list);

    unsigned int hadErrorInRow(unsigned int row);

    void zerowRow(unsigned int row);

    void printCelVecValPtr(vector<vector<cell *>> vec, string name);

    SudokuGitter generateNewTest();

    void initWithLine();
};


#endif //SUDOKU_SUDOKUGENERATOR_H
