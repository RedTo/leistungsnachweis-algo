//
// Created by Christian Keller on 11.06.18.
//

#include <random>
#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>
#include "SudokuGenerator.h"


/**
 * Generiert ein neues vollständiges Sudoku.
 */
SudokuGitter SudokuGenerator::generateNew() {
    vector<cell> ziffern(elementCount);

    for (unsigned int i = 0; i < elementCount; i++)
        ziffern[i] = cell(i + 1, true);

    //geordnet erstelle Ziffern in erste Reihe einfügen.
    gitter.cells[0] = ziffern;
    shuffle(begin(gitter.cells[0]), end(gitter.cells[0]), std::mt19937(std::random_device()()));

    gitter.print();

    return generateNewFromRow(1);
}

/**
 * Generiert ein neues Sudoku.
 */
SudokuGitter SudokuGenerator::generateNewFromRow(unsigned int startRow) {
    unsigned int irow = startRow;
    while (irow < elementCount) {
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
            gitter.print();
        } else {
            irow++;
            gitter.print();
        }
    }
    return SudokuGitter(gitter);
}

/**
 * Generiert ein neues großes (2 in einem und verbunden an den ecken) vollständiges Sudoku.
 */
tuple<SudokuGitter, SudokuGitter> SudokuGenerator::generateNewBig() {
    SudokuGenerator *untenRechtsGen = new SudokuGenerator(elementCount);
    SudokuGitter untenRechts = untenRechtsGen->generateNew();

    SudokuGenerator *linksObenGen = new SudokuGenerator(elementCount);
    linksObenGen->gitter.setQuadPermanent(0, 0,
                                          untenRechts.getQuad(gitter.getQuadHeight() - 1, gitter.getQuadWidth() - 1));
    SudokuGitter linksOben = linksObenGen->generateNewFromRow(0);

    //printCelVecValPtr(untenRechts.getQuad(gitter.getQuadHeight() - 1, gitter.getQuadWidth() - 1), "LinksObenUebernehmen");

    return tuple<SudokuGitter, SudokuGitter>(untenRechts, linksOben);
}

/**
 * Generiert valide Werte für die angegebene Zeile und beginnt bei der angegebenen Zelle. Dazu wird Backtracking verwendet.
 * @param row Zeilenposition
 * @param column Spaltenposition
 * @return Gibt an, ob ein gültiger Wert eingetragen werden kann (Backtracking)
 */
bool SudokuGenerator::generateCell(unsigned int row, unsigned int column) {
    vector<cell> ziffern(gitter.getElements());
    for (unsigned int i = 0; i < gitter.getElements(); i++)
        ziffern[i] = cell(i + 1);
    shuffle(begin(ziffern), end(ziffern), std::mt19937(std::random_device()()));

    vector<cell> quad(gitter.getElements());
    vector<cell> currRow(gitter.getElements());
    vector<cell> currCol(gitter.getElements());

    // Row Werte merken
    currRow = gitter.cells[row];
    // Column Werte merken
    for (unsigned int tmpRow = 0; tmpRow < gitter.getElements(); tmpRow++) {
        currCol[tmpRow] = gitter.getCell(tmpRow, column);
    }

    // Quad Werte merken
    auto quadStartRow = (row / gitter.getQuadHeight()) * gitter.getQuadHeight();
    auto quadStartCol = (column / gitter.getQuadWidth()) * gitter.getQuadWidth();

    int indexQuad = 0;
    for (auto tmpRow = quadStartRow; tmpRow < quadStartRow + gitter.getQuadHeight(); tmpRow++) {
        for (auto tmpCol = quadStartCol; tmpCol < quadStartCol + gitter.getQuadWidth(); tmpCol++) {
            quad[indexQuad] = gitter.getCell(tmpRow, tmpCol);
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

    for (unsigned int i = 1; i <= gitter.getElements(); i++)
        values.insert(i);

    vector<unsigned int> options;
    set_difference(values.begin(), values.end(), neighbours.begin(), neighbours.end(),
                   inserter(options, options.begin()));

    shuffle(begin(options), end(options), std::mt19937(std::random_device()()));

    unsigned int nextRow = row;
    unsigned int nextCol = column + 1;
    if (column == gitter.getElements()) {
        nextCol = 0;
        nextRow++;
    }

    for (unsigned int i = 0; i < options.size(); i++) {
        auto tmp = static_cast<unsigned int>(options[i]);

        std::cout << "###" << row + 1 << "," << column + 1 << ": Versuch " << tmp << " einzufügen. Umgebung: "
                  << std::endl;
        SudokuGitter::printCellVec(currRow, "Row");
        SudokuGitter::printCellVec(currCol, "Column");
        SudokuGitter::printCellVec(quad, "Quad");
        SudokuGitter::printIntVec(options, "Options");


        //gitter.cells[row][column] = cell(tmp);
        gitter.setCell(row, column, tmp);

        if ((column == gitter.getElements() - 1) || generateCell(nextRow, nextCol)) {
            return true;
        }
    }

    // Wenn feste variable gehe immer weiter da ist nix zu tun
    if (gitter.cells[row][column].isStatic && generateCell(nextRow, nextCol)) {
        return true;
    }

    // Fehler. Keine Option vorhanden um die Zelle zu setzen
    gitter.cells[row][column] = cell(0);
    return false;
}


/**
 * Reihe voller 0er schreiben.
 * @param row zu beschreibende Reihe
 */
void SudokuGenerator::zerowRow(unsigned int row) {
    for (unsigned int icol = 0; icol < elementCount; ++icol) {
        gitter.setCell(row, icol, 0);
    }
}

/**
 * Gibt einen vector auf der Commandline aus.
 * @param vec auszugebende Vektor
 * @param name Name des Vektors
 */
void SudokuGenerator::printCelVecValPtr(vector<vector<cell *>> vec, string name) {
    // Print Original Vector
    std::cout << name << ": ";
    for (unsigned int i = 0; i < vec.size(); i++) {
        std::cout << "\n";
        for (unsigned int u = 0; u < vec[i].size(); u++)
            std::cout << " " << vec[i][u]->value;
    }

    std::cout << std::endl;

}

/**
 * Suche wie oft ist schon ein fehler in der Zeile aufgetreten
 * @param row zeile welche geprüft werden soll
 */
unsigned int SudokuGenerator::hadErrorInRow(unsigned int row) {
    unsigned int found = 0;

    for (std::list<int>::const_iterator iterator = errorInRow.begin(), end = errorInRow.end();
         iterator != end; ++iterator) {
        if (*iterator == row)
            found++;
    }

    return found;
}