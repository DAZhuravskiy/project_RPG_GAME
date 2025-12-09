#include "headers/generate_functions.hpp"

#include <iostream>
#include <cstdlib>
#include <conio.h>




void generate() {
    srand(time(NULL)); //вот эта штука позволяет реально рандомить карту, а не выводить одни и те же комбинации
    
    int hp = 3; //Здоровье персонажа
    int coins = 0; // Баланс игрока

    int enemyX; //координаты врага
    int enemyY;

    int playerX; //координаты игрока
    int playerY;

    int enemyHP = 2 + rand() % 4; // от 2 до 5 хп у врага


    bool in_market = false;
    int market_x = (rand() % 10);
    int market_y = (rand() % 10);

    matrix_create(); //генерация матрицы (matrix_create)
    add_in_matrix(); // добавление объектов в матрицу (matrix_includes)
    add_enemies(enemyX, enemyY); // добавляем врагов
    add_player(playerX, playerY); // добавляем игрока
    


    auto printMap = [&](void) { //создаем функцию внутри фнкции (лямбда-функция)
        //auto сам определяет переменную printMap, [&] позволяет видеть переменные из внешней функци 
        std::cout << "\nТекущее здоровье = " << hp <<  "\nТекущий баланс = " << coins << std::endl; //вывод количества здоровья
        if (in_market){
            std::cout << "Вы зашли в магазин, вот что у нас есть:" << std::endl;
            std::cout << "1. Увеличить здоровье - 2 монеты" << std::endl;
            std::cout << "2. Ключ от подземелья - серце монстра" << std::endl;
            in_market = false;
        }
        for (int i = 0; i < 10; i++) { //выводим матрицу
            std::cout << std::endl;
            for (int j = 0; j < 10; j++) {
                std::cout << matrix[i][j] << ' ';
            }
        }
    };


    bool flag = true;
    while (flag) {
        std::cout << "\033[1J"; //вот эта имбулька очищает экран от кала


        matrix[market_x][market_y] = 'M';

        printMap();

        

        char move = _getch(); //не ждем нажатия enter после ввода символа
        move = std::tolower(move);
        int newX = playerX;
        int newY = playerY;

        wasd(move, playerX, playerY, newX, newY, flag);

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

        if (matrix[newX][newY] == 'M') {
            matrix[playerX][playerY] = ' ';
            playerX = newX;
            playerY = newY;
            matrix[playerX][playerY] = 'M';
            in_market = true;
		}

        if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10 && matrix[newX][newY] != '#' && matrix[newX][newY] != '*' && matrix[newX][newY] != 'M') { //ограничения по краям карты и камням и шипам
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

        

		
    }
}