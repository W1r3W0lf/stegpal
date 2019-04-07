//
// Created by wire_wolf on 4/7/19.
//

#ifndef STEGPAL_GAP_H
#define STEGPAL_GAP_H

#include "DIBHeader.h"
#include "FileHeader.h"

typedef struct Gap{
    int     size;
    void*   value;
}Gap;

Gap constructGap();

Gap getGap1(BITMAPFILEHEADER bitmapfileheader, FILE *fileIn);

Gap getGap2(DIBHeader dibHeader, FILE *fileIn);

void putGap(Gap gap, FILE *fileOut);


void destructGap(Gap gap);

#endif //STEGPAL_GAP_H
