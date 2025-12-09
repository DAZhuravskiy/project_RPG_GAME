#include "headers/generate_functions.hpp"
#include <iostream>

bool wasd(char move, int playerX, int playerY, int& newX, int& newY, bool& flag){
    if (move == 'q') {
            std::cout << "Выход из игры\n";
            return flag = false;
    }

    if (move == 'w') return newX--;
    else if (move == 'a') return newY--;
    else if (move == 's') return newX++;
    else if (move == 'd') return newY++;
    else return flag = true;
}