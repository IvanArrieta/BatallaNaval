cmake_minimum_required(VERSION 3.24)
project(ucc_2023_trabajo_final)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(trabajo_final main.cpp Barco.cpp Barco.h Barco1Casilla.cpp Barco1Casilla.h Barco2Casillas.cpp Barco2Casillas.h Barco3Casillas.cpp Barco3Casillas.h Barco4Casillas.cpp Barco4Casillas.h Juego.cpp Juego.h Tablero.cpp Tablero.h)
