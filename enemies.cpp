#include "generate_functions.hpp"


void add_enemies(int& enemyX, int& enemyY){ //добавляем врагов
    do {
        enemyX = rand() % 10;
        enemyY = rand() % 10;
    } while (matrix[enemyX][enemyY] != ' ');
    matrix[enemyX][enemyY] = '&';
}