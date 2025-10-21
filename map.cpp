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
  for (int i = 0; i < 1; i++){ //добавляем нужное кол-во персонажей
    x = (rand() % 10);
    y = (rand() % 10);
    matrix[x][y] = '@';
  }

  for (int i = 0; i<10; i++){ //выводим матрицу
    std::cout << std::endl;
    for (int j = 0; j<10; j++){
      std::cout << matrix[i][j] << ' ';
    }
  }
}
int main(){
  generate();
}