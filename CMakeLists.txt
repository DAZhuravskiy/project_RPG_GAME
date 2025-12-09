cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.

set(PROJECT_NAME test) 		         # задать значение PROJECT_NAME		 
project("${PROJECT_NAME}")           # установить имя проекта

set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Сказать программе, что должен быть исполняемый файл
add_executable("${PROJECT_NAME}" src/main.cpp src/generate.cpp src/map_generate_include.cpp src/movement_mechanics.cpp src/instruction.cpp src/start_end_screen.cpp)
