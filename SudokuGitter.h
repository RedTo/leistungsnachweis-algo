#ifndef TESTPROJECT_SUDOKUGITTER_H
#define TESTPROJECT_SUDOKUGITTER_H

#include <vector>
#include <list>
#include <string>

using namespace std;

/**
 * Klasse für ein n x n Sudoku Gitter
 */
class SudokuGitter {
public:
    struct cell {
        unsigned int value;
        bool isStatic = false;

        cell() {
            value = 0;
        }

        cell(cell c, bool s) {
            value = c.value;
            isStatic = s;
        }

        cell(unsigned int v) {
            value = v;
        }

        cell(unsigned int v, bool s) {
            value = v;
            isStatic = s;
        }
    };


private:
    vector<vector<cell>> cells;
    const unsigned int elements;
    const unsigned int quadWidth;
    const unsigned int quadHeight;
    list<int> errorInRow;

public:

    explicit SudokuGitter(unsigned int elements);

    cell getCell(unsigned int row, unsigned int column);

    void setCell(unsigned int row, unsigned int column, cell value);

    void generateNew();

    void generateNewBig();

    void print();

    SudokuGitter getSolvable();

private:

    const unsigned int getQuadAmount() { return unsigned int((cells.size() / quadHeight) * (cells[0].size() / quadWidth)); }

    const unsigned int getQuadAmountHeight() { return unsigned int(cells.size() / quadHeight); }

    const unsigned int getQuadAmountWidth() { return unsigned int(cells[0].size() / quadWidth); }

    const unsigned int getElements() { return elements; }

    const unsigned int getQuadWidth() { return quadWidth; }

    const unsigned int getQuadHeight() { return quadHeight; }

    bool generateCell(unsigned int row, unsigned int column);

    void printVec(vector<cell> vec, string name);

    void printVec(vector<unsigned int> vec, string name);

    unsigned int hadErrorInRow(unsigned int row);

    void zerowRow(unsigned int row);

    friend class ClassicSudokuVisualizer;

    void solveBigOne(SudokuGitter gitter);

    vector<vector<cell>> * getQuad(const unsigned int i);

    void belegeQuadVor();

    vector<vector<cell>> *getQuad(const unsigned int h, const unsigned int w);
};

#endif //TESTPROJECT_SUDOKUGITTER_H
