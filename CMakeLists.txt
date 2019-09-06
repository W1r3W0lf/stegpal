cmake_minimum_required(VERSION 3.10)
project(stegpal C)

set(CMAKE_C_STANDARD 99)

file(GLOB BMP
        "BMP/*.h"
        "BMP/*.c")

file(GLOB ICO
        "ICO/*.h"
        "ICO/*.c")

file(GLOB StegPal
        "StegPal/*.h"
        "StegPal/*.c")

add_executable(stegpal main.c wordDefine.h ${BMP} ${ICO} ${StegPal})
