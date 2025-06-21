#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();
void color_red(char *filename);
void color_green(const char *filename);
void color_blue(const char *filename);
void color_gray(const char *filename);
void color_invert(const char *filename);

void dimension (char *source_path);

void first_pixel (char *source_path);

void tenth_pixel (char *source_path);

void second_line(char *source_path);
void max_pixel (char *source_path);

void min_pixel (char *source_path);
void max_component(char *source_path, char component);

void min_component(char *source_path, char component);

void stat_report(char *source_path);
void color_grey_luminance (char *chemin_image);

void mirror_total(const char *filename);
void crop_and_resize(const char* filepath, int center_x, int center_y, int target_width, int target_height);
void scale_nearest(char* filename, float scale_ratio);
void scale_bilinear(const char *filename, float scale);


#endif