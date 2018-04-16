//
// Created by Christian Keller on 26.03.18.
//

#include <iostream>
#include <random>
#include <algorithm>
#include "SudokuGitter.h"

SudokuGitter::SudokuGitter(const unsigned int elements) : elements(elements),
                                                          cells(elements, vector<unsigned int>(elements)),
                                                          quadSize(static_cast<const unsigned int>(std::sqrt(
                                                                  elements))) {
}

void SudokuGitter::generateNew() {

    vector<unsigned int> ziffern(getElements());

    for (unsigned int i = 0; i < getElements(); i++)
        ziffern[i] = i + 1;

    //geordnet erstelle Ziffern in erste Reihe einfügen.
    cells[0] = ziffern;
    shuffle(begin(cells[0]), end(cells[0]), std::mt19937(std::random_device()()));

    print();

    // erste Zeile wird ausgelassen
    for (unsigned int irow = 1; irow < getElements(); irow++) {
        for (unsigned int icol = 0; icol < getElements(); icol++) {
            generateCell(irow, icol);
        }
        print();
    }

}

void SudokuGitter::generateCell(unsigned int row, unsigned int column) {

    vector<unsigned int> ziffern(getElements());
    for (unsigned int i = 0; i < getElements(); i++)
        ziffern[i] = i + 1;
    shuffle(begin(ziffern), end(ziffern), std::mt19937(std::random_device()()));

    vector<unsigned int> quad(getElements());
    vector<unsigned int> currRow(getElements());
    vector<unsigned int> currCol(getElements());

    // Row Werte merken
    currRow = cells[row];
    // Column Werte merken
    for (unsigned int tmpRow = 0; tmpRow < getElements(); tmpRow++) {
        currCol[tmpRow] = static_cast<unsigned int>(getCell(tmpRow, column));
    }

    // Quad Werte merken
    auto quadStartRow = (row / getQuadSize()) * getQuadSize();
    auto quadStartCol = (column / getQuadSize()) * getQuadSize();

    int indexQuad = 0;
    for (auto tmpRow = quadStartRow; tmpRow < quadStartRow + getQuadSize(); tmpRow++) {
        for (auto tmpCol = quadStartCol; tmpCol < quadStartCol + getQuadSize(); tmpCol++) {
            quad[indexQuad] = getCell(tmpRow, tmpCol);
            indexQuad++;
        }
    }

    for (unsigned int i = 0; i < getElements(); i++) {
        auto tmp = static_cast<unsigned int>(ziffern[i]);

        std::cout << "###" << row + 1 << "," << column + 1 << ": Versuch " << tmp << " einzufügen. Umgebung: "
                  << std::endl;
        printVec(currRow, "Row");
        printVec(currCol, "Column");
        printVec(quad, "Quad");


        if (std::find(currRow.begin(), currRow.end(), tmp) == currRow.end() && currRow[getElements() - 1] == 0 &&
            std::find(currCol.begin(), currCol.end(), tmp) == currCol.end() && currCol[getElements() - 1] == 0 &&
            std::find(quad.begin(), quad.end(), tmp) == quad.end() && quad[getElements() - 1] == 0) {
            cells[row][column] = tmp;
            break;
        }
    }

}

unsigned int SudokuGitter::getCell(unsigned int row, unsigned int column) {
    return cells[row][column];
}

void SudokuGitter::print() {
    for (unsigned int irow = 0; irow < getElements(); ++irow) {
        std::cout << " ";
        for (unsigned int icol = 0; icol < getElements(); ++icol) {
            std::cout << cells[irow][icol] << " ";
        }
        std::cout << std::endl; // << "--" << std::endl;
    }
}

void SudokuGitter::printVec(vector<unsigned int> vec, string name) {
    // Print Original Vector
    std::cout << name << ": ";
    for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << " " << vec[i];

    std::cout << std::endl;

}


