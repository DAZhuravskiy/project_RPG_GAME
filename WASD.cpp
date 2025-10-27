#include <iostream>
#include <cstdlib>
#include <conio.h>

void generate() {
    srand(time(NULL)); //вот эта штука позволяет реально рандомить карту, а не выводить одни и те же комбинации
    char matrix[10][10]; //создаем матрицу, выполняющую роль карты
    int x; //переменные, принимающие случайное значение для заполнения карты объектами
    int y;
    int hp = 3; //Здоровье персонажа

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

    int playerX;
    int playerY;
    do {
        playerX = (rand() % 10);
        playerY = (rand() % 10);
    } while (matrix[playerX][playerY] == '#'); //проверяем чтобы клетка не была занята "камнем"
    matrix[playerX][playerY] = '@';

    auto printMap = [&](void) { //создаем функцию внутри фнкции (лямбда-функция)
        //auto сам определяет переменную printMap, [&] позволяет видеть переменные из внешней функци 
        std::cout << "Текущее здоровье = " << hp << std::endl; //вывод количества здоровья
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
        int newX = playerX;
        int newY = playerY;
        if (move == 'w') newX--;
        else if (move == 'a') newY--;
        else if (move == 's') newX++;
        else if (move == 'd') newY++;
        else continue;

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
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "q - выход из игры" << std::endl;
    std::cout << "wasd - передвижение" << std::endl;
    std::cout << "@ - это вы" << std::endl;
    std::cout << "# - это камни, на них наступить не получится)" << std::endl;
    std::cout << "* - это шипы, они отнимают здоровье)" << std::endl;
    generate();
}
