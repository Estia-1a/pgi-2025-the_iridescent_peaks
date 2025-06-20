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

#endif