#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <estia-image.h>
#include <getopt.h>
#include "features.h"
#include "utils.h"
#include "argsparse.h"
 
int main(int argc, char **argv) {
  /*To use debug mode:
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */
 
  /*DO NOT EDIT THIS PART*/
  Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
  /* END */
 
  /* Use "if ( strncmp( command, <commandname>, 9 ) == 0 )" to check if your <commandname> is called by program.*/
  /* Example with helloworld command
   * If helloworld is a called command: freud.exe -f images/input/image.jpeg -c helloworld
   */
 
 
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }
 
  if ( strncmp( configuration.command, "color_red", 9) == 0){
    if (configuration.filenames[0]== NULL){
      fprintf(stderr,"Aucune image fourni.\n");
      return 1;
    }
    color_red(configuration.filenames[0]);
  }
  else if ( strncmp( configuration.command, "print_pixel", 11) == 0){
    int arg_count = 0;
    while (configuration.arguments[arg_count] != NULL){
      arg_count++;
    }
    if (arg_count < 2){
      fprintf(stderr,"fournir les coordonées X et Y.\n");
      return 1;
    }
    int x =atoi(configuration.arguments[0]);
    int y =atoi(configuration.arguments[1]);
    print_pixel(configuration.filenames[0], x, y);
  }
  else if ( strncmp( configuration.command, "color_green", 11) == 0){
    if (configuration.filenames[0]== NULL){
      fprintf(stderr,"Aucune image fourni.\n");
      return 1;
    }
    color_green(configuration.filenames[0]);
  }
  else if ( strncmp( configuration.command, "color_blue", 10) == 0){
    if (configuration.filenames[0]== NULL){
      fprintf(stderr,"Aucune image fourni.\n");
      return 1;
    }
    color_blue(configuration.filenames[0]);
  }
  else if ( strncmp( configuration.command, "color_gray", 10) == 0){
    if (configuration.filenames[0]== NULL){
      fprintf(stderr,"Aucune image fourni.\n");
      return 1;
    }
    color_gray(configuration.filenames[0]);
  }
  else if ( strncmp( configuration.command, "color_invert", 12) == 0){
    if (configuration.filenames[0]== NULL){
      fprintf(stderr,"Aucune image fourni.\n");
      return 1;
    }
    color_invert(configuration.filenames[0]);
  }
  if (strncmp(configuration.command, "color_grey_luminance", 21)==0) {
  color_grey_luminance(configuration.filenames[0]);
  }
  else if (strncmp(configuration.command, "mirror_total", 12) == 0){
    if (configuration.filenames[0] == NULL){
      fprintf(stderr, "Aucune image fournie.\n");
      return 1 ;
    }
    mirror_total(configuration.filenames[0]);
  }
 
  if ( strncmp( configuration.command, "dimension", 9) == 0 ) {
      dimension( configuration.filenames[0] );
  }
 
  if ( strncmp( configuration.command, "first_pixel", 11 ) == 0 ) {
      first_pixel( configuration.filenames[0] );
  }
 
 
  if ( strncmp( configuration.command, "tenth_pixel", 11)== 0 ) {
      tenth_pixel( configuration.filenames[0] );
  }
 
 
  if ( strncmp( configuration.command, "max_pixel", 9) == 0 ) {
    max_pixel( configuration.filenames[0] );
  }
 
  if ( strncmp( configuration.command, "min_pixel", 9 ) == 0 ) {
    min_pixel(configuration.filenames[0] );
  }
 
  if ( strncmp( configuration.command, "max_component", 13) == 0) {
    max_component(configuration.filenames[0], configuration.command[14] );
  }
 
  if ( strncmp( configuration.command, "min_component", 13) == 0) {
    min_component(configuration.filenames[0], configuration.command[14] );
  }
 
  if ( strncmp( configuration.command, "stat_report", 11) == 0) {
    stat_report(configuration.filenames[0]);
  }
  if (strncmp(configuration.command, "scale_crop", 10) == 0) {
    if (configuration.filenames[0] == NULL) {
        fprintf(stderr, "Aucune image fournie.\n");
        return 1;
    }
    if (configuration.arguments[0] == NULL || configuration.arguments[1] == NULL ||
        configuration.arguments[2] == NULL || configuration.arguments[3] == NULL) {
      fprintf(stderr, "Arguments insuffisants pour scale_crop\n");
      return 1;
    }
 
    int center_x = atoi(configuration.arguments[0]);
    int center_y = atoi(configuration.arguments[1]);
    int crop_width = atoi(configuration.arguments[2]);
    int crop_height = atoi(configuration.arguments[3]);
 
    scale_crop(configuration.filenames[0], center_x, center_y, crop_width, crop_height);
  }
  if (strncmp(configuration.command, "scale_nearest", 13) == 0) {
    if (configuration.filenames[0] == NULL || configuration.arguments[0] == NULL) {
        fprintf(stderr, "Image ou facteur de redimensionnement manquant.\n");
        return 1;
    }
 
    float scale = atof(configuration.arguments[0]);
    if (scale <= 0) {
        fprintf(stderr, "Facteur de redimensionnement invalide : %f\n", scale);
        return 1;
    }
 
    scale_nearest(configuration.filenames[0], scale);
  }
  if (strncmp(configuration.command, "scale_bilinear", 14) == 0) {
    if (configuration.filenames[0] == NULL) {
        fprintf(stderr, "Aucune image fournie.\n");
        return 1;
    }
    if (configuration.arguments[0] == NULL) {
        fprintf(stderr, "Aucun facteur d'échelle fourni.\n");
        return 1;
    }
    float scale = atof(configuration.arguments[0]);
    if (scale <= 0) {
        fprintf(stderr, "Le facteur d'échelle doit être supérieur à 0.\n");
        return 1;
    }
    scale_bilinear(configuration.filenames[0], scale);
  }
  if (strncmp(configuration.command, "color_desaturate", 16) == 0) {
    if (configuration.filenames[0] == NULL) {
        fprintf(stderr, "Aucune image fournie.\n");
        return 1;
    }
    color_desaturate(configuration.filenames[0]);
  }
 
  return 0;
 
}
 
/*
./build/freud.exe -f ./images/input/image.jpeg -c tenth_pixel
*/
 