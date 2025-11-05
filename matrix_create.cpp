#include "matrix_create.hpp"
#include <iostream>

std::vector<std::vector<char>> matrix; //создание матрицы
void matrix_create(){ //создаем матрицу 10x10 заполненную пробелами
    matrix = std::vector<std::vector<char>>(10, std::vector<char>(10, ' '));
}

void printMap(int& hp, int& coins) { //создаем функцию внутри фнкции (лямбда-функция)
        //auto сам определяет переменную printMap, [&] позволяет видеть переменные из внешней функци 
        std::cout << "\nТекущее здоровье = " << hp <<  "\nТекущий баланс = " << coins << std::endl; //вывод количества здоровья
        for (int i = 0; i < 10; i++) { //выводим матрицу
            std::cout << std::endl;
            for (int j = 0; j < 10; j++) {
                std::cout << matrix[i][j] << ' ';
            }
        }
};
