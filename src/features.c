#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
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