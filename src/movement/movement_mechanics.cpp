#include "C:\Users\KAVychuzhin\Documents\GitHub\project_RPG_GAME\include\generate_functions.hpp"

#include <iostream>
#include <conio.h>

void wasd(int& hp, int& coins, int& playerX, int& playerY, int& enemyHP, int& enemyX, int& enemyY){
    while (true) {
        std::cout << "\033[1J"; //вот эта имбулька очищает экран от кала

        printMap(hp, coins);
        
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

        if (matrix[newX][newY] == '&') {
            std::cout << "\nВы столкнулись с врагом! Его HP = " << enemyHP << std::endl;
            if (hp >= enemyHP) {
                std::cout << "Вы победили врага!" << std::endl;
                matrix[enemyX][enemyY] = ' ';
                break;
            } else {
                std::cout << "Вы проиграли... Игра окончена." << std::endl;
                break;
            }
		}

        if (newX >= 0 && newX < 20 && newY >= 0 && newY < 20 && matrix[newX][newY] != '#' && matrix[newX][newY] != '*') { //ограничения по краям карты и камням и шипам
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