#include <iostream>
#include "C:\Users\KAVychuzhin\Documents\GitHub\project_RPG_GAME\include\generate_functions.hpp"


void add_in_matrix(){
    int x; //переменные, принимающие случайное значение для заполнения карты объектами
    int y;

    for (int i = 0; i < 20; i++) { //добавдяем в нее нужное кол-во камней (второй аргумент цикла отвечает за это кол-во)
            x = (rand() % 20);
            y = (rand() % 20);
            matrix[x][y] = '#';
    }

    for (int i = 0; i < 10; i++) { //добавдяем в нее нужное кол-во шипов
            x = (rand() % 20);
            y = (rand() % 20);
            matrix[x][y] = '*';
    }

    for (int i = 0; i < 12; i++) { //добавдяем в нее нужное кол-во монеток
            x = (rand() % 20);
            y = (rand() % 20);
            matrix[x][y] = '$';
    }

    for (int i = 0; i < 2; i++) { // добавляем два баффа к здороьвю
            x = rand() % 20;
            y = rand() % 20;
            if (matrix[x][y] == ' ')
                matrix[x][y] = '+';
    }
}

void add_enemies(int& enemyX, int& enemyY){ //добавляем врагов
    do {
        enemyX = rand() % 20;
        enemyY = rand() % 20;
    } while (matrix[enemyX][enemyY] != ' ');
    matrix[enemyX][enemyY] = '&';
}

void add_player(int& playerX, int& playerY){ //добавляем игрока
    do {
            playerX = (rand() % 20);
            playerY = (rand() % 20);
        } while (matrix[playerX][playerY] == '#'); //проверяем чтобы клетка не была занята "камнем"
        matrix[playerX][playerY] = '@';
}

std::vector<std::vector<char>> matrix; //создание матрицы
void matrix_create(){ //создаем матрицу 10x10 заполненную пробелами
    matrix = std::vector<std::vector<char>>(20, std::vector<char>(20, ' '));
}

void printMap(int& hp, int& coins) {
        std::cout << "\nТекущее здоровье = " << hp <<  "\nТекущий баланс = " << coins << std::endl; //вывод количества здоровья
        for (int i = 0; i < 20; i++) { //выводим матрицу
            std::cout << std::endl;
            for (int j = 0; j < 20; j++) {
                std::cout << matrix[i][j] << ' ';
            }
        }
}