#include <iostream>
#include <cstdlib>

void generate() {
  srand(time(NULL)); //вот эта штука позволяет реально рандомить карту, а не выводить одни и те же комбинации
  char matrix[10][10]; //создаем матрицу, выполняющую роль карты
  int x; //переменные, принимающие случайное значение для заполнения карты объектами
  int y;

  for (int stroki = 0; stroki < 10; ++stroki) { //создаем матрицу, полностью состоящую из нулей
    std::cout << std::endl;
    for (int stolbi = 0; stolbi < 10; ++stolbi) {
      matrix[stroki][stolbi] = '0';
    }
  }

  for (int i = 0; i < 20; i++){ //добавдяем в нее нужное кол-во камней (второй аргумент цикла отвечает за это кол-во)
    x = (rand() % 10);
    y = (rand() % 10);
    matrix[x][y] = '#';
  }

  int playerX;
  int playerY;
  do {
    playerX = (rand() % 10);
    playerY = (rand() % 10);
  } while (matrix[playerX][playerY] == '#');
  matrix[playerX][playerY] = '@';

  auto printMap = [&](void){
    for (int i = 0; i<10; i++){ //выводим матрицу
        std::cout << std::endl;
        for (int j = 0; j<10; j++){
            std::cout << matrix[i][j] << ' ';
    }
  }
  };
  
    while(true) {
    printMap();
    char move = _getch();
    move = std::tolower(move);

    if (move == 'q'){
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

    if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10 && matrix[newX][newY] != '#') {
        matrix[playerX][playerY] == '0';
        playerX = newX;
        playerY = newY;
        matrix[playerX][playerY] = '@';
    }
    }
  }

int main(){
  generate();
}