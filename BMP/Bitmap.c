//
// Created by wire_wolf on 4/3/19.
//

#include "Bitmap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

BMP constructBMP(){
    BMP bmp;
    memset(&bmp.bmpDIBHeader, 0, sizeof(BITMAPFILEHEADER));
    bmp.bmpDIBHeader    = constructDIBHeader();
    bmp.bmpPalette      = constructPalette();
    bmp.bmpGap1         = constructGap();
    bmp.bmpPixels       = constructPixels();

    return bmp;
}

void destructBMP(BMP bmp){
    destructDIBHeader(bmp.bmpDIBHeader);
    destructPalette(bmp.bmpPalette);
    destructGap(bmp.bmpGap1);
    destructPixels(bmp.bmpPixels);
}

BMP getBMP(char* fileName){
    FILE* fileIn = fopen(fileName, "r");

    BMP bmp = constructBMP();
    bmp.bmpFileHeader   = getBMPHead(fileIn);
    bmp.bmpDIBHeader    = getDIBHeader(fileIn);
    bmp.bmpPalette      = getPalette(bmp.bmpDIBHeader, fileIn);
    bmp.bmpGap1         = getGap1(bmp.bmpFileHeader, fileIn);
    bmp.bmpPixels       = getPixels(bmp.bmpDIBHeader , fileIn);

    fclose(fileIn);

    return bmp;
}

void copyBMP(char* nameIn, char* nameOut){
    FILE* fileIn = fopen(nameIn, "r");
    FILE* fileOut = fopen(nameOut, "w");

    BMP bmp = constructBMP();
    bmp.bmpFileHeader   = getBMPHead(fileIn);
    putBMPHead(bmp.bmpFileHeader, fileOut);
    bmp.bmpDIBHeader    = getDIBHeader(fileIn);
    putDIBHeader(bmp.bmpDIBHeader, fileOut);
    bmp.bmpPalette      = getPalette(bmp.bmpDIBHeader, fileIn);
    putPalette(bmp.bmpPalette, fileOut);
    bmp.bmpGap1         = getGap1(bmp.bmpFileHeader, fileIn);
    putGap(bmp.bmpGap1, fileOut);
    bmp.bmpPixels       = getPixels(bmp.bmpDIBHeader , fileIn);
    putPixels(bmp.bmpPixels, fileOut);

    destructBMP(bmp);

    fclose(fileIn);
    fclose(fileOut);
}


void putBMP(BMP *bmp, char* fileName) {
    FILE* fileOut = fopen(fileName, "w");

    putBMPHead(bmp->bmpFileHeader, fileOut);
    putDIBHeader(bmp->bmpDIBHeader, fileOut);
    putPalette(bmp->bmpPalette, fileOut);
    putGap(bmp->bmpGap1, fileOut);
    putPixels(bmp->bmpPixels, fileOut);

    fclose(fileOut);
}