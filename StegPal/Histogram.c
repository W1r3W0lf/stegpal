//
// Created by wire_wolf on 4/14/19.
//

#include "Histogram.h"
#include <stdlib.h>







Histogram getHistogram(BMP *bmp){
    Histogram histogram = constructHistogram(bmp->bmpPalette.size);



    return histogram;
}


Histogram constructHistogram(int paletteSize){
    Histogram histogram;
    histogram.size = paletteSize;
    calloc(paletteSize, sizeof(int));
    return histogram;
}


void destructHisHistogram(Histogram histogram){
    free(histogram.histogram);
}

