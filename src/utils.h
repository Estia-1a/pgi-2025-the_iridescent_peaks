#ifndef UTILS_H
#define UTILS_H


typedef struct _pixelRGB {
   char G ;
   char B ;
   char R ; 
} pixelRGB ;

pixelRGB* get_pixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int channel_count, const unsigned int x, const unsigned int y);
void print_pixel(char *filename,int x, int y);


#endif