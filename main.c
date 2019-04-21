#include <stdio.h>

#include "BMP/Bitmap.h"
#include "StegPal/stegpal.h"

int main(int argc, char** argv) {

    if(argc < 3){
        fprintf(stderr, "ERROR not enough inputs\n");
        exit(1);
    }

    BMP test = getBMP(argv[1]);

    printf("%i bytes", getSpaceInBMP(test));

    putBMP(test, argv[2]);
    destructBMP(test);

    return 0;
}
