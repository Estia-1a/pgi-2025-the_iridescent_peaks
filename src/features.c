#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.*/
 void color_red(char *filename){
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
    int success = read_image_data(filename, &data, &width, &height, &channel_count);
    if (success == 0 || data == NULL ){
        fprintf(stderr,"Echec de la lecture de l'image : %s\n", filename);
        return;
    }

    int pixel_count = width * height;
    int i;
    for (i=0; i < pixel_count; ++i){
        int index = i * channel_count;

        if (channel_count >= 3){
            data[index + 1] = 0;
            data[index + 2] = 0;
        }
    }
    int written = write_image_data("image_out.bmp", data, width, height);
    if (written == 0){
        fprintf(stderr, "Impossible d'écrire l'image de sortie.\n");
    } else {
        printf("Image créée : image_out.bmp(rouge uniquement)\n");
    }
    free(data);
 }
void color_green(const char *filename){
    unsigned char *data;
    int width, height, channel_count;
    if (read_image_data((char*)filename, &data, &width, &height, &channel_count) == 0){
        fprintf(stderr,"impossible de lire l'image.\n");
        return;
    }
    int total = width * height;
    for (int i = 0; i < total; i++){
        int idx = i * channel_count;
        if (channel_count >=3){
            data[idx + 0]=0;
            data[idx + 2]=0;
        }
    }
    if (write_image_data("image_out.bmp", data, width, height)==0){
        fprintf(stderr,"échec de l'écriture de l'image.\n");
    } else {
        printf("L'image toute verte est enregistrée sous 'image_out.bmp'.\n");
    }
    free(data);
}
 void color_blue(const char *filename){
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
    int success = read_image_data((char*)filename, &data, &width, &height, &channel_count);
    if (success == 0 || data == NULL ){
        fprintf(stderr,"Echec de la lecture de l'image : %s\n", filename);
        return;
    }

    int pixel_count = width * height;
    for (int i=0; i < pixel_count; ++i){
        int index = i * channel_count;

        if (channel_count >= 3){
            data[index + 0] = 0;
            data[index + 1] = 0;
        }
    }
    int written = write_image_data("image_out.bmp", data, width, height);
    if (written == 0){
        fprintf(stderr, "Impossible d'écrire l'image de sortie.\n");
    } else {
        printf("Image créée : image_out.bmp(toute bleue)\n");
    }
    free(data);
 }
  void color_gray(const char *filename){
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
    int success = read_image_data((char*)filename, &data, &width, &height, &channel_count);
    if (success == 0 || data == NULL ){
        fprintf(stderr,"Lecture échouée de l'image : %s\n", filename);
        return;
    }

    int pixel_count = width * height;
    for (int i=0; i < pixel_count; ++i){
        int index = i * channel_count;

        if (channel_count >= 3){
            unsigned char r = data[index + 0];
            unsigned char g = data[index + 1];
            unsigned char b = data[index + 2];
            unsigned char gray = (r + g + b) / 3;
            data[index + 0] = gray;
            data[index + 1] = gray;
            data[index + 2] = gray;
        }
    }
    int written = write_image_data("image_out.bmp", data, width, height);
    if (written == 0){
        fprintf(stderr, "Impossible d'écrire l'image de sortie.\n");
    } else {
        printf("Image créée : image_out.bmp(toute grise)\n");
    }
    free(data);
 }
  void color_invert(const char *filename){
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
    int success = read_image_data((char*)filename, &data, &width, &height, &channel_count);
    if (success == 0 || data == NULL ){
        fprintf(stderr,"Echec de la lecture de l'image : %s\n", filename);
        return;
    }

    int pixel_count = width * height;
    for (int i=0; i < pixel_count; ++i){
        int index = i * channel_count;

        if (channel_count >= 3){
            data[index + 0] = 255 -data[index + 0];
            data[index + 1] = 255 -data[index + 1];
            data[index + 2] = 255 -data[index + 2];
        }
    }
    int written = write_image_data("image_out.bmp", data, width, height);
    if (written == 0){
        fprintf(stderr, "Impossible d'écrire l'image de sortie.\n");
    } else {
        printf("Image créée : image_out.bmp(toute inversée)\n");
    }
    free(data);
 }
 /* Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension (char *source_path){
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);

    printf("dimension: %d, %d\n", width, height);

}

void first_pixel(char *source_path) {
    unsigned char *data;
    int width, height, channels;

    read_image_data(source_path, &data, &width, &height, &channels);

    printf("first_pixel: %d, %d, %d\n", data[0], data[1], data[2]);
}


void tenth_pixel (char *source_path){
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);
    printf("tenth_pixel: %d, %d, %d\n", data[27], data[28], data[29]);

}

void max_pixel(char *source_path) {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);

    int max_sum = 0;
    int best_pixel = 0;

    for (int i = 0; i < width * height; i++) {
        int r = data[i * 3];
        int g = data[i * 3 + 1];
        int b = data[i * 3 + 2];
        int sum = r + g + b;

        if (sum> max_sum) {
            max_sum = sum;
            best_pixel = i;
        }
    }

    int x = best_pixel % width;
    int y = best_pixel / width;

    printf("max_pixel (%d, %d): %d, %d, %d\n", x, y,
        data[best_pixel * 3], data [best_pixel * 3 + 1], data[best_pixel * 3 + 2]);

}

void min_pixel(char *source_path) {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);
    
    int min_sum = 1000;
    int best_pixel = 0;
    
    for (int i = 0; i < width * height; i++) {
        int sum = data[i * 3] + data[i * 3 + 1] + data[i * 3 + 2];

        if (sum < min_sum) {
            min_sum = sum;
            best_pixel = i;
        }
    }
    int x = best_pixel % width;
    int y = best_pixel / width;

    printf("min_pixel ( %d, %d): %d, %d, %d\n", x, y,
        data[best_pixel * 3], data[best_pixel * 3 + 1], data[best_pixel * 3 + 2]);

}

void max_component(char *source_path, char component) {
    unsigned char *data;
    int width, height, channels;
    int max_value = 0;
    int best_pixel = 0;
    int offset;

    read_image_data(source_path, &data, &width, &height, &channels);

    if (component == 'G') {
        offset = 1;
    } else if (component == 'B') {
        offset = 2;
    } else {
        offset = 0;
    }
    for (int i = 0; i < width * height; i++) {
            int value = data[i * 3 + offset];
            if (value > max_value) {
                max_value = value;
                best_pixel = i;
            }
        }
        
        printf("max_component %c (%d, %d): %d\n", 
            component, best_pixel % width, best_pixel / width, max_value);
        
        free(data);
    }





    void min_component(char *source_path, char component) {
    unsigned char *data;
    int width, height, channels;
    int min_value = 255;
    int best_pixel = 0;
    int offset;

    read_image_data(source_path, &data, &width, &height, &channels);

    if (component == 'G') {
        offset = 1;
    } else if (component == 'B') {
        offset = 2;
    } else {
        offset = 0;
    }
    for (int i = 0; i < width * height; i++) {
            int value = data[i * 3 + offset];
            if (value < min_value) {
                min_value = value;
                best_pixel = i;
            }
        }
        
        printf("min_component %c (%d, %d): %d\n", 
            component, best_pixel % width, best_pixel / width, min_value);
        
        free(data);
    }