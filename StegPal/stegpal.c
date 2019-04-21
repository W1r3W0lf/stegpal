//
// Created by wire_wolf on 4/14/19.
//

#include "stegpal.h"
#include "Histogram.h"


BMP writeMessageToBMP(BMP bmp){

    return bmp;
}

void readMessageFromBMP(BMP bmp){

}

int getSpaceInBMP(BMP bmp){
    Histogram histogram = getHistogram(bmp);
    int total = 0;
    for (int i = 0; i < histogram.size; ++i) {
        if (histogram.histogram[i] == 0){
            total += 4;
        }
    }
    return total;
}