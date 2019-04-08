//
// Created by wire_wolf on 4/7/19.
//

#ifndef STEGPAL_ICONIMAGES_H
#define STEGPAL_ICONIMAGES_H


#include "../wordDefine.h"
#include "../BMP/DIBHeader.h"
#include "../BMP/Palette.h"

typedef struct ICONIMAGE
{
  BITMAPINFOHEADER  icHeader;      // DIB header
  RGBQUAD           icColors[1];   // Color table
  BYTE              icXOR[1];      // DIB bits for XOR mask
  BYTE              icAND[1];      // DIB bits for AND mask
} ICONIMAGE, *LPICONIMAGE;

#endif //STEGPAL_ICONIMAGES_H
