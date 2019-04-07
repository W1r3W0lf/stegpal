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
#include "gap.h"


typedef struct BMP {
    BITMAPFILEHEADER    bmpFileHeader;
    DIBHeader           bmpDIBHeader;
    Palette             bmpPalette;
    Gap                 bmpGap1;
    Pixels              bmpPixels;
    Gap                 bmpGap2;


} BMP;

BMP constructBMP();

void destructBMP(BMP bmp);

BMP getBMP(char* fileName);

// FOR DEBUG ONLY
void copyBMP(char* nameIn, char* nameOut);

void putBMP(BMP *bmp, char* fileName);

#endif //STEGPAL_BITMAP_H
