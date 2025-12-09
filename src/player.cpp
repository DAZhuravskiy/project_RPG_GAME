#include "headers/generate_functions.hpp"

void add_player(int& playerX, int& playerY){
    do {
            playerX = (rand() % 10);
            playerY = (rand() % 10);
        } while (matrix[playerX][playerY] == '#'); //проверяем чтобы клетка не была занята "камнем"
        matrix[playerX][playerY] = '@';
    }