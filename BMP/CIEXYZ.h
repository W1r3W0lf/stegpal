//
// Created by wire_wolf on 4/2/19.
//

#ifndef STEGPAL_CIEXYZ_H
#define STEGPAL_CIEXYZ_H

#include "../wordDefine.h"


/*
 * Microsoft definitions
typedef struct tagCIEXYZ {
    FXPT2DOT30 ciexyzX;
    FXPT2DOT30 ciexyzY;
    FXPT2DOT30 ciexyzZ;
} CIEXYZ, CIEXYZ FAR* LPCIEXYZ;

typedef struct tagCIEXYZTRIPLE {
    CIEXYZ ciexyzRed;
    CIEXYZ ciexyzGreen;
    CIEXYZ ciexyzBlue;
} CIEXYZTRIPLE typedef CIEXYZTRIPLE FAR* LPCIEXYZTRIPLE;
*/

typedef struct tagCIEXYZ {
    FXPT2DOT30 ciexyzX;
    FXPT2DOT30 ciexyzY;
    FXPT2DOT30 ciexyzZ;
} CIEXYZ;

typedef struct tagCIEXYZTRIPLE {
    CIEXYZ ciexyzRed;
    CIEXYZ ciexyzGreen;
    CIEXYZ ciexyzBlue;
} CIEXYZTRIPLE;


#endif //STEGPAL_CIEXYZ_H
