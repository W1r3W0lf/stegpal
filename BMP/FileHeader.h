//
// Created by wire_wolf on 4/2/19.
//

#ifndef STEGPAL_FILEHEADER_H
#define STEGPAL_FILEHEADER_H


#include "../wordDefine.h"

#include <stdio.h>

#include <stdint.h>


//#define bmpHeaderSize = 14;

// This looks back words little-endian?
//#define int16_t bmpMagic = 0x4d42;

typedef struct __attribute__((__packed__)) tagBITMAPFILEHEADER {
    WORD  bfType;
    DWORD bfSize;
    WORD  bfReserved1;
    WORD  bfReserved2;
    DWORD bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;


BITMAPFILEHEADER getBMPHead(FILE* fileIn);

void putBMPHead(BITMAPFILEHEADER fileHeader, FILE* fileOut);


#endif //STEGPAL_FILEHEADER_H
