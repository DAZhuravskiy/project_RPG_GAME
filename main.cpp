#include <iostream>
#include <cstdlib>
#include <time.h>
void generate() {
	srand(time(NULL)); //вот эта штука позволяет реально рандомить карту, а не выводить одни и те же комбинации
	char matrix[7][9];
	int x;
	for (int stroki = 0; stroki < 7; ++stroki) {
		std::cout << std::endl;
		for (int stolbi = 0; stolbi < 9; ++stolbi) {
			x = (rand() % 3);
			switch (x)
			{
			case 0:
				matrix[stroki][stolbi] = '0';
				break;
			case 1:
				matrix[stroki][stolbi] = '*';
				break;
			case 2:
				matrix[stroki][stolbi] = '@';
				break;
			default:
				break;
			}


			//matrix[stroki][stolbi] = x;
			std::cout << matrix[stroki][stolbi] << ' ';
		}
	}
}
int main()

{
	generate();
}