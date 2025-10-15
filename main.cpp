#include <iostream>
#include <cstdlib>

void generate() {
	char matrix[3][4];
	int x;
	for (int stroki = 0; stroki < 3; ++stroki) {
		std::cout << std::endl;
		for (int stolbi = 0; stolbi < 4; ++stolbi) {
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