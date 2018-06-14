#include <tuple>
#include "BigSudokuVisualizer.h"
#include "../generate/SudokuGenerator.h"


BigSudokuVisualizer::BigSudokuVisualizer(tuple<SudokuGitter, SudokuGitter> bigGitter) : bigGitter(bigGitter) {

}

const std::string BigSudokuVisualizer::createBorderBottomStyle(SudokuGitter gitter) {
    unsigned int size = gitter.getElements();
    unsigned int h = gitter.getQuadHeight() - 1;
    std::string border_bottom = "";
    while (h < size) {
        unsigned int iStart = h * size;
        for (unsigned int i = iStart; i < iStart + size; i++) {
            border_bottom.append("#cell-");
            border_bottom.append(std::to_string(i));
            border_bottom.append(", ");
        }
        h += gitter.getQuadHeight();
    }
    border_bottom = border_bottom.substr(0, border_bottom.length() - 2);
    border_bottom.append(" { border-bottom: 2px solid #000; } ");

    return border_bottom;
}

const std::string BigSudokuVisualizer::createBorderTopStyle(SudokuGitter gitter) {
    unsigned int size = gitter.getElements();
    unsigned int h = 0;
    std::string border_top = "";
    while (h < size) {
        unsigned int iStart = h * size;
        for (unsigned int i = iStart; i < iStart + size; i++) {
            border_top.append("#cell-");
            border_top.append(std::to_string(i));
            border_top.append(", ");
        }
        h += gitter.getQuadHeight();
    }
    border_top = border_top.substr(0, border_top.length() - 2);
    border_top.append(" { border-top: 2px solid #000; } ");
    return border_top;
}

const std::string BigSudokuVisualizer::createBorderLeftStyle(SudokuGitter gitter) {
    unsigned int size = gitter.getElements();
    unsigned int elements = size * size;
    std::string border_left = "";
    for (unsigned int i = 0; i < elements; i += gitter.getQuadWidth()) {
        border_left.append("#cell-");
        border_left.append(std::to_string(i));
        border_left.append(", ");
    }
    border_left = border_left.substr(0, border_left.length() - 2);
    border_left.append(" { border-left: 2px solid #000; } ");
    return border_left;
}

const std::string BigSudokuVisualizer::createBorderRightStyle(SudokuGitter gitter) {
    unsigned int size = gitter.getElements();
    unsigned int elements = size * size;
    std::string border_right = "";
    for (unsigned int i = gitter.getQuadWidth() - 1; i < elements; i += gitter.getQuadWidth()) {
        border_right.append("#cell-");
        border_right.append(std::to_string(i));
        border_right.append(", ");
    }
    border_right = border_right.substr(0, border_right.length() - 2);
    border_right.append(" { border-right: 2px solid #000; } ");
    return border_right;
}

const std::string BigSudokuVisualizer::createStyle(SudokuGitter gitter) {
    std::string style = "";
    style.append(createBorderBottomStyle(gitter));
    style.append(createBorderTopStyle(gitter));
    style.append(createBorderRightStyle(gitter));
    style.append(createBorderLeftStyle(gitter));

    return style;
}

const std::string BigSudokuVisualizer::createCells(SudokuGitter gitter1, SudokuGitter gitter2) {
    unsigned int size = gitter1.getElements();
    unsigned int colspan_size = size - gitter1.getQuadWidth();
    unsigned int rowspan_size = size - gitter1.getQuadHeight();

    std::string cells = "";
    std::string colspan = "";
    colspan.append("<td style='border: none' colspan='");
    colspan.append(std::to_string(colspan_size));
    colspan.append("'></td>");

    unsigned int counter = 0;
    unsigned int counter2 = 0;
    for (unsigned int row = 0; row < rowspan_size; row++) {
        cells.append("<tr>");
        for (unsigned int col = 0; col < size; col++) {
            unsigned int num = gitter1.getCell(row, col).value;
            if (num > 0) {
                cells.append("<td><input id='cell-");
                cells.append(std::to_string(counter));
                cells.append("' type='text' value='");
                cells.append(std::to_string(num));
                cells.append("' disabled></td>");
            } else {
                cells.append("<td><input id='cell-");
                cells.append(std::to_string(counter));
                cells.append("' type='text'></td>");
            }
            counter++;
        }
        cells.append(colspan);
        cells.append("</tr>");
    }

    for(unsigned int times = 0; times < gitter1.getQuadHeight(); times++){
        cells.append("<tr>");
        for (unsigned int col = 0; col < size; col++) {
            unsigned int num = gitter1.getCell(times + rowspan_size, col).value;
            if (num > 0) {
                cells.append("<td><input id='cell-");
                cells.append(std::to_string(counter));
                cells.append("' type='text' value='");
                cells.append(std::to_string(num));
                cells.append("' disabled></td>");
            } else {
                cells.append("<td><input id='cell-");
                cells.append(std::to_string(counter));
                cells.append("' type='text'></td>");
            }
            counter++;
        }
        counter2 += gitter2.getQuadWidth();
        unsigned int col = gitter2.getQuadWidth();
        if(col == size){
            col--;
        }
        for (col; col < size; col++) {
            unsigned int num = gitter2.getCell(times, col).value;
            if (num > 0) {
                cells.append("<td><input id='cell-");
                cells.append(std::to_string(counter2));
                cells.append("' type='text' value='");
                cells.append(std::to_string(num));
                cells.append("' disabled></td>");
            } else {
                cells.append("<td><input id='cell-");
                cells.append(std::to_string(counter2));
                cells.append("' type='text'></td>");
            }
            counter2++;
        }
        cells.append("</tr>");
    }
    for (unsigned int row = gitter2.getQuadHeight(); row < size; row++) {
        cells.append("<tr>");
        cells.append(colspan);
        for (unsigned int col = 0; col < size; col++) {
            unsigned int num = gitter2.getCell(row, col).value;
            if (num > 0) {
                cells.append("<td><input id='cell-");
                cells.append(std::to_string(counter2));
                cells.append("' type='text' value='");
                cells.append(std::to_string(num));
                cells.append("' disabled></td>");
            } else {
                cells.append("<td><input id='cell-");
                cells.append(std::to_string(counter2));
                cells.append("' type='text'></td>");
            }
            counter2++;
        }
        cells.append("</tr>");
    }
    return cells;
}

void BigSudokuVisualizer::createHTML(std::string name) {
    SudokuGitter gitter1 = std::get<0>(bigGitter);
    SudokuGitter gitter2 = std::get<1>(bigGitter);

    std::string style = createStyle(gitter1);
    std::string cells = createCells(gitter1, gitter2);

    std::string html = html_template;

    size_t index = 0;
    index = html.find("###STYLE###", index);
    html = html.replace(index, 11, style);
    index = 0;
    index = html.find("###CELLS###", index);
    html = html.replace(index, 11, cells);

    ofstream htmlFile;
    htmlFile.open(name);
    htmlFile << html;
    htmlFile.close();
}
