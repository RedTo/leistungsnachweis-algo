//
// Created by Christian Keller on 26.03.18.
//

#include <iostream>
#include "SudokuGitter.h"

SudokuGitter::SudokuGitter(const unsigned int elements) : elements(elements), cells(elements, vector<int>(elements)) {
}

void SudokuGitter::generateNew() {
    for (int irow = 0; irow < elements; ++irow) {
        for (int icol = 0; icol < elements; ++icol) {
            cells[irow][icol] = irow * elements + icol;
        }
    }
}

int SudokuGitter::getCell(int row, int column) {
    return cells[row][column];
}

void SudokuGitter::print() {
    for (int irow = 0; irow < elements; ++irow) {
        std::cout << "|";
        for (int icol = 0; icol < elements; ++icol) {
            std::cout << cells[irow][icol] << "|";
        }
        std::cout << std::endl << "-------------------" << std::endl;
    }
}


