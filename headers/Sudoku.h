//
// Created by PC GAMER on 09/08/2023.
//

#ifndef SUDOKU_SUDOKU_H
#define SUDOKU_SUDOKU_H

#include "Point.h"

class Sudoku{
public:

    int numbers[9][9];

    Sudoku();
    Sudoku(int num[9][9]);
    ~Sudoku();

    void display();
    bool lineIsValid(unsigned int idx);
    bool columnIsValid(unsigned int idx);
    bool blocIsValid(int x, int y);
    int getBlocOriginX(int x);
    int getBlocOriginY(int y);

private:

};

#endif //SUDOKU_SUDOKU_H
