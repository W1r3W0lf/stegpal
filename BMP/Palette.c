//
// Created by wire_wolf on 4/3/19.
//

#include "Palette.h"

#include <stdlib.h>

void showRGBquad(RGBQUAD rgbquad){
    printf("RGBQuad R 0x%x G 0x%x B 0x%x 0 0x%x", rgbquad.rgbRed, rgbquad.rgbGreen ,rgbquad.rgbBlue, rgbquad.rgbReserved);
}

RGBQUAD getRGBquad(FILE *filein){
    RGBQUAD rgbquad;
    if(fread(&rgbquad, sizeof(rgbquad), 1, filein)){
        fprintf(stderr, "ERROR reading RGBquad\n");
        exit(1);
    }
    return rgbquad;
}

void putRGBQuad(RGBQUAD *rgbquad ,FILE *fileout){
    fwrite(rgbquad, sizeof(RGBQUAD), 1, fileout);
}

Palette getPalette(DIBHeader dibHeader, FILE *filein){

    Palette palette;

    switch (dibHeader.type){
        case core:
            // Find a way to determen the pallet size for core
            break;
        case info:
            palette.size = dibHeader.info->biClrUsed;
            break;
        case v4:
            palette.size = dibHeader.v4->bV4ClrUsed;
            break;
        case v5:
            palette.size = dibHeader.v5->bV5ClrUsed;
            break;
    }

    // TODO Palette I think that this might require using the heap
    if(fread(palette.pRgbquad, palette.size, 1, filein)){
        fprintf(stderr, "ERROR failed to read in palette. palette size %d\n", palette.size );
        exit(1);
    }

    return palette;
}

void putPalette(Palette palette, FILE *fileout){
    if(fwrite(palette.pRgbquad, palette.size, 1, fileout)){
        fprintf(stderr, "ERROR failed to write palette to file. palette size %d\n", palette.size);
        exit(1);
    }
}
