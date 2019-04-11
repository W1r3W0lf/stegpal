//
// Created by wire_wolf on 4/7/19.
//

#include "IconImages.h"
#include <stdlib.h>


ICONIMAGE constructICONIMAGE(){
    ICONIMAGE iconimage;
    iconimage.colorSize = 0;
    iconimage.icColors = NULL;
    iconimage.xorSize = 0;
    iconimage.icXOR = NULL;
    iconimage.andSize = 0;
    iconimage.icAND = NULL;
    return iconimage;
}


void destructICONIMAGE(ICONIMAGE iconimage){
    if (iconimage.icColors){
        free(iconimage.icColors);
    }
    if (iconimage.icXOR){
        free(iconimage.icXOR);
    }
    if (iconimage.icAND){
        free(iconimage.icAND);
    }
}


ICONIMAGE getICONIMAGE(FILE* fileIn){
    ICONIMAGE iconimage = constructICONIMAGE();

    if (fread(&iconimage.icHeader, sizeof(BITMAPINFOHEADER), 1, fileIn) != 1){
        fprintf(stderr, "ERROR reading ICONIMAGE INFOHEADER from file\n");
        exit(1);
    }

    iconimage.colorSize = iconimage.icHeader.biClrUsed;
    iconimage.icColors = malloc(iconimage.colorSize);

    if (fread(iconimage.icColors, iconimage.colorSize, 1, fileIn) != 1){
        fprintf(stderr, "ERROR reading ICONIMAGE Color table from file\n");
        exit(1);
    }

    // TODO find the size of icXOR and icAND
    // I am thinking it's the size of the image.

    // the XOR mask should follow the same bit depth as the image
    iconimage.xorSize = iconimage.icHeader.biSizeImage;
    iconimage.icColors = malloc(iconimage.xorSize);

    if (fread(iconimage.icColors, iconimage.xorSize, 1, fileIn) != 1){
        fprintf(stderr, "ERROR reading ICONIMAGE XOR table from file\n");
        exit(1);
    }

    // the AND mask should have one bit per pixel.
    iconimage.andSize = iconimage.icHeader.biWidth * iconimage.icHeader.biHeight;
    iconimage.icColors = malloc(iconimage.andSize);

    if (fread(iconimage.icColors, iconimage.andSize, 1, fileIn) != 1){
        fprintf(stderr, "ERROR reading ICONIMAGE AND table from file\n");
        exit(1);
    }

    return iconimage;
}


void putICONIMAGE(ICONIMAGE iconimage, FILE* fileOut){
    if(fwrite(&iconimage, sizeof(ICONIMAGE), 1, fileOut) != 0){
        fprintf(stderr, "ERROR writing ICONIMAGE to file\n");
        exit(1);
    }
}