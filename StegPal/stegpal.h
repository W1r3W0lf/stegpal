//
// Created by wire_wolf on 4/14/19.
//

#ifndef STEGPAL_STEGPAL_H
#define STEGPAL_STEGPAL_H

#include "../BMP/Bitmap.h"

BMP writeMessageToBMP(BMP bmp, char* message );

void readMessageFromBMP(BMP bmp);

void readHexFromBMP(BMP bmp);

int getSpaceInBMP(BMP bmp);

#endif //STEGPAL_STEGPAL_H
