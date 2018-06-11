#include <iostream>
#include "SudokuGitter.h"
#include "visual/ClassicSudokuVisualizer.h"

int main() {
    int elements = 9;
    SudokuGitter gitter = SudokuGitter(elements);
    gitter.generateNew();

    //disable cout by setting failbit, remove this line or call std::cout.clear()
    //std::cout.setstate(std::ios_base::failbit);
    std::cout << "###### Ende ######" << std::endl;
    gitter.print();
    std::cout << "Zeile 1 Spalte 0: " << gitter.getCell(1, 0).value << std::endl;

    int countZero = 0;
    for (int row = 0; row < elements; row++) {
        for (int col = 0; col < elements; col++) {
            if (gitter.getCell(row, col).value == 0)
                countZero++;
        }
    }

    std::cout << "Anzahl 0: " << countZero << std::endl;
    gitter.setDifficulty(0.6);
    SudokuGitter solvable = gitter.getSolvable();
    std::cout << "##### Solvable #######" << std::endl;
    solvable.print();
    std::cout << "##### solved Sudoku #######" << std::endl;
    //SudokuGitter::solve(solvable);


    ClassicSudokuVisualizer visualizer = ClassicSudokuVisualizer(gitter);
    visualizer.createHTML("output/sudoku.html");

    return 0;
}