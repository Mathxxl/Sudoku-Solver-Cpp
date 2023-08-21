//
// Created by PC GAMER on 10/08/2023.
//

#ifndef SUDOKU_SUDOKUSOLVER_H
#define SUDOKU_SUDOKUSOLVER_H

#include "Sudoku.h"
#include <vector>

class SudokuSolver{
public:
    void Solve(const Sudoku& sud, bool print = false);

    SudokuSolver();
    ~SudokuSolver();

    void displaySolution();
    [[nodiscard]] bool isSolved() const {return solved;};

private:
    //Attributes
    Sudoku sudoku;
    int numberBasePoints;
    std::vector<Point> points;
    bool solved;
    bool printProcess;

    //Setup
    std::vector<Point> getPointsInOrder();
    int countPossibilities(int array[9][9][9],int i, int j);
    static Point getMinPossibility(int count[9][9]);

    //Solving
    bool solveValue(int i);
};

#endif //SUDOKU_SUDOKUSOLVER_H
