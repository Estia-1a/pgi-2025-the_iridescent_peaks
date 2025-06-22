#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
 void color_grey_luminance (char *chemin_image) {
    int largeur=0, hauteur=0, canaux=0;
    unsigned char *donnees= NULL;
    if (!read_image_data(chemin_image, &donnees, &largeur, &hauteur, &canaux)) {
        printf("impossible de charger l'image:%s\n", chemin_image);
        return;
    }
    unsigned char *curseur=donnees;
    unsigned char intensite;
    for (int px=0; px<largeur*hauteur; px++) {
        unsigned char r =*curseur;
        unsigned char g =*(curseur+1);
        unsigned char b =*(curseur+2);
 
        intensite=(unsigned char)(0.21*r+0.72*g+0.07*b);
 
        *curseur=intensite;
        *(curseur+1)=intensite;
        *(curseur+2)=intensite;
        curseur +=3;
    }
    if(write_image_data("sortie_grie.bmp", donnees, largeur, hauteur)) {
        printf("image convertie enregistrée dans sortie_gris.bmp\n");
    } else {
        printf("Erreur lors de l'enregistrement de l'image\n");
    }
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
 
void stat_report(char *source_path) {
    FILE *file = fopen("stat_report.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "erreur");
        return;
    }
 
 
    max_pixel (source_path);
    fprintf(file, "\n");
 
    min_pixel (source_path);
    fprintf(file, "\n");
 
    max_component (source_path, 'R');
    fprintf(file, "\n");
 
    max_component (source_path, 'G');
    fprintf(file, "\n");
 
    max_component (source_path, 'B');
    fprintf(file, "\n");
 
 
    min_component (source_path, 'R');
    fprintf(file, "\n");
 
    min_component (source_path, 'G');
    fprintf(file, "\n");
 
    min_component (source_path, 'B');
    fprintf(file, "\n");
 
 
 
    printf("rapport : stat_report.txt\n");
}
 
void mirror_total(char *filename) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
 
    int success = read_image_data(filename, &data, &width, &height, &channel_count);
    if (success == 0 || data == NULL) {
        fprintf(stderr, "Echec de la lecture de l'image : %s\n", filename);
        return;
    }
 
    int row_size = width * channel_count; // largeur en octets d'une ligne (sans padding)
    unsigned char *temp = malloc(height * row_size);
    if (!temp) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        free(data);
        return;
    }
 
    memcpy(temp, data, height * row_size);
 
    for (int y = 0; y < height; y++) {
        int y_mirror = height - 1 - y;
        for (int x = 0; x < width; x++) {
            int x_mirror = width - 1 - x;
 
            // source index dans temp (ligne miroir, colonne miroir)
            int src_index = (y_mirror * width + x_mirror) * channel_count;
            // destination index dans data (ligne y, colonne x)
            int dst_index = (y * width + x) * channel_count;
 
            for (int c = 0; c < channel_count; c++) {
                data[dst_index + c] = temp[src_index + c];
            }
        }
    }
 
    free(temp);
 
    int written = write_image_data("image_out.bmp", data, width, height);
    if (written == 0) {
        fprintf(stderr, "Impossible d'écrire l'image sortante.\n");
    } else {
        printf("Image creer : image_out.bmp (miroir total)\n");
    }
 
    free(data);
}



void scale_crop(char *filename, int center_x, int center_y, int crop_width, int crop_height) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
 
    int success = read_image_data(filename, &data, &width, &height, &channel_count);
    if (success == 0 || data == NULL) {
        fprintf(stderr, "Echec de la lecture de l'image : %s\n", filename);
        return;
    }
 
    int left = center_x - crop_width / 2;
    int top = center_y - crop_height / 2;
    int right = left + crop_width;
    int bottom = top + crop_height;
 
    if (left < 0) left = 0;
    if (top < 0) top = 0;
    if (right > width) right = width;
    if (bottom > height) bottom = height;
 
    int new_width = right - left;
    int new_height = bottom - top;
 
    unsigned char *cropped_data = malloc(new_width * new_height * channel_count);
    if (!cropped_data) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        free(data);
        return;
    }
 
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            for (int c = 0; c < channel_count; c++) {
                cropped_data[(y * new_width + x) * channel_count + c] =
                    data[((y + top) * width + (x + left)) * channel_count + c];
            }
        }
    }
 
    int written = write_image_data("image_out.bmp", cropped_data, new_width, new_height);
    if (written == 0) {
        fprintf(stderr, "Impossible d'écrire l'image sortante.\n");
    } else {
        printf("Image creer : image_out.bmp (crop)\n");
    }
 
    free(data);
    free(cropped_data);
}

void scale_nearest(char *filename, float scale) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
 
    int success = read_image_data(filename, &data, &width, &height, &channel_count);
    if (success == 0 || data == NULL) {
        fprintf(stderr, "Erreur de lecture de l'image : %s\n", filename);
        return;
    }
 
    int new_width = (int)(width * scale);
    int new_height = (int)(height * scale);
 
    unsigned char *scaled_data = malloc(new_width * new_height * channel_count);
    if (!scaled_data) {
        fprintf(stderr, "Erreur d'allocation mémoire pour l'image redimensionnée.\n");
        free(data);
        return;
    }
 
    for (int y = 0; y < new_height; y++) {
        int src_y = (int)(y / scale);
        if (src_y >= height) src_y = height - 1;
 
        for (int x = 0; x < new_width; x++) {
            int src_x = (int)(x / scale);
            if (src_x >= width) src_x = width - 1;
 
            for (int c = 0; c < channel_count; c++) {
                scaled_data[(y * new_width + x) * channel_count + c] =
                    data[(src_y * width + src_x) * channel_count + c];
            }
        }
    }
 
    int written = write_image_data("image_out.bmp", scaled_data, new_width, new_height);
    if (written == 0) {
        fprintf(stderr, "Impossible d'écrire l'image sortante.\n");
    } else {
        printf("Image creer : image_out.bmp (redimensionnée x%.2f)\n", scale);
    }
 
    free(data);
    free(scaled_data);
}

void scale_bilinear(char *filename, float scale) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
 
    int success = read_image_data(filename, &data, &width, &height, &channel_count);
    if (success == 0 || data == NULL) {
        fprintf(stderr, "Echec de la lecture de l'image : %s\n", filename);
        return;
    }
 
    int new_width = (int)(width * scale);
    int new_height = (int)(height * scale);
 
    unsigned char *scaled_data = malloc(new_width * new_height * channel_count);
    if (scaled_data == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        free(data);
        return;
    }
 
    for (int y = 0; y < new_height; y++) {
        float src_y = y / scale;
        int y0 = (int)src_y;
        int y1 = y0 + 1;
        float dy = src_y - y0;
 
        if (y1 >= height) y1 = height - 1;
 
        for (int x = 0; x < new_width; x++) {
            float src_x = x / scale;
            int x0 = (int)src_x;
            int x1 = x0 + 1;
            float dx = src_x - x0;
 
            if (x1 >= width) x1 = width - 1;
 
            for (int c = 0; c < channel_count; c++) {
                float v00 = data[(y0 * width + x0) * channel_count + c];
                float v10 = data[(y0 * width + x1) * channel_count + c];
                float v01 = data[(y1 * width + x0) * channel_count + c];
                float v11 = data[(y1 * width + x1) * channel_count + c];
 
                float val = (1 - dx) * (1 - dy) * v00 +
                            dx * (1 - dy) * v10 +
                            (1 - dx) * dy * v01 +
                            dx * dy * v11;
 
                scaled_data[(y * new_width + x) * channel_count + c] = (unsigned char)(val);
            }
        }
    }
 
    int written = write_image_data("image_out.bmp", scaled_data, new_width, new_height);
    if (written == 0) {
        fprintf(stderr, "Impossible d'écrire l'image sortante.\n");
    } else {
        printf("Image creer : image_out.bmp (bilinear, facteur %.2f)\n", scale);
    }
 
    free(data);
    free(scaled_data);
}
 
void color_desaturate(char *filename) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
 
    int success = read_image_data(filename, &data, &width, &height, &channel_count);
    if (success == 0 || data == NULL) {
        fprintf(stderr, "Échec de la lecture de l'image : %s\n", filename);
        return;
    }
 
    int pixel_count = width * height;
 
    for (int i = 0; i < pixel_count; ++i) {
        int index = i * channel_count;
 
        if (channel_count >= 3) {
            unsigned char r = data[index];
            unsigned char g = data[index + 1];
            unsigned char b = data[index + 2];
 
            unsigned char min_val = (r < g) ? ((r < b) ? r : b) : ((g < b) ? g : b);
            unsigned char max_val = (r > g) ? ((r > b) ? r : b) : ((g > b) ? g : b);
            unsigned char new_val = (min_val + max_val) / 2;
 
            data[index]     = new_val;
            data[index + 1] = new_val;
            data[index + 2] = new_val;
        }
    }
 
    int written = write_image_data("image_out.bmp", data, width, height);
    if (written == 0) {
        fprintf(stderr, "Impossible d'écrire l'image sortante.\n");
    } else {
        printf("Image creer : image_out.bmp (désaturer)\n");
    }
 
    free(data);
}


