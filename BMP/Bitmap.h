//
// Created by wire_wolf on 4/1/19.
//

#ifndef STEGPAL_BITMAP_H
#define STEGPAL_BITMAP_H



#include "../wordDefine.h"
#include "FileHeader.h"
#include "DIBHeader.h"
#include "Palette.h"
#include "Pixels.h"



typedef struct BMP {
    BITMAPFILEHEADER    bmpFileHeader;
    DIBHeader           bmpDIBHeader;
    Palette             bmpPalette;
    Pixels              bmpPixels;
} BMP;

BMP constructBMP();

void destructBMP(BMP bmp);

BMP getBMP(char* fileName);

void putBMP(BMP *bmp, char* fileName);

#endif //STEGPAL_BITMAP_H
