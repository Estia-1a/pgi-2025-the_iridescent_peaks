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

void mirror_total(const char *filename) {
    int w, h, ch;
    unsigned char *src = NULL;
    read_image_data((char*)filename, &src, &w, &h, &ch);

    unsigned char *dst = malloc(w * h * ch);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int src_idx = (y * w + x) * ch;
            int dst_idx = ((h - 1 - y) * w + (w - 1 - x)) * ch;
            for (int c = 0; c < ch; c++) {
                dst[dst_idx + c] = src[src_idx + c];
            }
        }
    }

    if (write_image_data("image_out.bmp", dst, w, h) != 0) {
        free_image_data(dst);
    }
    if (write_image_data("image_out.bmp", dst, w, h)) {
        printf("Image output.bmp (miroir) a ete générée\n");
    } else {
        fprintf(stderr, "Pas de mirror_total()\n");
    }


    free_image_data(src);
    free(dst);
}



void crop_and_resize(const char *filepath, int center_x, int center_y, int target_width, int target_height) {
    int img_width, img_height, num_channels;
    unsigned char *image_data = NULL;

    read_image_data((char*)filepath, &image_data, &img_width, &img_height, &num_channels);

    int half_w = target_width / 2;
    int half_h = target_height / 2;

    int crop_x_start = center_x - half_w;
    int crop_y_start = center_y - half_h;
    int crop_x_end = center_x + half_w;
    int crop_y_end = center_y + half_h;

    if (crop_x_start < 0) {
        target_width += crop_x_start;
        crop_x_start = 0;
    }
    if (crop_x_end >= img_width) {
        target_width -= (crop_x_end - img_width + 1);
    }
    if (crop_y_start < 0) {
        target_height += crop_y_start;
        crop_y_start = 0;
    }
    if (crop_y_end >= img_height) {
        target_height -= (crop_y_end - img_height + 1);
    }

    unsigned char *cropped_data = (unsigned char *)malloc(target_width * target_height * num_channels);

    for (int row = 0; row < target_height; row++) {
        for (int col = 0; col < target_width; col++) {
            int source_x = crop_x_start + col;
            int source_y = crop_y_start + row;

            int source_index = (source_y * img_width + source_x) * num_channels;
            int dest_index = (row * target_width + col) * num_channels;

            for (int ch = 0; ch < num_channels; ch++) {
                cropped_data[dest_index + ch] = image_data[source_index + ch];
            }
        }
    }
}

void scale_nearest(char* filename, float a) {
    int width, height, channels;
    unsigned char* input_data = NULL;

    read_image_data(filename, &input_data, &width, &height, &channels);

    int scaled_w = (int)(width * a);
    int scaled_h = (int)(height * a);

    unsigned char* output_data = (unsigned char*)malloc(scaled_w * scaled_h * channels);

    for (int j = 0; j < scaled_h; j++) {
        for (int i = 0; i < scaled_w; i++) {
            int nearest_x = (int)(i / a);
            int nearest_y = (int)(j / a);

            int src_idx = (nearest_y * width + nearest_x) * channels;
            int dst_idx = (j * scaled_w + i) * channels;

            for (int c = 0; c < channels; c++) {
                output_data[dst_idx + c] = input_data[src_idx + c];
            }
        }
    }

    if (write_image_data("image_out.bmp", output_data, scaled_w, scaled_h) == 0) {
        free(output_data);
    }

    free_image_data(input_data);
}

void scale_bilinear(const char *filename, float scale) {
    int width, height, channels;
    unsigned char* input_data = NULL;

    read_image_data((char*)filename, &input_data, &width, &height, &channels);

    int resized_w = (int)(width * scale);
    int resized_h = (int)(height * scale);

    unsigned char* output = (unsigned char*)malloc(resized_w * resized_h * channels);

    for (int y = 0; y < resized_h; y++) {
        for (int x = 0; x < resized_w; x++) {

            float src_x = x / scale;
            float src_y = y / scale;

            int x1 = (int)src_x;
            int y1 = (int)src_y;

            int x2 = (x1 + 1 < width)  ? x1 + 1 : x1;
            int y2 = (y1 + 1 < height) ? y1 + 1 : y1;

            float dx = src_x - x1;
            float dy = src_y - y1;

            for (int c = 0; c < channels; c++) {
                float top_left     = input_data[(y1 * width + x1) * channels + c];
                float top_right    = input_data[(y1 * width + x2) * channels + c];
                float bottom_left  = input_data[(y2 * width + x1) * channels + c];
                float bottom_right = input_data[(y2 * width + x2) * channels + c];

                float interpolated_value =
                    (1 - dx) * (1 - dy) * top_left +
                    dx * (1 - dy) * top_right +
                    (1 - dx) * dy * bottom_left +
                    dx * dy * bottom_right;

                output[(y * resized_w + x) * channels + c] = (unsigned char)(interpolated_value);
            }
        }
    }

    if (write_image_data("image_out.bmp", output, resized_w, resized_h) == 0) {
        free(output);
    }

    free_image_data(input_data);
}


