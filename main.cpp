#include <iostream>
#include <tuple>
#include "SudokuGitter.h"
#include "visual/ClassicSudokuVisualizer.h"
#include "generate/SudokuGenerator.h"
#include "visual/BigSudokuVisualizer.h"

SudokuGitter mainClassicSudoku(int elements){
    SudokuGenerator generator = SudokuGenerator(elements);
    SudokuGitter gitter = generator.generateNew();

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
    return solvable;
}

void visualizeClassicSudoku(SudokuGitter gitter){
    ClassicSudokuVisualizer visualizer = ClassicSudokuVisualizer(gitter);
    visualizer.createHTML("output/classic.html");
}

tuple<SudokuGitter, SudokuGitter> mainBigSudoku(int elements){
    SudokuGenerator generator = SudokuGenerator(elements);
    tuple<SudokuGitter, SudokuGitter> bigGitter = generator.generateNewBig();
    SudokuGitter gitter1 = std::get<0>(bigGitter);
    SudokuGitter gitter2 = std::get<1>(bigGitter);
    gitter1 = gitter1.getSolvable();
    gitter2 = gitter2.getSolvable();
    bigGitter = std::make_tuple(gitter1, gitter2);
    return bigGitter;
};

void visualizeBigSudoku(tuple<SudokuGitter, SudokuGitter> bigGitter){
    BigSudokuVisualizer visualizer = BigSudokuVisualizer(bigGitter);
    visualizer.createHTML("output/big.html");
}

int main() {
    int elements = 9;
    SudokuGitter gitter = mainClassicSudoku(elements);
    visualizeClassicSudoku(gitter);

    tuple<SudokuGitter, SudokuGitter> bigGitter = mainBigSudoku(elements);
    visualizeBigSudoku(bigGitter);
}