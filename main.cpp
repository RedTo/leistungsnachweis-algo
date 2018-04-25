#include <iostream>
#include "SudokuGitter.h"

int main() {
    int elements = 6;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    std::cout << "###### Ende ######" << std::endl;
    gitter.print();
    std::cout << "Zeile 1 Spalte 0: " << gitter.getCell(1, 0) << std::endl;

    int countZero = 0;
    for (int row = 0; row < elements; row++) {
        for (int col = 0; col < elements; col++) {
            if (gitter.getCell(row, col) == 0)
                countZero++;
        }
    }

    std::cout << "Anzahl 0: " << countZero;

    return 0;
}