//
// Created by Christian Keller on 26.03.18.
//

#include <iostream>
#include "SudokuGitter.h"

SudokuGitter::SudokuGitter(const unsigned int elements) : elements(elements) {
}

void SudokuGitter::generateNew() {
    for (int irow = 0; irow < elements; ++irow) {
        for (int icol = 0; icol < elements; ++icol) {
            lines[irow][icol] = irow * 6 + icol;
        }
    }
}

int SudokuGitter::getCell(int row, int column) {
    return lines[row][column];
}

void SudokuGitter::print() {
    for (int irow = 0; irow < 6; ++irow) {
        std::cout << "|";
        for (int icol = 0; icol < 6; ++icol) {
            std::cout << lines[irow][icol] << "|";
        }
        std::cout << std::endl << "-------------------" << std::endl;
    }
}
