//
// Created by Christian Keller on 26.03.18.
//

#include <iostream>
#include <random>
#include <algorithm>
#include <set>
#include "SudokuGitter.h"

/**
 * Konstruktor um ein Sudoku zu erstellen
 * @param elements Gibt die Größe des Sudokus an: elements x elements
 */
SudokuGitter::SudokuGitter(const unsigned int elements) : elements(elements),
                                                          cells(elements, vector<unsigned int>(elements)),
                                                          quadHeight(static_cast<const unsigned int>(std::sqrt(
                                                                  elements))),
                                                          quadWidth(
                                                                  elements / static_cast<const unsigned int>(std::sqrt(
                                                                          elements))) {
    cout << "Create sudoku with: " << elements << " elements." << endl;
    cout << "quad height: " << getQuadHeight() << " quad width:" << getQuadWidth() << endl;
}

/**
 * Generiert ein neues vollständiges Sudoku.
 */
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
        generateCell(irow, 0);
        print();

    }

}

/**
 * Generiert valide Werte für die angegebene Zeile und beginnt bei der angegebenen Zelle. Dazu wird Backtracking verwendet.
 * @param row Zeilenposition
 * @param column Spaltenposition
 * @return Gibt an, ob ein gültiger Wert eingetragen werden kann (Backtracking)
 */
bool SudokuGitter::generateCell(unsigned int row, unsigned int column) {

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
    auto quadStartRow = (row / getQuadHeight()) * getQuadHeight();
    auto quadStartCol = (column / getQuadWidth()) * getQuadWidth();

    int indexQuad = 0;
    for (auto tmpRow = quadStartRow; tmpRow < quadStartRow + getQuadHeight(); tmpRow++) {
        for (auto tmpCol = quadStartCol; tmpCol < quadStartCol + getQuadWidth(); tmpCol++) {
            quad[indexQuad] = getCell(tmpRow, tmpCol);
            indexQuad++;
        }
    }

    set<int> neighbours = {};

    for (auto val : currRow) {
        neighbours.insert(val);
    }
    for (auto val : currCol) {
        neighbours.insert(val);
    }
    for (auto val : quad) {
        neighbours.insert(val);
    }

    set<int> values = {};

    for (unsigned int i = 1; i <= getElements(); i++)
        values.insert(i);

    vector<unsigned int> options;
    set_difference(values.begin(), values.end(), neighbours.begin(), neighbours.end(),
                   inserter(options, options.begin()));

    shuffle(begin(options), end(options), std::mt19937(std::random_device()()));

    unsigned int nextRow = row;
    unsigned int nextCol = column + 1;
    if (column == getElements()) {
        nextCol = 0;
        nextRow++;
    }

    for (unsigned int i = 0; i < options.size(); i++) {
        auto tmp = static_cast<unsigned int>(options[i]);

        std::cout << "###" << row + 1 << "," << column + 1 << ": Versuch " << tmp << " einzufügen. Umgebung: "
                  << std::endl;
        printVec(currRow, "Row");
        printVec(currCol, "Column");
        printVec(quad, "Quad");
        printVec(options, "Options");


        cells[row][column] = tmp;

        if ((column == getElements() - 1) || generateCell(nextRow, nextCol)) {
            return true;
        }
    }

    //cell bereits 0
    cells[row][column] = 0;
    return false;

}

/**
 * Gibt den Wert einer Zelle zurück.
 * @param row Zeilenposition
 * @param column Spaltenposition
 * @return Wert der Zelle
 */
unsigned int SudokuGitter::getCell(unsigned int row, unsigned int column) {
    return cells[row][column];
}

/**
 * Gibt das Sudoku auf der Commandline aus.
 */
void SudokuGitter::print() {
    for (unsigned int irow = 0; irow < getElements(); ++irow) {
        std::cout << " ";
        for (unsigned int icol = 0; icol < getElements(); ++icol) {
            std::cout << cells[irow][icol] << " ";
        }
        std::cout << std::endl; // << "--" << std::endl;
    }
}

/**
 * Gibt einen vector auf der Commandline aus.
 * @param vec auszugebende Vektor
 * @param name Name des Vektors
 */
void SudokuGitter::printVec(vector<unsigned int> vec, string name) {
    // Print Original Vector
    std::cout << name << ": ";
    for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << " " << vec[i];

    std::cout << std::endl;

}


