//
// Created by wire_wolf on 4/14/19.
//

#ifndef STEGPAL_HISTOGRAM_H
#define STEGPAL_HISTOGRAM_H

#include "../BMP/Bitmap.h"
#include "../BMP/Palette.h"

typedef struct BMPDataNode BMPDataNode;

struct BMPDataNode {
    BMPDataNode *next;
    RGBQUAD     *data;
};

typedef struct Histogram{
    int**   histogram;
    int     size;
}Histogram;



BMPDataNode** getBMPData(BMP bmp);

void setBMPData(BMP bmp, char** string, int stringSize);


Histogram constructHistogram(int paletteSize);

void destructHisHistogram(Histogram histogram);

Histogram getHistogram(BMP *bmp);

#endif //STEGPAL_HISTOGRAM_H
