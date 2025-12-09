#include "include\main_functions.hpp"
#include "include\start_end_screen.hpp"
#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    start_screen();

    instruction();
    generate();

    end_screen();
}
