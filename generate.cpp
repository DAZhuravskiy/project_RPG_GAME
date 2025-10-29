#include "func.hpp"

#include <iostream>
#include <cstdlib>
#include <conio.h>


void generate() {
    srand(time(NULL)); //вот эта штука позволяет реально рандомить карту, а не выводить одни и те же комбинации
    char matrix[10][10]; //создаем матрицу, выполняющую роль карты
    int x; //переменные, принимающие случайное значение для заполнения карты объектами
    int y;
    int hp = 3; //Здоровье персонажа
    int coins = 0; // Баланс игрока

    for (int i = 0; i < 10; ++i) { //создаем матрицу, полностью состоящую из нулей
        std::cout << std::endl;
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = ' ';
        }
    }

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
	int enemyX, enemyY;
    int enemyHP = 2 + rand() % 4; // от 2 до 5 хп у врага
    do {
        enemyX = rand() % 10;
        enemyY = rand() % 10;
    } while (matrix[enemyX][enemyY] != ' ');
    matrix[enemyX][enemyY] = '&';

    int playerX;
    int playerY;
    do {
        playerX = (rand() % 10);
        playerY = (rand() % 10);
    } while (matrix[playerX][playerY] == '#'); //проверяем чтобы клетка не была занята "камнем"
    matrix[playerX][playerY] = '@';


    auto printMap = [&](void) { //создаем функцию внутри фнкции (лямбда-функция)
        //auto сам определяет переменную printMap, [&] позволяет видеть переменные из внешней функци 
        std::cout << "Текущее здоровье = " << hp <<  "Текущее баланс = " << coins << std::endl; //вывод количества здоровья
        for (int i = 0; i < 10; i++) { //выводим матрицу
            std::cout << std::endl;
            for (int j = 0; j < 10; j++) {
                std::cout << matrix[i][j] << ' ';
            }
        }
    };

    while (true) {
        //system("clear"); //эта штука странно рботает в зависимости от запуска, да и дипсик на нее ругается, так что пох
        std::cout << "\033[1J"; //вот эта имбулька очищает экран от кала

        printMap();
        char move = _getch(); //не ждем нажатия enter после ввода символа
        move = std::tolower(move);

        if (move == 'q') {
            std::cout << "Выход из игры\n";
            break;
        }

        if (move == 'e') {
            std::cout << "Ваш баланс монет: " << coins << std::endl;
            continue;
        }

        int newX = playerX;
        int newY = playerY;
        if (move == 'w') newX--;
        else if (move == 'a') newY--;
        else if (move == 's') newX++;
        else if (move == 'd') newY++;
        else continue;

        if (matrix[newX][newY] == '+') {
            hp++;
		}
        
        if (matrix[newX][newY] == '$') {
            coins++;
        }

        if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10 && matrix[newX][newY] != '#' && matrix[newX][newY] != '*') { //ограничения по краям карты и камням и шипам
            matrix[playerX][playerY] = ' ';
            playerX = newX;
            playerY = newY;
            matrix[playerX][playerY] = '@';
        }
        if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10 && matrix[newX][newY] == '*'){ //если игрок сталкивается с шипами, то здоровье уменьшается
            hp--;
        }
        if (hp == 0) { //если хп = 0, выход из игры
            std::cout << "Выход из игры\n";
            break;
        }

		if (matrix[newX][newY] == '&') {
            std::cout << "Вы столкнулись с врагом! Его HP = " << enemyHP << std::endl;
            if (hp >= enemyHP) {
                std::cout << "Вы победили врага!" << std::endl;
                matrix[enemyX][enemyY] = ' ';
            } else {
                std::cout << "Вы проиграли... Игра окончена." << std::endl;
                break;
            }
		}
    }
}