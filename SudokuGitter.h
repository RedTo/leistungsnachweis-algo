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
    unsigned int elements;
    unsigned int quadWidth;
    unsigned int quadHeight;

public:
    explicit SudokuGitter(unsigned int elements);

    unsigned int getCell(unsigned int row, unsigned int column);

    void setCell(unsigned int row, unsigned int column, unsigned int value);

    void print();

    SudokuGitter getSolvable();

private:
    const unsigned int getElements() { return elements; }

    const unsigned int getQuadWidth() { return quadWidth; }

    const unsigned int getQuadHeight() { return quadHeight; }

    friend class ClassicSudokuVisualizer;

    friend class SudokuGenerator;
};

#endif //TESTPROJECT_SUDOKUGITTER_H
