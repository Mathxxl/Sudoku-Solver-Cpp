//
// Created by PC GAMER on 09/08/2023.
//

#include "Sudoku.h"
#include <iostream>

Sudoku::Sudoku(int num[9][9]) {
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            numbers[i][j] = num[i][j];
        }
    }
}

Sudoku::Sudoku(){
    for(auto & line : numbers){
        for(int & n : line){
            n = 0;
        }
    }
}

Sudoku::~Sudoku() = default;

void Sudoku::display() {
    std::cout << "___________________" << std::endl;
    for(int i = 0; i < 9; i++){
        auto line = numbers[i];
        std::cout << "|";
        for(int j = 0; j < 9; j++) {
            std::cout << line[j];
            if((j+1)%3 == 0 && j!=0 && j!=8) std::cout << "|";
            else if(j != 8) std::cout << " ";
        }
        std::cout << "|" << std::endl;
        if((i+1)%3 == 0 && i!=0 && i!=8){
            std::cout << "-------------------" << std::endl;
        }
    }
    std::cout << "___________________" << std::endl;
}

bool Sudoku::lineIsValid(unsigned int idx) {
    int mem[9] = {0};

    for(int i = 0; i < 9; i++){
        int value = numbers[idx][i] - 1;
        if(value < 0) continue;
        else mem[value]++;
        if(mem[value] > 1) {
            return false;
        }
    }
    return true;
}

bool Sudoku::columnIsValid(unsigned int idx) {
    int mem[9] = {0};
    for(auto & number : numbers){
        int value = number[idx] - 1;
        if(value < 0) continue;
        else mem[value]++;
        if(mem[value] > 1) {
            return false;
        }
    }
    return true;
}

int Sudoku::getBlocOriginX(int x) {
    return (x/3) * 3;
}

int Sudoku::getBlocOriginY(int y) {
    return (y/3) * 3;
}

bool Sudoku::blocIsValid(int x, int y) {
    int originX = getBlocOriginX(x);
    int originY = getBlocOriginY(y);

    int mem[9] = {0};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int subX = originX + i;
            int subY = originY + j;
            int value = numbers[subX][subY] - 1;
            if(value < 0) continue;
            else mem[value]++;
            if(mem[value] > 1) return false;
        }
    }
    return true;
}
