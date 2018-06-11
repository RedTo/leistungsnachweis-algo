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
 * Gibt den Wert einer Zelle zurück.
 * @param row Zeilenposition
 * @param column Spaltenposition
 * @return Wert der Zelle
 */
unsigned int SudokuGitter::getCell(unsigned int row, unsigned int column) {
    return cells[row][column];
}

/**
 * Gibt ein Quad als verschachtelten vector zurück in dem sich Pointer zu den eigentlichen Werten befinden.
 * @param hoehenIndex
 * @param breitenInxted
 * @return Gefordertes Quad des Gitters
 */
vector<vector<unsigned int*>> SudokuGitter::getQuad(unsigned int hoehenIndex, unsigned int breitenInxted) {
    vector<vector<unsigned int*>> result;

    unsigned int startHeightIndex = quadHeight * hoehenIndex;
    unsigned int startWidthIndex = quadWidth * breitenInxted;

    //if (endHeihgt > elements || endWidth > elements)
    //    throw std::invalid_argument( "Quad index out of bounds! Index cant be higher than available quad amount." );
    //else if (hoehenIndex < 0 || breitenInxted < 0)
    //   throw std::invalid_argument( "Quad index out of bounds! Index cant be lower than 0." );

    for (int heightIndex = 0; heightIndex < quadHeight; heightIndex++) {
        for (int widthIndex = 0; widthIndex < quadWidth; widthIndex++) {
            result[heightIndex][widthIndex] = &cells[heightIndex+startHeightIndex][widthIndex+startWidthIndex];
        }
    }
}

/**
 * Setze ein quad in einem Gitter permanent.
 * @param hoehenIndex
 * @param breitenInxted
 * @return Gefordertes Quad des Gitters
 */
void SudokuGitter::setQuad(unsigned int hoehenIndex, unsigned int breitenInxted, vector<vector<unsigned int*>> quadToSet) {
    vector<vector<unsigned int*>> result;

    unsigned int startHeightIndex = quadHeight * hoehenIndex;
    unsigned int startWidthIndex = quadWidth * breitenInxted;

    //if (endHeihgt > elements || endWidth > elements)
    //    throw std::invalid_argument( "Quad index out of bounds! Index cant be higher than available quad amount." );
    //else if (hoehenIndex < 0 || breitenInxted < 0)
    //   throw std::invalid_argument( "Quad index out of bounds! Index cant be lower than 0." );

    for (int heightIndex = 0; heightIndex < quadHeight; heightIndex++) {
        for (int widthIndex = 0; widthIndex < quadWidth; widthIndex++) {
            cells[heightIndex+startHeightIndex][widthIndex+startWidthIndex] = *quadToSet[heightIndex][widthIndex];
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
 * Gibt den Wert einer Zelle zurück.
 * @param row Zeilenposition
 * @param column Spaltenposition
 * @return Wert der Zelle
 */
void SudokuGitter::setCellPermanent(unsigned int row, unsigned int column, unsigned int value) {
    cells[row][column] = value;
    cells[row][column]
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
                solvable.setCell(row, col, getCell(row, col));
        }
    }

    return solvable;
}


