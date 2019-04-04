#include <stdio.h>

#include "BMP/Bitmap.h"

int main(int argc, char** argv) {

    if(argc < 3){
        fprintf(stderr, "ERROR not enough inputs");
        exit(1);
    }

    BMP bmp = getBMP(argv[1]);

    putBMP(&bmp ,argv[2]);

    return 0;
}
