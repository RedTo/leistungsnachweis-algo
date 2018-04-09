#include <iostream>
#include "SudokuGitter.h"

int main() {
    SudokuGitter gitter = SudokuGitter(7);
    gitter.generateNew();
    gitter.print();
    std::cout << "Zeile 1 Spalte 0: " << gitter.getCell(1, 0) << std::endl;
    return 0;
}