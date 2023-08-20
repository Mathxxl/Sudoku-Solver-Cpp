//
// Created by PC GAMER on 20/08/2023.
//

#ifndef SUDOKU_POINT_H
#define SUDOKU_POINT_H

#include <vector>

class Point{
public:
    int x;
    int y;
    std::vector<int> possibleValues;
};

#endif //SUDOKU_POINT_H
