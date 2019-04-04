//
// Created by wire_wolf on 4/2/19.
//

#ifndef STEGPAL_DIBHEADER_H
#define STEGPAL_DIBHEADER_H

#include "../wordDefine.h"
#include "CIEXYZ.h"

#include <stdio.h>

typedef struct __attribute__((__packed__)) tagBITMAPCOREHEADER {
    DWORD bcSize;
    WORD  bcWidth;
    WORD  bcHeight;
    WORD  bcPlanes;
    WORD  bcBitCount;
} BITMAPCOREHEADER, *PBITMAPCOREHEADER;

typedef struct __attribute__((__packed__)) tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG  biWidth;
    LONG  biHeight;
    WORD  biPlanes;
    WORD  biBitCount;
    DWORD biCompression;    // The hs code uses Compression insted of a DWORD
    DWORD biSizeImage;
    LONG  biXPelsPerMeter;
    LONG  biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;

typedef struct __attribute__((__packed__)) {
    DWORD        bV4Size;
    LONG         bV4Width;
    LONG         bV4Height;
    WORD         bV4Planes;
    WORD         bV4BitCount;
    DWORD        bV4V4Compression;  // The hs code uses Compression insted of a DWORD
    DWORD        bV4SizeImage;
    LONG         bV4XPelsPerMeter;
    LONG         bV4YPelsPerMeter;
    DWORD        bV4ClrUsed;
    DWORD        bV4ClrImportant;
    DWORD        bV4RedMask;
    DWORD        bV4GreenMask;
    DWORD        bV4BlueMask;
    DWORD        bV4AlphaMask;
    DWORD        bV4CSType;
    CIEXYZTRIPLE bV4Endpoints;
    DWORD        bV4GammaRed;
    DWORD        bV4GammaGreen;
    DWORD        bV4GammaBlue;
} BITMAPV4HEADER, *PBITMAPV4HEADER;

typedef struct __attribute__((__packed__)) {
    DWORD        bV5Size;
    LONG         bV5Width;
    LONG         bV5Height;
    WORD         bV5Planes;
    WORD         bV5BitCount;
    DWORD        bV5Compression;    // The hs code uses Compression insted of a DWORD
    DWORD        bV5SizeImage;
    LONG         bV5XPelsPerMeter;
    LONG         bV5YPelsPerMeter;
    DWORD        bV5ClrUsed;
    DWORD        bV5ClrImportant;
    DWORD        bV5RedMask;
    DWORD        bV5GreenMask;
    DWORD        bV5BlueMask;
    DWORD        bV5AlphaMask;
    DWORD        bV5CSType;
    CIEXYZTRIPLE bV5Endpoints;
    DWORD        bV5GammaRed;
    DWORD        bV5GammaGreen;
    DWORD        bV5GammaBlue;
    DWORD        bV5Intent;
    DWORD        bV5ProfileData;
    DWORD        bV5ProfileSize;
    DWORD        bV5Reserved;
} BITMAPV5HEADER, *PBITMAPV5HEADER;

typedef enum DIBType{
    core = 16,
    info = 40,
    v4   = 108,
    v5   = 124
} DIBType;

// Pointers are used for the Header types to allow for easy acess and shrinks the memory footprint.
typedef struct DIBHeader{
    DIBType             type;
    BITMAPCOREHEADER    *core;
    BITMAPINFOHEADER    *info;
    BITMAPV4HEADER      *v4;
    BITMAPV5HEADER      *v5;
}DIBHeader;

DIBHeader constructDIBHeader();

DIBHeader getDIBHeader(FILE *input);

void* getDIBPtr(DIBHeader dibHeader);

void destructDIBHeader(DIBHeader dibHeader);

void putDIBHeader( DIBHeader dibHeader, FILE *output);

#endif //STEGPAL_DIBHEADER_H
