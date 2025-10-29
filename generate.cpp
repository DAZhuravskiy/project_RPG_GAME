#include "func.hpp"

#include <iostream>
#include <cstdlib>
#include <conio.h>


void generate() {
    srand(time(NULL)); //��� ��� ����� ��������� ������� ��������� �����, � �� �������� ���� � �� �� ����������
    char matrix[10][10]; //������� �������, ����������� ���� �����
    int x; //����������, ����������� ��������� �������� ��� ���������� ����� ���������
    int y;
    int hp = 3; //�������� ���������
    int coins = 0; // ������ ������

    for (int i = 0; i < 10; ++i) { //������� �������, ��������� ��������� �� �����
        std::cout << std::endl;
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = ' ';
        }
    }

    for (int i = 0; i < 10; i++) { //��������� � ��� ������ ���-�� ������ (������ �������� ����� �������� �� ��� ���-��)
        x = (rand() % 10);
        y = (rand() % 10);
        matrix[x][y] = '#';
    }

    for (int i = 0; i < 5; i++) { //��������� � ��� ������ ���-�� �����
        x = (rand() % 10);
        y = (rand() % 10);
        matrix[x][y] = '*';
    }

    for (int i = 0; i < 5; i++) { //��������� � ��� ������ ���-�� �������
        x = (rand() % 10);
        y = (rand() % 10);
        matrix[x][y] = '$';
    }

	for (int i = 0; i < 2; i++) { // ��������� ��� ����� � ��������
        x = rand() % 10;
        y = rand() % 10;
        if (matrix[x][y] == ' ')
            matrix[x][y] = '+';
    }
	int enemyX, enemyY;
    int enemyHP = 2 + rand() % 4; // �� 2 �� 5 �� � �����
    do {
        enemyX = rand() % 10;
        enemyY = rand() % 10;
    } while (matrix[enemyX][enemyY] != ' ');
    matrix[enemyX][enemyY] = '&';

    int playerX;
    int playerY;
    do {
        playerX = (rand() % 10);
        playerY = (rand() % 10);
    } while (matrix[playerX][playerY] == '#'); //��������� ����� ������ �� ���� ������ "������"
    matrix[playerX][playerY] = '@';


    auto printMap = [&](void) { //������� ������� ������ ������ (������-�������)
        //auto ��� ���������� ���������� printMap, [&] ��������� ������ ���������� �� ������� ������ 
        std::cout << "������� �������� = " << hp <<  "������� ������ = " << coins << std::endl; //����� ���������� ��������
        for (int i = 0; i < 10; i++) { //������� �������
            std::cout << std::endl;
            for (int j = 0; j < 10; j++) {
                std::cout << matrix[i][j] << ' ';
            }
        }
    };

    while (true) {
        //system("clear"); //��� ����� ������� ������� � ����������� �� �������, �� � ������ �� ��� ��������, ��� ��� ���
        std::cout << "\033[1J"; //��� ��� �������� ������� ����� �� ����

        printMap();
        char move = _getch(); //�� ���� ������� enter ����� ����� �������
        move = std::tolower(move);

        if (move == 'q') {
            std::cout << "����� �� ����\n";
            break;
        }

        if (move == 'e') {
            std::cout << "��� ������ �����: " << coins << std::endl;
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

        if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10 && matrix[newX][newY] != '#' && matrix[newX][newY] != '*') { //����������� �� ����� ����� � ������ � �����
            matrix[playerX][playerY] = ' ';
            playerX = newX;
            playerY = newY;
            matrix[playerX][playerY] = '@';
        }
        if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10 && matrix[newX][newY] == '*'){ //���� ����� ������������ � ������, �� �������� �����������
            hp--;
        }
        if (hp == 0) { //���� �� = 0, ����� �� ����
            std::cout << "����� �� ����\n";
            break;
        }

		if (matrix[newX][newY] == '&') {
            std::cout << "�� ����������� � ������! ��� HP = " << enemyHP << std::endl;
            if (hp >= enemyHP) {
                std::cout << "�� �������� �����!" << std::endl;
                matrix[enemyX][enemyY] = ' ';
            } else {
                std::cout << "�� ���������... ���� ��������." << std::endl;
                break;
            }
		}
    }
}