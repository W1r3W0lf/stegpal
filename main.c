#include <stdio.h>

#include "BMP/Bitmap.h"
#include "StegPal/Histogram.h"

int main(int argc, char** argv) {

    if(argc < 3){
        fprintf(stderr, "ERROR not enough inputs\n");
        exit(1);
    }

    BMP test = getBMP(argv[1]);

    Histogram spread = getHistogram(test);

    for (int i = 0; i < spread.size ; ++i) {
        printf("%i : %i\n",i ,  spread.histogram[i]);
    }

    putBMP(test, argv[2]);
    destructBMP(test);

    return 0;
}
