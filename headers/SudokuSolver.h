//
// Created by PC GAMER on 10/08/2023.
//

#ifndef SUDOKU_SUDOKUSOLVER_H
#define SUDOKU_SUDOKUSOLVER_H

#include "Sudoku.h"
#include <vector>

class SudokuSolver{
public:
    void Solve(Sudoku sud = nullptr);

    SudokuSolver();
    ~SudokuSolver();

    void displaySolution();
    bool isSolved() const {return solved;};

private:
    //Attributes
    Sudoku sudoku;
    int numberBasePoints;
    std::vector<Point> points;
    bool solved;

    //Setup
    std::vector<Point> getPointsInOrder();
    int countPossibilities(int array[9][9][9],int i, int j);
    Point getMinPossibility(int count[9][9]);

    //Solving
    bool solveValue(int i);
};

#endif //SUDOKU_SUDOKUSOLVER_H
