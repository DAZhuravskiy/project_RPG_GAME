#include "generate_functions.hpp"
#include <iostream>

std::vector<std::vector<char>> matrix; //создание матрицы
void matrix_create(){ //создаем матрицу 10x10 заполненную пробелами
    matrix = std::vector<std::vector<char>>(10, std::vector<char>(10, ' '));
}
