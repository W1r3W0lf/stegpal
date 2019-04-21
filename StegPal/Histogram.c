//
// Created by wire_wolf on 4/14/19.
//

#include "Histogram.h"
#include <stdlib.h>
#include <string.h>

/*
 * This function returns the value of the chunk of data.
 * It also changes the chunk into an unsigned int
 * an int on my system is 32 bits. witch is the max size of a pixel. I am making it unsigned for easy use and debugging.
 */
unsigned int getPixelValue(char *value, int bitLength, int subByteLocation){
    char emptyBox[4] = {0};
    char mask;

    if(bitLength < 8){
        mask = 0xff << (8 - bitLength);
        emptyBox[3] = (*value & mask) >> subByteLocation * bitLength;
    }else{
        memcpy(&emptyBox[4 - bitLength/8],value, bitLength/8);
    }
    return *(unsigned int*)emptyBox;
}


Histogram getHistogram(BMP *bmp){

    Histogram histogram = constructHistogram(bmp->bmpPalette.size);
    char* pixels = (char*)bmp->bmpPixels.pixels;

    for (int pixelOffset = 0; pixelOffset < bmp->bmpPixels.size * sizeof(RGBQUAD) ; pixelOffset++) {
        histogram.histogram[getPixelValue(&pixels[pixelOffset], bmp->bmpPixels.bits, 0)]++;
        for(int chunk = 1; chunk < 8/bmp->bmpPixels.bits; chunk++){
            histogram.histogram[getPixelValue(&pixels[pixelOffset], bmp->bmpPixels.bits, chunk)]++;
        }
    }
    return histogram;
}


Histogram constructHistogram(int paletteSize){
    Histogram histogram;
    histogram.size = paletteSize;
    histogram.histogram = calloc(paletteSize, sizeof(int));
    return histogram;
}


void destructHisHistogram(Histogram histogram){
    free(histogram.histogram);
}

