#include <stdio.h>

#include "BMP/Bitmap.h"

int main(int argc, char** argv) {

    if(argc < 3){
        fprintf(stderr, "ERROR not enough inputs\n");
        exit(1);
    }

    copyBMP(argv[1], argv[2]);

    return 0;
}
