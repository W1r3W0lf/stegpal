//
// Created by wire_wolf on 4/9/19.
//

#include "Icons.h"
#include <stdlib.h>

ICONDIR constructICONDIR(){
    ICONDIR icondir;
    icondir.idReserved  = 0;
    icondir.idType      = 0;
    icondir.idCount     = 0;
    icondir.idEntries   = NULL;
    return icondir;
}

void destructICONDIR(ICONDIR icondir){
    if(icondir.idEntries){
        free(icondir.idEntries);
    }
}

ICONDIR getICONDIR(FILE* fileIn){
    ICONDIR icondir = constructICONDIR();

    // This reads in the first three words
    if(fread(&icondir, sizeof(WORD)*3, 1, fileIn) != 1 ){
        fprintf(stderr, "ERROR reading ICONDIR 3 WORDS from file\n");
        exit(1);
    }

    icondir.idEntries = malloc(sizeof(ICONIMAGE)*icondir.idCount);

    if(fread(icondir.idEntries, sizeof(ICONIMAGE)*icondir.idCount, 1, fileIn)){
        fprintf(stderr, "ERROR reading ICONDIR IMAGES from file");
        exit(1);
    }

    return icondir;
}

void putICONDIR(ICONDIR icondir, FILE* fileOut){

}