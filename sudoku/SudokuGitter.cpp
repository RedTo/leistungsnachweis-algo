//
// Created by Christian Keller on 26.03.18.
//

#include <iostream>
#include <random>
#include <algorithm>
#include <set>
#include <list>
#include <math.h>
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
 * Generiert ein neues vollständiges Sudoku.
 */
void SudokuGitter::generateNew() {

    vector<cell> ziffern(getElements());

    for (unsigned int i = 0; i < getElements(); i++)
        ziffern[i] = cell(i + 1, true);

    //geordnet erstelle Ziffern in erste Reihe einfügen.
    cells[0] = ziffern;
    shuffle(begin(cells[0]), end(cells[0]), std::mt19937(std::random_device()()));

    print();

    // erste Zeile wird ausgelassen
    unsigned int irow = 1;
    while (irow < getElements()) {
        // Bei groeseren sudokus kann es tatsechlich auch mal keine loesung fuer eine Reihe geben -> vorherige Reihe neu machen
        if (!generateCell(irow, 0)) {
            // Todo: Reicht es immer nur eine reihe zurueck zu gehen?
            unsigned int hadErrorsInRow = hadErrorInRow(irow);
            errorInRow.push_back(irow);

            // Bis zum ruecksprungpunkt 0er einsetzen (aktuelle row ist schon 0)
            unsigned int jumpBackToRow = irow - 1;
            while (irow > jumpBackToRow) {
                irow--;
                zerowRow(irow);
            }

            cout << "REDO last row! There is no solution for this row. Errors in this Row: " << hadErrorsInRow + 1
                 << "\n";
            print();
        } else {
            for (int i = 0; i < getElements(); ++i) {
                cells[irow][i].isStatic = true;
            }
            irow++;
            print();
        }
    }

}

/**
 * Generiert valide Werte für die angegebene Zeile und beginnt bei der angegebenen Zelle. Dazu wird Backtracking verwendet.
 * @param row Zeilenposition
 * @param column Spaltenposition
 * @return Gibt an, ob ein gültiger Wert eingetragen werden kann (Backtracking)
 */
bool SudokuGitter::generateCell(unsigned int row, unsigned int column) {
    vector<SudokuGitter::cell> ziffern(getElements());
    for (unsigned int i = 0; i < getElements(); i++)
        ziffern[i] = cell(i + 1);
    shuffle(begin(ziffern), end(ziffern), std::mt19937(std::random_device()()));

    vector<SudokuGitter::cell> quad(getElements());
    vector<SudokuGitter::cell> currRow(getElements());
    vector<SudokuGitter::cell> currCol(getElements());

    // Row Werte merken
    currRow = cells[row];
    // Column Werte merken
    for (unsigned int tmpRow = 0; tmpRow < getElements(); tmpRow++) {
        currCol[tmpRow] = getCell(tmpRow, column);
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
        neighbours.insert(val.value);
    }
    for (auto val : currCol) {
        neighbours.insert(val.value);
    }
    for (auto val : quad) {
        neighbours.insert(val.value);
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


        cells[row][column] = cell(tmp);

        if ((column == getElements() - 1) || generateCell(nextRow, nextCol)) {
            return true;
        }
    }

    cells[row][column] = cell(0);
    return false;
}

/**
 * Gibt den Wert einer Zelle zurück.
 * @param row Zeilenposition
 * @param column Spaltenposition
 * @return Wert der Zelle
 */
SudokuGitter::cell SudokuGitter::getCell(unsigned int row, unsigned int column) {
    return cells[row][column];
}

/**
 * Gibt den Wert einer Zelle zurück.
 * @param row Zeilenposition
 * @param column Spaltenposition
 * @return Wert der Zelle
 */
void SudokuGitter::setCell(unsigned int row, unsigned int column, cell value) {
    cells[row][column] = value;
}

/**
 * Gibt das Sudoku auf der Commandline aus.
 */
void SudokuGitter::print() {
    for (unsigned int irow = 0; irow < getElements(); ++irow) {
        std::cout << " ";
        for (unsigned int icol = 0; icol < getElements(); ++icol) {
            std::cout << cells[irow][icol].value << " ";
        }
        std::cout << std::endl; // << "--" << std::endl;
    }
}

/**
 * Reihe voller 0er schreiben.
 * @param row zu beschreibende Reihe
 */
void SudokuGitter::zerowRow(unsigned int row) {
    for (unsigned int icol = 0; icol < getElements(); ++icol) {
        cells[row][icol].value = 0;
    }
}

/**
 * Gibt einen vector auf der Commandline aus.
 * @param vec auszugebende Vektor
 * @param name Name des Vektors
 */
void SudokuGitter::printVec(vector<cell> vec, string name) {
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
void SudokuGitter::printVec(vector<unsigned int> vec, string name) {
    // Print Original Vector
    std::cout << name << ": ";
    for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << " " << vec[i];

    std::cout << std::endl;

}

/**
 * Suche wie oft ist schon ein fehler in der Zeile aufgetreten
 * @param row zeile welche geprüft werden soll
 */
unsigned int SudokuGitter::hadErrorInRow(unsigned int row) {
    unsigned int found = 0;

    for (std::list<int>::const_iterator iterator = errorInRow.begin(), end = errorInRow.end();
         iterator != end; ++iterator) {
        if (*iterator == row)
            found++;
    }

    return found;
}

SudokuGitter SudokuGitter::getSolvable() {
    SudokuGitter solvable = SudokuGitter(getElements());

    int globalElements = getElements() * getElements();

    vector<unsigned int> permutation(globalElements);

    for (int i = 0; i < globalElements; i++) {
        if (i < floor(globalElements * 0.35))
            permutation[i] = 1;
        else
            permutation[i] = 0;
    }

    shuffle(begin(permutation), end(permutation), std::mt19937(std::random_device()()));

    for (unsigned int row = 0; row < getElements(); row++) {
        for (unsigned int col = 0; col < getElements(); col++) {
            if (permutation[row * getElements() + col] == 1)
                solvable.setCell(row, col, cell(getCell(row, col), true));
        }
    }

    return solvable;
}


