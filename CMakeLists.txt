cmake_minimum_required(VERSION 3.25)
project("Sudoku")

set(CMAKE_C_STANDARD 17)



add_executable(Sudoku main.cpp headers/Sudoku.h cpp/Sudoku.cpp headers/SudokuSolver.h cpp/SudokuSolver.cpp headers/Point.h)
include_directories(headers)
