//
// Created by wire_wolf on 4/2/19.
//

#ifndef STEGPAL_PIXELS_H
#define STEGPAL_PIXELS_H

#include "../wordDefine.h"
#include "DIBHeader.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct tagRGBTRIPLE {
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} RGBTRIPLE;

typedef struct Pixels{
    int width;
    int height;
    int size;   //Number of bytes
    int bits;   //Number of bits per pixel
    RGBTRIPLE **pixels;
} Pixels;


Pixels constructPixels();

void destructPixels(Pixels pixels);

Pixels getPixels(DIBHeader dibHeader ,FILE *fileIn);

void putPixels(Pixels pixels ,FILE *output);

#endif //STEGPAL_PIXELS_H
