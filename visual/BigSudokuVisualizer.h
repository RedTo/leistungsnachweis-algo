#ifndef SUDOKU_BIGSUDOKUVISUALIZER_H
#define SUDOKU_BIGSUDOKUVISUALIZER_H

#include <random>
#include <string>
#include <iostream>
#include <fstream>
#include "../SudokuGitter.h"

class BigSudokuVisualizer {
private:
    tuple<SudokuGitter,SudokuGitter> bigGitter;
    std::string html_template = "<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>HTML Sudoku Board</title><link href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css' rel='stylesheet'><style type='text/css'>html, body { background-color: #FAFAFA } table { border: 2px solid #000000; } td { border: 1px solid #000000; text-align: center; vertical-align: middle; } input { color: #000000; padding: 0; border: 0; text-align: center; width: 48px; height: 48px; font-size: 24px; background-color: #FFFFFF; outline: none;} input:disabled { background-color: #EEEEEE; } ###STYLE###</style></head><body><div class='container'><h1>HTML Big-Sudoku Board</h1><table id='grid' style='border: none'>###CELLS###</table></div></body></html>";

public:
    explicit BigSudokuVisualizer(tuple<SudokuGitter,SudokuGitter> bigGitter);
    void createHTML(std::string path);

private:
    const std::string createStyle(SudokuGitter gitter);
    const std::string createCells(SudokuGitter gitter1, SudokuGitter gitter2);
    const std::string createBorderBottomStyle(SudokuGitter gitter);
    const std::string createBorderTopStyle(SudokuGitter gitter);
    const std::string createBorderRightStyle(SudokuGitter gitter);
    const std::string createBorderLeftStyle(SudokuGitter gitter);
};

#endif //SUDOKU_BIGSUDOKUVISUALIZER_H
