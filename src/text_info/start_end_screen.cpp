#include "C:\Users\KAVychuzhin\Documents\GitHub\project_RPG_GAME\include\start_end_screen.hpp"

#include <iostream>
#include <conio.h>

void start_screen(){
    std::cout << "XXXX      XXXX      XXXXX      XXXX      XXXX     " << std::endl;
    std::cout << "X   X     X   X     X         X         X         " << std::endl;
    std::cout << "XXXX      XXXX      XXXXX      XXX       XXX      " << std::endl;
    std::cout << "X         X X       X             X         X     " << std::endl;
    std::cout << "X         X  X      XXXXX     XXXX      XXXX      " << std::endl;
    std::cout << "      XXXX     XXXX       XXX       XXX      XXXXX" << std::endl;
    std::cout << "     X         X   X     X   X     X   X     X    " << std::endl;
    std::cout << "      XXX      XXXX      XXXXX     X         XXXXX" << std::endl;
    std::cout << "         X     X         X   X     X   X     X    " << std::endl;
    std::cout << "     XXXX      X         X   X      XXX      XXXXX" << std::endl;
    std::cout << "                    XXXXX      XXX                " << std::endl;
    std::cout << "                      X       X   X               " << std::endl;
    std::cout << "                      X       X   X               " << std::endl;
    std::cout << "                      X       X   X               " << std::endl;
    std::cout << "                      X        XXX                " << std::endl;
    std::cout << "      XXXX     XXXXX      XXX      XXXX      XXXXX" << std::endl;
    std::cout << "     X           X       X   X     X   X       X  " << std::endl;
    std::cout << "      XXX        X       XXXXX     XXXX        X  " << std::endl;
    std::cout << "         X       X       X   X     X X         X  " << std::endl;
    std::cout << "     XXXX        X       X   X     X  X        X  " << std::endl;
    while (true){
        char click = _getch(); //не ждем нажатия enter после ввода символа
        click = std::tolower(click);
        if (click == ' '){
            break;
        }
    }

}

void end_screen(){
    std::cout << " XXXX      XXX       X X      XXXXX     " << std::endl;
    std::cout << "X         X   X     X X X     X         " << std::endl;
    std::cout << "X XXX     XXXXX     X X X     XXXXX     " << std::endl;
    std::cout << "X   X     X   X     X X X     X         " << std::endl;
    std::cout << " XXX      X   X     X X X     XXXXX     " << std::endl;
    std::cout << "      XXX      X   X     XXXXX     XXXX " << std::endl;
    std::cout << "     X   X     X   X     X         X   X" << std::endl;
    std::cout << "     X   X      X X      XXXXX     XXXX " << std::endl;
    std::cout << "     X   X      X X      X         X X  " << std::endl;
    std::cout << "      XXX        X       XXXXX     X  X " << std::endl;
    while (true){
        char click = _getch(); //не ждем нажатия enter после ввода символа
        click = std::tolower(click);
        if (click == ' '){
            break;
        }
    }
}