#include "ClassicSudokuVisualizer.h"


ClassicSudokuVisualizer::ClassicSudokuVisualizer(SudokuGitter gitter) : gitter(gitter) {

}

const std::string ClassicSudokuVisualizer::createBorderBottomStyle() {
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

const std::string ClassicSudokuVisualizer::createBorderTopStyle() {
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

const std::string ClassicSudokuVisualizer::createBorderLeftStyle() {
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

const std::string ClassicSudokuVisualizer::createBorderRightStyle() {
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

const std::string ClassicSudokuVisualizer::createStyle() {
    std::string style = "";
    style.append(createBorderBottomStyle());
    style.append(createBorderTopStyle());
    style.append(createBorderRightStyle());
    style.append(createBorderLeftStyle());

    return style;
}

const std::string ClassicSudokuVisualizer::createCells() {
    unsigned int size = gitter.getElements();

    SudokuGitter solvable = gitter.getSolvable();

    std::string cells = "";

    unsigned int counter = 0;
    for (unsigned int row = 0; row < size; row++) {
        cells.append("<tr>");
        for (unsigned int col = 0; col < size; col++) {
            unsigned int num = solvable.getCell(row, col).value;
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
        cells.append("</tr>");
    }

    return cells;
}

void ClassicSudokuVisualizer::createHTML(std::string name) {
    std::string style = createStyle();
    std::string cells = createCells();

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

//int main() {
//    SudokuGitter gitter = SudokuGitter(9);
//    gitter.generateNew();
//
//    ClassicSudokuVisualizer visualizer = ClassicSudokuVisualizer(gitter);
//    visualizer.createHTML("index.html");
//}


