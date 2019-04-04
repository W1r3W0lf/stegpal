//
// Created by wire_wolf on 4/3/19.
//
#include "DIBHeader.h"

#include <stdio.h>
#include <stdlib.h>

DIBHeader constructDIBHeader(){
    DIBHeader dibHeader;
    dibHeader.type = 0;
    dibHeader.core = NULL;
    dibHeader.info = NULL;
    dibHeader.v4   = NULL;
    dibHeader.v5   = NULL;
    return dibHeader;
}

void destructDIBHeader(DIBHeader dibHeader){
    free(getDIBPtr(dibHeader));
}

DIBHeader getDIBHeader(FILE *input){
    DIBHeader dibHeader = constructDIBHeader();

    fpos_t pos;
    int8_t size;

    // save and restore the position of the file stream to see the size of the DIBHeader
    fgetpos(input, &pos);
    fread(&size, 1, 1, input);
    fsetpos(input, &pos);

    void* dibOut;

    switch(size){
        case core:
            dibHeader.type = core;
            dibHeader.core = malloc(size);
            dibOut = dibHeader.core;
            break;
        case info:
            dibHeader.type = info;
            dibHeader.info = malloc(size);
            dibOut = dibHeader.info;
            break;
        case v4:
            dibHeader.type = v4;
            dibHeader.v4   = malloc(size);
            dibOut = dibHeader.v4;
            break;
        case v5:
            dibHeader.type = v5;
            dibHeader.v5   = malloc(size);
            dibOut = dibHeader.v5;
            break;
        default:
            fprintf(stderr, "ERROR READING DIBHeader unknown DIBHeaderType %i \n" , size);
            exit(1);
    }

    if(fread(dibOut, size, 1, input)){
        fprintf(stderr, "Failed to read DIBHeader from file\n");
        exit(1);
    }

    return dibHeader;
}

void* getDIBPtr(DIBHeader dibHeader){
    switch (dibHeader.type){
        case core:
            return dibHeader.core;
        case info:
            return dibHeader.info;
        case v4:
            return dibHeader.v4;
        case v5:
            return dibHeader.v5;
    }
}


void putDIBHeader( DIBHeader dibHeader, FILE *output){
    if (fwrite(getDIBPtr(dibHeader), dibHeader.type, 1, output)){
        fprintf(stderr, "Failed to write DIBHeader of type %i\n", dibHeader.type);
        exit(1);
    }
}