#pragma once
#include <vector>

extern std::vector<std::vector<char>> matrix;
void add_in_matrix();
void matrix_create();
void add_enemies(int& enemyX, int& enemyY);
void add_player(int& playerX, int& playerY);
bool wasd(char move, int playerX, int playerY, int& newX, int& newY, bool& flag);