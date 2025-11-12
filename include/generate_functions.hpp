#pragma once
#include <vector>
extern std::vector<std::vector<char>> matrix;

extern std::vector<std::vector<char>> matrix;
void add_in_matrix();
void add_enemies(int& enemyX, int& enemyY);
void add_player(int& playerX, int& playerY);
void wasd(int& hp, int& coins, int& playerX, int& playerY, int& enemyHP, int& enemyX, int& enemyY);
void matrix_create();
void printMap(int& hp, int& coins);