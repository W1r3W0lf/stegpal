//
// Created by wire_wolf on 4/2/19.
//

#include "Pixels.h"

#include <stdlib.h>

Pixels constructPixels(){
    Pixels pixels;
    pixels.width = 0;
    pixels.height = 0;
    pixels.size = 0;
    pixels.bits = 0;
    pixels.pixels = NULL;
    return pixels;
}

void destructPixels(Pixels pixels){
    pixels.width = 0;
    pixels.height = 0;
    pixels.size = 0;
    pixels.bits = 0;
    free(pixels.pixels);
}


Pixels getPixels(DIBHeader dibHeader ,FILE *fileIn){
    Pixels pixels = constructPixels();

    switch (dibHeader.type){
        case core:
            pixels.bits = dibHeader.core->bcBitCount;
            pixels.height = dibHeader.core->bcHeight;
            pixels.width = dibHeader.core->bcWidth;
            int rowSizeCore = (int)(1+((pixels.bits * pixels.width -1))/32.0)*4;
            pixels.size = rowSizeCore * pixels.height;
            break;
        case info:
            pixels.bits = dibHeader.info->biBitCount;
            pixels.height = dibHeader.info->biHeight;
            pixels.width = dibHeader.info->biWidth;
            int rowSizeInfo = (int)(1+((pixels.bits * pixels.width -1))/32.0)*4;
            pixels.size = rowSizeInfo * pixels.height;
            break;
        case v4:
            pixels.bits = dibHeader.v4->bV4BitCount;
            pixels.height = dibHeader.v4->bV4Height;
            pixels.width = dibHeader.v4->bV4Height;
            pixels.size = dibHeader.v4->bV4SizeImage;
            break;
        case v5:
            pixels.bits = dibHeader.v5->bV5BitCount;
            pixels.height = dibHeader.v5->bV5Height;
            pixels.width = dibHeader.v5->bV5Height;
            pixels.size =dibHeader.v5->bV5SizeImage;
            break;
    }



    pixels.pixels = malloc(pixels.size);

    if (fread(pixels.pixels, pixels.size, 1, fileIn) != 1){
        fprintf(stderr, "ERROR reading Pixels h%i w%i s%i b%i \n", pixels.height, pixels.width, pixels.size, pixels.bits);
        exit(1);
    }

    return pixels;
}


void putPixels(Pixels pixels ,FILE *fileOut){
    if (fwrite(pixels.pixels, pixels.size, 1, fileOut) != 1){
        fprintf(stderr, "ERROR writhing Pixels\n");
        exit(1);
    }
}