#include <stdio.h>
#include <stdlib.h>
#include <estia-image.h>
#include "utils.h"


pixelRGB* get_pixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int channel_count, const unsigned int x, const unsigned int y){
    if (!data || x >= width || y >= height){
        return NULL;
    }


    int index = (y * width + x) * channel_count;
    return (pixelRGB*) &data[index]; 
}

void print_pixel(char *filename,int x,int y){
    char *data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) !=0 ) {
       fprintf(stderr,"Erreur lors de la lecture de l'image : %s\n",filename);
       return;
    }

    pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);

    if (!pixel){
        fprintf(stderr,"Coordonnées invalides pour le pixel (%d, %d).\n", x, y);
    } else {
        printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
    }
    free(data);
}   