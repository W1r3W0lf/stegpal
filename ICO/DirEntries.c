//
// Created by wire_wolf on 4/7/19.
//

#include "DirEntries.h"
#include <stdlib.h>

ICONDIRENTRY getICONDIRENTRY(FILE* fileIn){
    ICONDIRENTRY icondirentry;
    if(fread(&icondirentry, sizeof(ICONDIRENTRY), 1, fileIn) != 1 ){
        fprintf(stderr, "Error reading ICONDIRENTRY from file\n");
        exit(1);
    }
    return icondirentry;
}

void putICONDIRENTRY(ICONDIRENTRY icondirentry, FILE* fileOut){
    if(fwrite(&icondirentry, sizeof(ICONDIRENTRY), 1, fileOut) != 1 ){
        fprintf(stderr, "Error writing ICONDIRENTRY from file\n");
        exit(1);
    }
}