#include "C:\Users\KAVychuzhin\Documents\GitHub\project_RPG_GAME\include\main_functions.hpp"
#include "C:\Users\KAVychuzhin\Documents\GitHub\project_RPG_GAME\include\start_end_screen.hpp"
#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    start_screen();

    instruction();
    generate();

    end_screen();
}
