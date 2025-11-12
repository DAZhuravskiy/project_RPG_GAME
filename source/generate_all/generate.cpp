#include "generate_functions.hpp"

#include <iostream>
#include <cstdlib>





void generate() {
    srand(time(NULL)); //вот эта штука позволяет реально рандомить карту, а не выводить одни и те же комбинации
    
    int hp = 3; //Здоровье персонажа
    int coins = 0; // Баланс игрока

    int enemyX; //координаты врага
    int enemyY;

    int playerX; //координаты игрока
    int playerY;

    int enemyHP = 2 + rand() % 4; // от 2 до 5 хп у врага

    matrix_create(); //генерация матрицы (matrix_create)
    add_in_matrix(); // добавление объектов в матрицу (matrix_includes)
    add_enemies(enemyX, enemyY); // добавляем врагов
    add_player(playerX, playerY); // добавляем игрока
    
    printMap(hp, coins);

    wasd(hp, coins, playerX, playerY, enemyHP, enemyX, enemyY);
}