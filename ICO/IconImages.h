//
// Created by wire_wolf on 4/7/19.
//

#ifndef STEGPAL_ICONIMAGES_H
#define STEGPAL_ICONIMAGES_H


#include "../wordDefine.h"
#include "../BMP/Palette.h"
#include "../BMP/DIBHeader.h"
#include <stdio.h>

typedef struct ICONIMAGE
{
  BITMAPINFOHEADER  icHeader;   // DIB header
  int               colorSize;
  RGBQUAD**         icColors;   // Color table
  int               xorSize;
  BYTE**            icXOR;      // DIB bits for XOR mask
  int               andSize;
  BYTE**            icAND;      // DIB bits for AND mask
} ICONIMAGE, *LPICONIMAGE;

ICONIMAGE constructICONIMAGE();

void destructICONIMAGE(ICONIMAGE iconimage);

ICONIMAGE getICONIMAGE(FILE* fileIn);

void putICONIMAGE(ICONIMAGE iconimage, FILE* fileOut);

#endif //STEGPAL_ICONIMAGES_H
