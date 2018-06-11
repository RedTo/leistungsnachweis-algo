//
// Created by Christian Keller on 26.03.18.
//

#include <iostream>
#include <random>
#include <algorithm>
#include <set>
#include <list>
#include "SudokuGitter.h"

/**
 * Konstruktor um ein Sudoku zu erstellen
 * @param elements Gibt die Größe des Sudokus an: elements x elements
 */
SudokuGitter::SudokuGitter(const unsigned int elements) : elements(elements),
                                                          cells(elements, vector<cell>(elements)),
                                                          quadHeight(static_cast<const unsigned int>(std::sqrt(
                                                                  elements))),
                                                          quadWidth(
                                                                  elements / static_cast<const unsigned int>(std::sqrt(
                                                                          elements))) {
    cout << "Create sudoku with: " << elements << " elements." << endl;
    cout << "quad height: " << getQuadHeight() << " quad width:" << getQuadWidth() << endl;
}

/**
 * Gibt den Wert einer Zelle zurück.
 * @param row Zeilenposition
 * @param column Spaltenposition
 * @return Wert der Zelle
 */
unsigned int SudokuGitter::getCellValue(unsigned int row, unsigned int column) {
    return cells[row][column].value;
}

/**
 * Gibt den Wert einer Zelle zurück.
 * @param row Zeilenposition
 * @param column Spaltenposition
 * @return Wert der Zelle
 */
cell SudokuGitter::getCell(unsigned int row, unsigned int column) {
    return cells[row][column];
}

/**
 * Gibt ein Quad als verschachtelten vector zurück in dem sich Pointer zu den eigentlichen Werten befinden.
 * @param hoehenIndex
 * @param breitenInxted
 * @return Gefordertes Quad des Gitters
 */
vector<vector<cell *>> SudokuGitter::getQuad(unsigned int hoehenIndex, unsigned int breitenInxted) {
    vector<vector<cell *>> result;

    unsigned int startHeightIndex = quadHeight * hoehenIndex;
    unsigned int startWidthIndex = quadWidth * breitenInxted;

    for (int heightIndex = 0; heightIndex < quadHeight; heightIndex++) {
        for (int widthIndex = 0; widthIndex < quadWidth; widthIndex++) {
            result[heightIndex][widthIndex] = &cells[heightIndex + startHeightIndex][widthIndex + startWidthIndex];
        }
    }

    return result;
}

/**
 * Setze ein quad in einem Gitter permanent.
 * @param hoehenIndex
 * @param breitenInxted
 * @return Gefordertes Quad des Gitters
 */
void
SudokuGitter::setQuadPermanent(unsigned int hoehenIndex, unsigned int breitenInxted, vector<vector<cell *>> quadToSet) {
    vector<vector<unsigned int *>> result;

    unsigned int startHeightIndex = quadHeight * hoehenIndex;
    unsigned int startWidthIndex = quadWidth * breitenInxted;

    for (int heightIndex = 0; heightIndex < quadHeight; heightIndex++) {
        for (int widthIndex = 0; widthIndex < quadWidth; widthIndex++) {
            //Setze als fest in beiden Gittern
            cells[heightIndex + startHeightIndex][widthIndex + startWidthIndex].isStatic = true;
            cells[heightIndex + startHeightIndex][widthIndex + startWidthIndex] = *quadToSet[heightIndex][widthIndex];
        }
    }
}

/**
 * Gibt den Wert einer Zelle zurück.
 * @param row Zeilenposition
 * @param column Spaltenposition
 * @return Wert der Zelle
 */
void SudokuGitter::setCell(unsigned int row, unsigned int column, unsigned int value) {
    cells[row][column] = value;
}

/**
 * Gibt das Sudoku auf der Commandline aus.
 */
void SudokuGitter::print() {
    for (unsigned int irow = 0; irow < getElements(); ++irow) {
        std::cout << " ";
        for (unsigned int icol = 0; icol < getElements(); ++icol) {
            std::cout << getCellValue(icol, irow) << " ";
        }
        std::cout << std::endl; // << "--" << std::endl;
    }
}


SudokuGitter SudokuGitter::getSolvable() {
    SudokuGitter solvable = SudokuGitter(getElements());

    int globalElements = getElements() * getElements();

    vector<unsigned int> permutation(globalElements);

    for (int i = 0; i < globalElements; i++) {
        if (i < globalElements * 0.33)
            permutation[i] = 1;
        else
            permutation[i] = 0;
    }

    shuffle(begin(permutation), end(permutation), std::mt19937(std::random_device()()));

    for (unsigned int row = 0; row < getElements(); row++) {
        for (unsigned int col = 0; col < getElements(); col++) {
            if (permutation[row * getElements() + col] == 1)
                solvable.setCell(row, col, getCellValue(row, col));
        }
    }

    return solvable;
}

/**
 * Gibt einen vector auf der Commandline aus.
 * @param vec auszugebende Vektor
 * @param name Name des Vektors
 */
void SudokuGitter::printCellVec(vector<cell> vec, string name) {
    // Print Original Vector
    std::cout << name << ": ";
    for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << " " << vec[i].value;

    std::cout << std::endl;
}

/**
 * Gibt einen vector auf der Commandline aus.
 * @param vec auszugebende Vektor
 * @param name Name des Vektors
 */
void SudokuGitter::printIntVec(vector<unsigned  int> vec, string name) {
    // Print Original Vector
    std::cout << name << ": ";
    for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << " " << vec[i];

    std::cout << std::endl;
}


