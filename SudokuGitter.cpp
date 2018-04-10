//
// Created by Christian Keller on 26.03.18.
//

#include <iostream>
#include <random>
#include "SudokuGitter.h"

SudokuGitter::SudokuGitter(const unsigned int elements) : elements(elements),
                                                          cells(elements, vector<int>(elements)),
                                                          quadSize(static_cast<const int>(std::sqrt(elements))) {
}

void SudokuGitter::generateNew() {

    vector<int> ziffern(getElements());

    for (int i = 0; i < getElements(); i++)
        ziffern[i] = i + 1;

    //geordnet erstelle Ziffern in erste Reihe einfügen.
    cells[0] = ziffern;
    shuffle(begin(cells[0]), end(cells[0]), std::mt19937(std::random_device()()));

    print();

    // erste Zeile wird ausgelassen
    for (int irow = 1; irow < getElements(); irow++) {
        for (int icol = 0; icol < getElements(); icol++) {
            generateCell(irow, icol);
        }
        print();
    }

}

void SudokuGitter::generateCell(int row, int column) {

    vector<int> ziffern(getElements());
    for (int i = 0; i < getElements(); i++)
        ziffern[i] = i + 1;
    shuffle(begin(ziffern), end(ziffern), std::mt19937(std::random_device()()));

    vector<int> quad(getElements());
    vector<int> currRow(getElements());
    vector<int> currCol(getElements());

    // Row Werte merken
    currRow = cells[row];
    // Column Werte merken
    for (int tmpRow = 0; tmpRow < getElements(); tmpRow++) {
        currCol[tmpRow] = getCell(tmpRow, column);
    }

    // Quad Werte merken
    int quadStartRow = (row / getQuadSize()) * getQuadSize();
    int quadStartCol = (column / getQuadSize()) * getQuadSize();

    int indexQuad = 0;
    for (int tmpRow = quadStartRow; tmpRow < quadStartRow + getQuadSize(); tmpRow++) {
        for (int tmpCol = quadStartCol; tmpCol < quadStartCol + getQuadSize(); tmpCol++) {
            quad[indexQuad] = getCell(tmpRow, tmpCol);
            indexQuad++;
        }
    }

    for (int i = 0; i < getElements(); i++) {
        int tmp = ziffern[i];

        std::cout << "###" << row+1 << "," << column+1 << ": Versuch " << tmp << " einzufügen. Umgebung: " << std::endl;
        printVec(currRow, "Row");
        printVec(currCol, "Column");
        printVec(quad, "Quad");


        if (std::find(currRow.begin(), currRow.end(), tmp) == currRow.end() && *currRow.end() == 0 &&
            std::find(currCol.begin(), currCol.end(), tmp) == currCol.end() && *currCol.end() == 0 &&
            std::find(quad.begin(), quad.end(), tmp) == quad.end() && *quad.end() == 0) {
            cells[row][column] = tmp;
            break;
        }
    }

}

int SudokuGitter::getCell(int row, int column) {
    return cells[row][column];
}

void SudokuGitter::print() {
    for (int irow = 0; irow < getElements(); ++irow) {
        std::cout << "|";
        for (int icol = 0; icol < getElements(); ++icol) {
            std::cout << cells[irow][icol] << "|";
        }
        std::cout << std::endl << "--" << std::endl;
    }
}

void SudokuGitter::printVec(vector<int> vec, string name) {
    // Print Original Vector
    std::cout << name << ": ";
    for (int i = 0; i < vec.size(); i++)
        std::cout << " " << vec[i];

    std::cout << std::endl;

}


