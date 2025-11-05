#include <iostream>
#include "generate_functions.hpp"


void add_in_matrix(){
    int x; //переменные, принимающие случайное значение для заполнения карты объектами
    int y;

    for (int i = 0; i < 10; i++) { //добавдяем в нее нужное кол-во камней (второй аргумент цикла отвечает за это кол-во)
            x = (rand() % 10);
            y = (rand() % 10);
            matrix[x][y] = '#';
    }

    for (int i = 0; i < 5; i++) { //добавдяем в нее нужное кол-во шипов
            x = (rand() % 10);
            y = (rand() % 10);
            matrix[x][y] = '*';
    }

    for (int i = 0; i < 5; i++) { //добавдяем в нее нужное кол-во монеток
            x = (rand() % 10);
            y = (rand() % 10);
            matrix[x][y] = '$';
    }

    for (int i = 0; i < 2; i++) { // добавляем два баффа к здороьвю
            x = rand() % 10;
            y = rand() % 10;
            if (matrix[x][y] == ' ')
                matrix[x][y] = '+';
    }
}