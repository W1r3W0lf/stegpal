//
// Created by wire_wolf on 4/7/19.
//

#include "IconImages.h"
#include <stdlib.h>


ICONIMAGE getICONIMAGE(FILE* fileIn){
    ICONIMAGE iconimage;
    if(fread(&iconimage, sizeof(ICONIMAGE), 1, fileIn) != 0){
        fprintf(stderr, "ERROR reading ICONIMAGE from file\n");
        exit(1);
    }
    return iconimage;
}


int getICONIMAGEsize(DIBHeader dibHeader){
    switch (dibHeader.type){
        case core:
            // I don't think this will work for core
            return dibHeader.core->bcSize;
        case info:
            return dibHeader.info->biSizeImage;
        case v4:
            return dibHeader.v4->bV4SizeImage;
        case v5:
            return dibHeader.v5->bV5SizeImage;
    }
}


void putICONIMAGE(ICONIMAGE iconimage, FILE* fileOut){
    if(fwrite(&iconimage, sizeof(ICONIMAGE), 1, fileOut) != 0){
        fprintf(stderr, "ERROR writing ICONIMAGE to file\n");
        exit(1);
    }
}