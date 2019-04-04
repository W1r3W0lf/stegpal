//
// Created by wire_wolf on 4/2/19.
//

#ifndef STEGPAL_FILEHEADER_H
#define STEGPAL_FILEHEADER_H


#include "../wordDefine.h"

#include <stdio.h>


const int bmpHeaderSize = 14;
const int16_t bmpMagic = 0x4d42; // This looks back words little-endian?

typedef struct tagBITMAPFILEHEADER {
    WORD  bfType;
    DWORD bfSize;
    WORD  bfReserved1;
    WORD  bfReserved2;
    DWORD bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;


BITMAPFILEHEADER getBMPHead(FILE* input);

void putBMPHead(BITMAPFILEHEADER fileHeader, FILE* output);


#endif //STEGPAL_FILEHEADER_H
