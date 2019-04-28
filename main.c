#include <stdio.h>

#include "BMP/Bitmap.h"
#include "StegPal/stegpal.h"

void printSize(char* fileName){
    BMP freeBytes = getBMP(fileName);
    printf("%i free bytes\n", getSpaceInBMP(freeBytes));
    destructBMP(freeBytes);
}

void writeToBMP(char* inputFile, char* outputFile, char* message){
    BMP bmpData = getBMP(inputFile);
    writeMessageToBMP(bmpData,message);
    putBMP(bmpData, outputFile);
    destructBMP(bmpData);
}

int main(int argc, char** argv) {

    switch(argc){
        case 2:
            printSize(argv[1]);
            break;
        case 4:
            writeToBMP(argv[1],argv[2],argv[3]);
            break;
        default:
            fprintf(stderr, "ERROR wrong number of inputs\n");
            exit(1);
    }
    return 0;
}
