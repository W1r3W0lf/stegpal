//
// Created by wire_wolf on 4/7/19.
//

#include "Gap.h"
#include <stdlib.h>

Gap constructGap(){
    Gap gap;
    gap.size = 0;
    gap.value = NULL;
    return gap;
}

//TODO There is a bug with gap that causes it to crash
Gap getGap(BITMAPFILEHEADER bitmapfileheader, FILE *fileIn){
    long position = ftell(fileIn);
    Gap gap = constructGap();
    gap.size = position - bitmapfileheader.bfOffBits;

    if(!gap.size)
        return gap;

    gap.value = malloc(gap.size);

    if(fread(&gap.value, gap.size, 1, fileIn) != 0){
        fprintf(stderr, "ERROR failed to read in Gap1. Size %i\n", gap.size);
        exit(1);
    }

    return gap;
}

void putGap(Gap gap, FILE *fileOut){
    if(gap.size && fwrite(gap.value, gap.size, 1, fileOut)){
        fprintf(stderr, "ERROR failed to write Gap. Size %i\n", gap.size);
        exit(1);
    }
}


void destructGap(Gap gap){
    if(gap.size){
        free(gap.value);
    }
}