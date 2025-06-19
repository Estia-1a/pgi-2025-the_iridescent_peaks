#ifndef UTILS_H
#define UTILS_H


typedef struct _pixelRGB {
   char G ;
   char B ;
   char R ; 
} pixelRGB ;

pixelRGB* get_pixel(char* data, const int width, const int height, const int channel_count, const int x, const int y);
void print_pixel(char *filename,int x, int y);


#endif
