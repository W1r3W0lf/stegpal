//
// Created by wire_wolf on 4/2/19.
//

#ifndef STEGPAL_PALETTE_H
#define STEGPAL_PALETTE_H

#include "DIBHeader.h"
#include "../wordDefine.h"

#include <stdio.h>


typedef struct tagRGBQUAD {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rgbRed;
    BYTE rgbReserved;
} RGBQUAD;


typedef struct Palette{
    int         size;
    RGBQUAD**   pRgbquad;
} Palette;

Palette constructPalette();

void destructPalette(Palette palette);

void showRGBquad(RGBQUAD rgbquad);

RGBQUAD getRGBquad(FILE *filein);

void putRGBQuad(RGBQUAD *rgbquad ,FILE *fileout);

Palette getPalette(DIBHeader dibHeader, FILE *filein);

void putPalette(Palette palette, FILE *fileout);


#endif //STEGPAL_PALETTE_H
