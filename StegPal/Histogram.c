//
// Created by wire_wolf on 4/14/19.
//

#include "Histogram.h"
#include <stdlib.h>
#include <string.h>


unsigned int getPixelValue(char *value, int bitLength, int subByteLocation){
    char emptyBox[4] = {0};
    char mask = 0;

    if(bitLength < 8){
        mask = 0xff << (8 - bitLength);
        emptyBox[0] = (*value & mask);
        emptyBox[0] = emptyBox[0] >> subByteLocation * bitLength;
    }else{
        //ERROR here
        memcpy(&emptyBox,value, bitLength/8);
    }
    return *(unsigned int*)emptyBox;
}


Histogram getHistogram(BMP bmp){
    Histogram histogram = constructHistogram(bmp.bmpPalette.size);
    char* pixels = (char*)bmp.bmpPixels.pixels;

    unsigned int temp;

    for (int pixelOffset = 0; pixelOffset < bmp.bmpPixels.size ; pixelOffset++) {

        temp = getPixelValue(&pixels[pixelOffset], bmp.bmpPixels.bits, 8/bmp.bmpPixels.bits - 1);

        histogram.histogram[temp]++;
        

        for(int chunk = (8/bmp.bmpPixels.bits) - 2; chunk >= 0 ; chunk--){

            histogram.histogram[getPixelValue(&pixels[pixelOffset], bmp.bmpPixels.bits, chunk)]++;
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

