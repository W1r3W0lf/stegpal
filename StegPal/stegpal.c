//
// Created by wire_wolf on 4/14/19.
//

#include "stegpal.h"
#include "Histogram.h"
#include <stdio.h>
#include <string.h>


BMP writeMessageToBMP(BMP bmp, char* message){
    Histogram histogram = getHistogram(bmp);

    char messageBuffer[4] = {0};

    for (int i = 0; i < histogram.size; ++i) {
        if(!histogram.histogram[i]){

            for (int j = 0; j < 3 ; ++j) {
                if(!*message){
                    return bmp;
                }

                messageBuffer[j] = *message;
                message++;
            }

            bmp.bmpPalette.pRgbquad[i] = *(RGBQUAD*)messageBuffer;
        }
    }

    destructHistogram(histogram);
    return bmp;
}

void readMessageFromBMP(BMP bmp){
    Histogram histogram = getHistogram(bmp);

    char messageBuffer[4] = {0};

    for (int i = 0; i < histogram.size; ++i) {
        if(!histogram.histogram[i]){
            memcpy(messageBuffer, (RGBQUAD*)&bmp.bmpPalette.pRgbquad[i],4);
            printf("%s", messageBuffer);
        }
    }
    printf("\n");

    destructHistogram(histogram);
}

void readHexFromBMP(BMP bmp){
    Histogram histogram = getHistogram(bmp);

    for (int i = 0; i < histogram.size; ++i) {
        if(!histogram.histogram[i]){
            printf("%i : %x \n", i ,  bmp.bmpPalette.pRgbquad[i] );
        }
    }

    destructHistogram(histogram);
}

int getSpaceInBMP(BMP bmp){
    Histogram histogram = getHistogram(bmp);
    int total = 0;
    for (int i = 0; i < histogram.size; ++i) {
        if (histogram.histogram[i] == 0){
            total += 3;
        }
    }
    destructHistogram(histogram);
    return total;
}