//
// Created by wire_wolf on 4/7/19.
//

#ifndef STEGPAL_ICONS_H
#define STEGPAL_ICONS_H

#include "../wordDefine.h"

typedef struct
{
    WORD           idReserved;   // Reserved (must be 0)
    WORD           idType;       // Resource Type (1 for icons)
    WORD           idCount;      // How many images?
    ICONDIRENTRY   idEntries[1]; // An entry for each image (idCount of 'em)
} ICONDIR, *LPICONDIR;

#endif //STEGPAL_ICONS_H
