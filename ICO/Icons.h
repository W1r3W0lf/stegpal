//
// Created by wire_wolf on 4/7/19.
//

#ifndef STEGPAL_ICONS_H
#define STEGPAL_ICONS_H

#include "../wordDefine.h"
#include "IconImages.h"
#include <stdio.h>

/*
typedef struct
{
    WORD           idReserved;   // Reserved (must be 0)
    WORD           idType;       // Resource Type (1 for icons)
    WORD           idCount;      // How many images?
    ICONDIRENTRY   idEntries[1]; // An entry for each image (idCount of 'em)
} ICONDIR, *LPICONDIR;
 */

// TODO make a little-endien to big-endien swaping function

typedef struct __attribute__((__packed__))
{
    WORD           idReserved;  // Reserved (must be 0)
    WORD           idType;      // Resource Type (1 for icons)
    WORD           idCount;     // How many images?
    ICONIMAGE**    idEntries;   // An entry for each image (idCount of 'em)
} ICONDIR, *LPICONDIR;

ICONDIR constructICONDIR();

void destructICONDIR(ICONDIR icondir);

ICONDIR getICONDIR(FILE* fileIn);

void putICONDIR(ICONDIR icondir, FILE* fileOut);

#endif //STEGPAL_ICONS_H
