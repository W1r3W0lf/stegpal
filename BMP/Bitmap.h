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
#include "Gap.h"


typedef struct BMP {
    BITMAPFILEHEADER    bmpFileHeader;
    DIBHeader           bmpDIBHeader;
    Palette             bmpPalette;
    Gap                 bmpGap;
    Pixels              bmpPixels;
} BMP;

BMP constructBMP();

void destructBMP(BMP bmp);

BMP getBMP(char* fileName);

void putBMP(BMP bmp, char* fileName);

// an ICOBMP is a BMP file without the magic bytes in the file header and so no gap
typedef struct ICOBMP {
    DIBHeader           bmpDIBHeader;
    Palette             bmpPalette;
    Pixels              bmpPixels;
} ICOBMP;

ICOBMP constructICOBMP();

void destructICOBMP(ICOBMP icobmp);

ICOBMP getICOBMP(char* fileName);

void putICOBMP(ICOBMP icobmp, char* fileName);


#endif //STEGPAL_BITMAP_H
