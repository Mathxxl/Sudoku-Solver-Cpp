#include <iostream>
#include <algorithm>

#include "SudokuSolver.h"

/**
 * TODO
 * - nettoyer les cout
 * - ajouter l'option d'afficher les étapes au setup
 * - ajouter l'entrée user pour les sudoku
 * - commenter le code
 * - Passer en taille N
 */

int main() {

    //Test Values
    int arr[9][9] = {{0,0,0,2,6,0,7,0,1},{6,8,0,0,7,0,0,9,0},{1,9,0,0,0,4,5,0,0},{8,2,0,1,0,0,0,4,0},{0,0,4,6,0,2,9,0,0},{0,5,0,0,0,3,0,2,8},{0,0,9,3,0,0,0,7,4},{0,4,0,0,5,0,0,3,6},{7,0,3,0,1,8,0,0,0}};
    Sudoku testSudoku(arr);
    bool displayProcess = false;

    std::string display_answer;

    //User Input

    std::cout << "You may enter the Sudoku you want to solve : ";

    std::cout << "\nDo you want to display to solving process (y/n) ? : ";
    std::cin >> display_answer;
    displayProcess = (display_answer == "y");

    testSudoku.display();

    //Solving

    SudokuSolver solver;

    solver.Solve(testSudoku, displayProcess);

    //Display solution

    if(solver.isSolved()){
        std::cout << "\nSolved Sudoku : " << std::endl;

        solver.displaySolution();
    }

    return 0;
}
