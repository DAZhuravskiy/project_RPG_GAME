#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
int generate() {
	// так как значение массива( типа matrix[4][5]) нормально вытащить из функции нельзя( ну или можно но костялями какимито) разумней будет использовать для генерации карты std::vector
	srand(time(NULL)); //вот эта штука позволяет реально рандомить карту, а не выводить одни и те же комбинации
	int len = 10;
	std::vector<char> matrix(len * len, '0');// здесь мы задает вектора matrix который по сути будет нашей картой в виде цепочки нулей.
	for (int i = 0; i < len * len - 1;) {
		std::cout << std::endl;
		int x;

		for (int k = 0; k < len; k++) {
			x = rand() % 3;
			switch (x) {
			case 0: matrix[i] = '0'; break;
			case 1: matrix[i] = '*'; break;
			case 2: matrix[i] = '0'; break;

			}
			i++;
			//т.к. вектор является цепочкой из элементов, для генерации случайных карт нужно зарандомить значение каждого элемента этой последовательности
		}
	}
	for (int i = 0; i < len * len - 1 - 1;) {

		std::cout << std::endl;
		for (int k = 0; k < len; k++) {
			std::cout << matrix[i] << ' ';
			i++;
		}
	}
	return 0;
}
int main(){

	generate();
}