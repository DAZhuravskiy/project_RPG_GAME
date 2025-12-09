#include "include\generate_functions.hpp"

#include <iostream>
#include <conio.h>

void wasd(int& hp, int& coins, int& playerX, int& playerY, int& enemyHP, int& enemyX, int& enemyY, bool& in_market, int market_x, int market_y, int& heart, int princess_x, int princess_y, int& key){
    while (true) {
        std::cout << "\033[1J"; //вот эта имбулька очищает экран от кала

        printMap(hp, coins, in_market, market_x, market_y, heart, princess_x, princess_y, key, princess_saved);
        
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


    
    if (in_market) {
    switch (move) {
    case '1':  // покупка HP за 2 монеты
        if (coins >= 2) {
            coins -= 2;
            hp += 1;
            std::cout << "Вы купили +1 к здоровью! Сейчас здоровье: " << hp << std::endl;
        } else {
            std::cout << "Недостаточно монет для покупки здоровья." << std::endl;
        }
        in_market = false; // выходим из магазина
        _getch();
        continue;

    case '2':  // покупка ключа за сердце монстра
        if (key == 1) {
            std::cout << "У вас уже есть ключ, второй не нужен." << std::endl;
        } else if (heart >= 1) {
            heart -= 1;
            key = 1;
            std::cout << "Вы купили ключ от подземелья!" << std::endl;
        } else {
            std::cout << "У вас нет сердца монстра для покупки ключа." << std::endl;
        }
        in_market = false;
        _getch();
        continue;

    case '0':  // выйти из магазина
        std::cout << "Вы вышли из магазина." << std::endl;
        in_market = false;
        _getch();
        continue;

    default:
        std::cout << "В магазине нужно нажать 1, 2 или 0 для выхода." << std::endl;
        _getch();
        continue;
    }
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

        if (matrix[newX][newY] == '&') {
            std::cout << "\nВы столкнулись с врагом! Его HP = " << enemyHP << std::endl;
            if (hp >= enemyHP) {
                std::cout << "Вы победили врага и добыли его сердце!" << std::endl;
                matrix[enemyX][enemyY] = ' ';
                heart += 1;
            } else {
                std::cout << "Вы проиграли... Игра окончена." << std::endl;
                break;
            }
		}

        if (matrix[newX][newY] == 'M') {
            matrix[playerX][playerY] = ' ';
            playerX = newX;
            playerY = newY;
            matrix[playerX][playerY] = 'M';
            in_market = true;
		}

        if (matrix[newX][newY] == 'P') {
            matrix[playerX][playerY] = ' ';
            playerX = newX;
            playerY = newY;
            matrix[playerX][playerY] = 'P';
            princess_saved = true;
		}        

        if (newX >= 0 && newX < 20 && newY >= 0 && newY < 20 && matrix[newX][newY] != '#' && matrix[newX][newY] != '*' && matrix[newX][newY] != 'M') { //ограничения по краям карты и камням и шипам
            matrix[playerX][playerY] = ' ';
            playerX = newX;
            playerY = newY;
            matrix[playerX][playerY] = '@';
        }
        if (newX >= 0 && newX < 20 && newY >= 0 && newY < 20 && matrix[newX][newY] == '*'){ //если игрок сталкивается с шипами, то здоровье уменьшается
            hp--;
        }
        if (hp == 0) { //если хп = 0, выход из игры
            std::cout << "Выход из игры\n";
            break;
        }
    }
}