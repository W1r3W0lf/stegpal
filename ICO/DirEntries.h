//
// Created by wire_wolf on 4/7/19.
//

#ifndef STEGPAL_DIRENTRIES_H
#define STEGPAL_DIRENTRIES_H

#include "../wordDefine.h"

typedef struct
{
    BYTE        bWidth;          // Width, in pixels, of the image
    BYTE        bHeight;         // Height, in pixels, of the image
    BYTE        bColorCount;     // Number of colors in image (0 if >=8bpp)
    BYTE        bReserved;       // Reserved ( must be 0)
    WORD        wPlanes;         // Color Planes
    WORD        wBitCount;       // Bits per pixel
    DWORD       dwBytesInRes;    // How many bytes in this resource?
    DWORD       dwImageOffset;   // Where in the file is this image?
} ICONDIRENTRY, *LPICONDIRENTRY;

#endif //STEGPAL_DIRENTRIES_H
