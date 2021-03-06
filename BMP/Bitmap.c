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
    bmp.bmpGap          = constructGap();
    bmp.bmpPixels       = constructPixels();
    return bmp;
}


void destructBMP(BMP bmp){
    destructDIBHeader(bmp.bmpDIBHeader);
    destructPalette(bmp.bmpPalette);
    destructGap(bmp.bmpGap);
    destructPixels(bmp.bmpPixels);
}


BMP getBMP(char* fileName){
    FILE* fileIn = fopen(fileName, "r");

    BMP bmp = constructBMP();
    bmp.bmpFileHeader   = getBMPHead(fileIn);
    bmp.bmpDIBHeader    = getDIBHeader(fileIn);
    bmp.bmpPalette      = getPalette(bmp.bmpDIBHeader, fileIn);
//    bmp.bmpGap          = getGap(bmp.bmpFileHeader, fileIn);
    bmp.bmpPixels       = getPixels(bmp.bmpDIBHeader , fileIn);
    fclose(fileIn);

    return bmp;
}


void putBMP(BMP bmp, char* fileName) {
    FILE* fileOut = fopen(fileName, "w");

    putBMPHead(bmp.bmpFileHeader, fileOut);
    putDIBHeader(bmp.bmpDIBHeader, fileOut);
    putPalette(bmp.bmpPalette, fileOut);
    putGap(bmp.bmpGap, fileOut);
    putPixels(bmp.bmpPixels, fileOut);

    fclose(fileOut);
}