//
// Created by wire_wolf on 4/3/19.
//

#include "FileHeader.h"

#include <stdio.h>
#include <stdlib.h>

BITMAPFILEHEADER getBMPHead(FILE* fileIn){
    BITMAPFILEHEADER bmpFileHeader;
    if (fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, fileIn) != 1 ){
        fprintf(stderr, "Error reading BMPHeader from file\n");
        exit(1);
    }
    return bmpFileHeader;
}

void putBMPHead(BITMAPFILEHEADER fileHeader, FILE* fileOut){
    if(fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fileOut) != 1){
        fprintf(stderr, "Error writing BMPHeader to file\n");
        exit(1);
    }
}