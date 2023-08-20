//
// Created by PC GAMER on 09/08/2023.
//

#include "Sudoku.h"
#include <iostream>
#include <string>

Sudoku::Sudoku(int num[9][9]) {
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            numbers[i][j] = num[i][j];
        }
    }
}

Sudoku::Sudoku(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            numbers[i][j] = 0;
        }
    }
}

Sudoku::~Sudoku() {

}

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
        if(value <= 0) continue;
        else mem[value]++;
        if(mem[value] > 1) {
            return false;
        }
    }
    return true;
}

bool Sudoku::columnIsValid(unsigned int idx) {
    int mem[9] = {0};
    //std::cout << "\nElements in column" << std::endl;
    for(int j = 0; j < 9; j++){
        int value = numbers[j][idx] - 1;
        //std::string out = "Point (" + std::to_string(j) + "," + std::to_string(idx) + ") = " + std::to_string(value+1) + " (";
        //for(auto& v : mem) out += std::to_string(v);
        //std::cout << out << ") / ";
        if(value <= 0) continue;
        else mem[value]++;
        if(mem[value] > 1) {
            //std::string subout = "(";
            //for(auto& v : mem) subout += std::to_string(v);
            //std::cout << "\n" << value + 1 << " already found " << subout << ")" << std::endl;
            return false;
        }
    }
    //std::cout << std::endl;
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

    //std::cout << "Checking bloc for " << x << "," << y << " ; origin = " << originX << "," << originY << std::endl;

    int mem[9] = {0};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int subX = originX + i;
            int subY = originY + j;
            int value = numbers[subX][subY] - 1;
            //std::cout << "see value " << value << std::endl;
            if(value <= 0) continue;
            else mem[value]++;
            if(mem[value] > 1) return false;
        }
    }
    return true;
}
