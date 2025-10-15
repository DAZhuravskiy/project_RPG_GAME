#include <iostream>

int main()
{
	int matrix[3][4];
	int numerate = 0;
	for (int i = 0; i < 3; ++i){
		std::cout << std::endl;
		for (int j = 0; j < 4; ++j){
			matrix[i][j] = numerate;
			++numerate;
			std::cout << matrix[i][j] << ' ';
		}
	}

	
}