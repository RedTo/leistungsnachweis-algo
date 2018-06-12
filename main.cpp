#include <iostream>
#include "SudokuGitter.h"
#include "visual/ClassicSudokuVisualizer.h"
#include "generate/SudokuGenerator.h"

int main() {
    int elements = 9;
    SudokuGenerator generator = SudokuGenerator(elements);
    SudokuGitter gitter = generator.generateNew();
    //SudokuGitter gitter = generator.generateNewBig();

    //disable cout by setting failbit, remove this line or call std::cout.clear()
    //std::cout.setstate(std::ios_base::failbit);
    std::cout << "###### Ende ######" << std::endl;
    gitter.print();
    std::cout << "Zeile 1 Spalte 0: " << gitter.getCellValue(1, 0) << std::endl;

    int countZero = 0;
    for (int row = 0; row < elements; row++) {
        for (int col = 0; col < elements; col++) {
            if (gitter.getCellValue(row, col) == 0)
                countZero++;
        }
    }

    std::cout << "Anzahl 0: " << countZero << std::endl;
    //gitter.setDifficulty(0.6);
    SudokuGitter solvable = gitter.getSolvable();
    std::cout << "##### Solvable #######" << std::endl;
    solvable.print();
    std::cout << "##### solved Sudoku #######" << std::endl;
    //SudokuGitter::solve(solvable);

    ClassicSudokuVisualizer visualizer = ClassicSudokuVisualizer(gitter);
    visualizer.createHTML("output/gitter.html");

    return 0;
}