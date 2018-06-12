//
// Created by Christian Keller on 11.06.18.
//

#include <random>
#include <algorithm>
#include <iostream>
#include <set>
#include "SudokuGenerator.h"


/**
 * Generiert ein neues vollständiges Sudoku.
 */
SudokuGitter SudokuGenerator::generateNew() {

    unsigned int irow = 0;

    if (gitter.getQuadWidth() == gitter.getQuadHeight() && gitter.getQuadWidth() == 3 && gitter.getElements() == 9) {
        initWithQuad();

        vector<tuple<int, int>> quadCoords(8);
        quadCoords[0] = make_tuple(0, 0);
        quadCoords[1] = make_tuple(0, 2);
        quadCoords[2] = make_tuple(0, 1);
        quadCoords[3] = make_tuple(2, 2);
        quadCoords[4] = make_tuple(2, 0);
        quadCoords[5] = make_tuple(2, 1);
        quadCoords[6] = make_tuple(1, 0);
        quadCoords[7] = make_tuple(1, 2);

        for (int index = 0; index < 8; ++index) {

            int rowIndex;
            int colIndex;
            tie(rowIndex, colIndex) = quadCoords[index];
            vector<tuple<unsigned int, unsigned int>> cellLists;

            // Falls keine Lösung für das Quad gefunden wurde erneut für dieses Quad anfangen
            vector<vector<cell *>> quadData = gitter.getQuad(rowIndex, colIndex);

            for (vector<cell *> row: quadData) {
                for (cell *cellData: row) {
                    cellLists.emplace_back(cellData->rowIndex, cellData->colIndex);
                }
            }

            while (!generateCell(cellLists)) {
                cout << "failed to set Quad" << rowIndex << ", " << colIndex << endl;

                // Falls keine Lösung für das Quad gefunden wurde erneut für dieses Quad anfangen
                vector<vector<cell *>> quadData = gitter.getQuad(rowIndex, colIndex);

                for (vector<cell *> row: quadData) {
                    for (cell *cellData: row) {
                        *cellData = cell(cellData->rowIndex, cellData->colIndex, 0);
                    }
                }
                index = index - 1;
                break;
            }

            gitter.print();
        }


            cout << "ende: " << endl;
            gitter.print();

    } else {
        initWithLine();
        irow = 1;

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
            } else {
                irow++;
            }
        }
    }

    gitter.print();

    return SudokuGitter(gitter);
}

void SudokuGenerator::initWithLine() {
    vector<cell> ziffern(elementCount);

    for (unsigned int i = 0; i < elementCount; i++)
        ziffern[i] = cell(0, 0, i + 1, true);

    //geordnet erstelle Ziffern in erste Reihe einfügen.
    gitter.cells[0] = ziffern;
    shuffle(begin(gitter.cells[0]), end(gitter.cells[0]), std::mt19937(std::random_device()()));

    gitter.print();
}

/**
 * Generiert ein neues vollständiges Sudoku.
 */
void SudokuGenerator::initWithQuad() {

    vector<cell> ziffern(elementCount);

    for (unsigned int i = 0; i < elementCount; i++)
        ziffern[i] = cell(0, 0, i + 1, true);

    //geordnet erstelle Ziffern in erste Reihe einfügen.
    //gitter.cells[0] = ziffern;
    shuffle(begin(ziffern), end(ziffern), std::mt19937(std::random_device()()));


    int middleQuadColumnIndex = gitter.getQuadWidth() / 2;
    int middleQuadRowIndex = gitter.getQuadHeight() / 2;
    auto quad = gitter.getQuad(middleQuadRowIndex, middleQuadColumnIndex);


    for (unsigned int i = 0; i < quad.size(); i++) {
        //std::cout << "\n";
        for (unsigned int u = 0; u < quad[i].size(); u++) {
            cell tmp = ziffern[i * gitter.getQuadHeight() + u];
            tmp.rowIndex = i;
            tmp.colIndex = u;
            *quad[i][u] = tmp;
        }
    }
    gitter.print();

    printCelVecValPtr(quad, "middleQuad");
}

SudokuGitter SudokuGenerator::generateNewTest() {

    //vector<cell> ziffern(elementCount);
//
    //for (unsigned int i = 0; i < elementCount; i++)
    //    ziffern[i] = cell(i + 1, true);
//
    ////geordnet erstelle Ziffern in erste Reihe einfügen.
    //gitter.cells[0] = ziffern;
    //shuffle(begin(gitter.cells[0]), end(gitter.cells[0]), std::mt19937(std::random_device()()));

    gitter.print();

    // erste Zeile wird ausgelassen
    unsigned int irow = 0;
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
 * Generiert ein neues großes (5 in einem und verbunden an den ecken) vollständiges Sudoku.
 */
SudokuGitter SudokuGenerator::generateNewBig() {
    SudokuGenerator *mitteGen = new SudokuGenerator(9);
    SudokuGitter mitte = mitteGen->generateNew();

    printCelVecValPtr(mitte.getQuad(0, 0), "LinksObenUebernehmen");
    SudokuGenerator *linksObenGen = new SudokuGenerator(9);
    linksObenGen->gitter.setQuadPermanent(0, 0, mitte.getQuad(0, 0));
    SudokuGitter linksOben = linksObenGen->generateNewTest();

    return SudokuGitter(gitter);
}

/**
 * Generiert valide Werte für die angegebene Zeile und beginnt bei der angegebenen Zelle. Dazu wird Backtracking verwendet.
 * @param row Zeilenposition
 * @param column Spaltenposition
 * @return Gibt an, ob ein gültiger Wert eingetragen werden kann (Backtracking)
 */
bool SudokuGenerator::generateCell(vector<tuple<unsigned int, unsigned int>> list) {
    unsigned int row;
    unsigned int col;
    tie(row, col) = list.back();
    list.pop_back();

    unsigned int nextRow = 0;
    unsigned int nextCol = 0;

    bool hasNext = true;
    if (list.empty())
        hasNext = false;
    else
        tie(nextRow, nextCol) = list.back();

    if (gitter.getCell(row, col).isStatic && hasNext)
        return generateCell(nextRow, nextCol);
    else if (gitter.getCell(row, col).isStatic && !hasNext)
        return true;
    vector<cell> ziffern(gitter.getElements());
    for (unsigned int i = 0; i < gitter.getElements(); i++)
        ziffern[i] = cell(0, 0, i + 1);
    shuffle(begin(ziffern), end(ziffern), std::mt19937(std::random_device()()));

    vector<cell> quad(gitter.getElements());
    vector<cell> currRow(gitter.getElements());
    vector<cell> currCol(gitter.getElements());
    vector<cell> diag(gitter.getElements());

    // Row Werte merken
    currRow = gitter.cells[row];
    // Column Werte merken
    for (unsigned int tmpRow = 0; tmpRow < gitter.getElements(); tmpRow++) {
        currCol[tmpRow] = gitter.getCell(tmpRow, col);
    }

    // Quad Werte merken
    auto quadStartRow = (row / gitter.getQuadHeight()) * gitter.getQuadHeight();
    auto quadStartCol = (col / gitter.getQuadWidth()) * gitter.getQuadWidth();

    int indexQuad = 0;
    for (auto tmpRow = quadStartRow; tmpRow < quadStartRow + gitter.getQuadHeight(); tmpRow++) {
        for (auto tmpCol = quadStartCol; tmpCol < quadStartCol + gitter.getQuadWidth(); tmpCol++) {
            quad[indexQuad] = gitter.getCell(tmpRow, tmpCol);
            indexQuad++;
        }
    }


    set<int> neighbours = {};

//    if (gitter.getQuadWidth() == gitter.getQuadHeight() && gitter.getQuadWidth() == 3) {
//        if (row == col) {
//            for (unsigned int j = 0; j < gitter.getElements(); ++j)
//                diag[j] = gitter.getCell(j, j);
//        } else if (col == (gitter.getElements() - row - 1)) {
//            for (unsigned int j = 0; j < gitter.getElements(); ++j)
//                diag[j] = gitter.getCell(j, gitter.getElements() - 1 - j);
//        }
//        for (auto val : diag)
//            neighbours.insert(val.value);
//    }

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


    for (unsigned int i = 0; i < options.size(); i++) {
        auto tmp = static_cast<unsigned int>(options[i]);

        std::cout << "###" << row + 1 << "," << col + 1 << ": Versuch " << tmp << " einzufügen. Umgebung: "
                  << std::endl;
//        SudokuGitter::printCellVec(currRow, "Row");
//        SudokuGitter::printCellVec(currCol, "Column");
        SudokuGitter::printCellVec(quad, "Quad");
        if (gitter.getQuadWidth() == gitter.getQuadHeight() && gitter.getQuadWidth() == 3 &&
            (row == col || col == (gitter.getElements() - row - 1))) {
            SudokuGitter::printCellVec(diag, "Diag");
        }
        SudokuGitter::printIntVec(options, "Options");


        gitter.cells[row][col] = cell(row, col, tmp);

        if (!hasNext || generateCell(list)) {
            return true;
        }
    }

    gitter.cells[row][col] = cell(row, col, 0);
    return false;

}

/**
 * Generiert valide Werte für die angegebene Zeile und beginnt bei der angegebenen Zelle. Dazu wird Backtracking verwendet.
 * @param row Zeilenposition
 * @param column Spaltenposition
 * @return Gibt an, ob ein gültiger Wert eingetragen werden kann (Backtracking)
 */
bool SudokuGenerator::generateCell(unsigned int row, unsigned int column) {
    unsigned int nextRow = row;
    unsigned int nextCol = column + 1;
    if (column == gitter.getElements()) {
        nextCol = 0;
        nextRow++;
    }

    if (gitter.getCell(row, column).isStatic)
        return generateCell(nextRow, nextCol);
    vector<cell> ziffern(gitter.getElements());
    for (unsigned int i = 0; i < gitter.getElements(); i++)
        ziffern[i] = cell(0, 0, i + 1);
    shuffle(begin(ziffern), end(ziffern), std::mt19937(std::random_device()()));

    vector<cell> quad(gitter.getElements());
    vector<cell> currRow(gitter.getElements());
    vector<cell> currCol(gitter.getElements());
    vector<cell> diag(gitter.getElements());

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

    if (gitter.getQuadWidth() == gitter.getQuadHeight() && gitter.getQuadWidth() == 3) {
        if (row == column) {
            for (unsigned int j = 0; j < gitter.getElements(); ++j)
                diag[j] = gitter.getCell(j, j);
        } else if (row == (gitter.getElements() - column)) {
            for (unsigned int j = 0; j < gitter.getElements(); ++j)
                diag[j] = gitter.getCell(j, gitter.getElements() - j);
        }
        for (auto val : diag)
            neighbours.insert(val.value);
    }

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


    for (unsigned int i = 0; i < options.size(); i++) {
        auto tmp = static_cast<unsigned int>(options[i]);
/*
        std::cout << "###" << row + 1 << "," << column + 1 << ": Versuch " << tmp << " einzufügen. Umgebung: "
                  << std::endl;
        SudokuGitter::printCellVec(currRow, "Row");
        SudokuGitter::printCellVec(currCol, "Column");
        SudokuGitter::printCellVec(quad, "Quad");
        if (gitter.getQuadWidth() == gitter.getQuadHeight() && gitter.getQuadWidth() == 3 &&
            (row == column || row == (gitter.getElements() - column))) {
            SudokuGitter::printCellVec(diag, "Diag");
        }
        SudokuGitter::printIntVec(options, "Options");

*/
        gitter.cells[row][column] = cell(row, column, tmp);

        if ((column == gitter.getElements() - 1) || generateCell(nextRow, nextCol)) {
            return true;
        }
    }

    gitter.cells[row][column] = cell(row, column, 0);
    return false;
}


/**
 * Reihe voller 0er schreiben.
 * @param row zu beschreibende Reihe
 */
void SudokuGenerator::zerowRow(unsigned int row) {
    for (unsigned int icol = 0; icol < elementCount; ++icol) {
        if (!gitter.getCell(row, icol).isStatic)
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