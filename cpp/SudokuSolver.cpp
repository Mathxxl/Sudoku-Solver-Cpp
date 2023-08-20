//
// Created by PC GAMER on 10/08/2023.
//

#include "SudokuSolver.h"
#include <iostream>

SudokuSolver::SudokuSolver() {}

SudokuSolver::~SudokuSolver() {}

void SudokuSolver::Solve(Sudoku sud) {
        sudoku = sud;

        points = getPointsInOrder();
        std::cout << "points : " << std::endl;
        for(Point current : points){
            std::cout << "(" << current.x << "," << current.y << ") ";
        }

        if(points.empty()) {
            std::cout << "Already Solved" << std::endl;
            return;
        }

        std::cout << std::endl;
        solved = solveValue(0);
        if(solved){
            std::cout << "Solved" << std::endl;
        } else {
            std::cout << "Unsolvable" << std::endl;
        }

}

std::vector<Point> SudokuSolver::getPointsInOrder() {
    std::vector<Point> toReturn;
    numberBasePoints = 0;

    //Set array of possibilities
    std::cout << "Set array of possibilities" << std::endl;

    int possibilities[9][9][9];
    for(int i =0; i < 9; i++){
        for(int j=0; j<9;j++){
            if(sudoku.numbers[i][j] > 0) numberBasePoints++;
            for(int k = 0; k < 9; k++){
                if(sudoku.numbers[i][j] <= 0){
                    possibilities[i][j][k] = k+1;
                } else {
                    possibilities[i][j][k] = 0;
                }
            }
        }
    }

    std::cout << "base points = " << numberBasePoints << std::endl;

    //Removals to get actual possibilities
    std::cout << "Removals to get actual possibilities" << std::endl;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j<9;j++){
                int value = sudoku.numbers[i][j];
                if(value <= 0) continue;

                //std::cout << "Eliminate " << value << " for line " << i << std::endl;
                //eliminate line
                for(int x = 0; x < 9; x++){
                    if(x == j) continue;
                    possibilities[i][x][value-1] = 0;

                }

                //std::cout << "Eliminate " << value << " for column " << j << std::endl;
                //eliminate column
                for(int y = 0; y < 9; y++){
                    if(y == i) continue;
                    possibilities[y][j][value-1] = 0;

                }

                //eliminate bloc
                int origX = sudoku.getBlocOriginX(i);
                int origY = sudoku.getBlocOriginY(j);

                //std::cout << "Eliminate " << value  << " from bloc " << origX << ":" << origY << std::endl;

                for(int x = 0; x < 3; x++){
                    for(int y = 0; y < 3; y++){
                        if(origX + x == i && origY + y == j) continue;
                        possibilities[origX + x][origY + y][value-1] = 0;
                    }
                }
        }
    }

    //Count possibilities
    std::cout << "Count possibilities" << std::endl;

    int count[9][9];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j< 9; j++){
            count[i][j] = countPossibilities(possibilities, i, j);
            //std::cout << "Point (" << i << "," << j << ") has " << count[i][j] << " possibilities" << std::endl;
         }
    }

    std::cout << "Count array : " << std::endl;
    for(int i = 0; i < 9; i++){
        for(int j = 0 ; j < 9; j++){
            std::cout << count[i][j] << " ";
        }
        std::cout << std::endl;
    }


    //Set vector of min
    std::cout << "Set vector of min" << std::endl;

    int totalN = 81 - numberBasePoints;
    std::cout << "total points = " << totalN << std::endl;
    for(int a = 0; a < totalN; a++){
        Point min = getMinPossibility(count);

        //Set possible values
        for(auto& val : possibilities[min.x][min.y]){
            if(val > 0) min.possibleValues.push_back(val);
        }

        toReturn.push_back(min);

        std::cout << "Add min Point (" << min.x << "," << min.y << ") with " << count[min.x][min.y] << " possibilities" << std::endl;

        //remove min value
        count[min.x][min.y] = 101;
    }

    return toReturn;


}

int SudokuSolver::countPossibilities(int array[9][9][9], int i, int j) {
    auto list = array[i][j];
    int count = 0;
    std::cout << "Point (" << i << "," << j << ") = " << sudoku.numbers[i][j] << " possibilities are : ";
    for(int k = 0; k < 9; k++){
        int value = list[k];
        if(value != 0)  std::cout << value;
        if(value > 0) count++;
    }
    std::cout << " ; count = " << count << std::endl;
    return count;
}

Point SudokuSolver::getMinPossibility(int (*count)[9]) {
    Point toReturn;
    int min = 100;

    for(int i =0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            int value = count[i][j];
            if(value <= 0) continue;
            if(value < min){
                min = value;
                toReturn.x = i;
                toReturn.y = j;
            }
        }
    }
    return toReturn;
}

bool SudokuSolver::solveValue(int i) {
    if(i == points.size()) {
        std::cout << "finish" << std::endl;
        return true;
    }

    //std::cout << " i = " << i << std::endl;

    Point p = points[i];

    int x = p.x;
    int y = p.y;
    int N = p.possibleValues.size();

    //std::cout << "Checking values for Point (" << x << "," << y << ") with " << N << " possibilities" << std::endl;

    if(N <= 0) return false;

    for(int k = 0; k < N; k++){
        int val = p.possibleValues[k];

        sudoku.numbers[x][y] = val;

        //std::cout << "Test with value " << val << std::endl;
        //std::cout << "line valid : " << (sudoku.lineIsValid(x) ? "true" : "false") << " ; column valid : " << (sudoku.columnIsValid(y)? "true" : "false") << " ; bloc valid : " << (sudoku.blocIsValid(x,y)? "true" : "false") << std::endl;

        if(sudoku.lineIsValid(x) && sudoku.columnIsValid(y) && sudoku.blocIsValid(x, y)){
            //std::cout << "valid" << std::endl;
            //std::cout << " i+1 = " << i+1 << std::endl;
            if(solveValue(i+1)){
                //std::cout << "next value valid" << std::endl;
                return true;
            } else {
                //std::cout << "next value invalid" << std::endl;
                //std::cout << "on remonte à " << i << std::endl;
            }
        } else {
            //sudoku.display();
        }
    }

    sudoku.numbers[x][y] = 0;
    return false;
}

void SudokuSolver::displaySolution() {
    sudoku.display();
}