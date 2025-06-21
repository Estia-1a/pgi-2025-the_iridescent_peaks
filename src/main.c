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
  return 0;


  if ( strncmp( configuration.command, "mirror_total", 24 ) == 0 ) {
    mirror_total( configuration.filenames[0]);
  }

  if (strncmp(configuration.command, "crop_and_resize", 25) == 0) {
    int center_x = atoi(configuration.arguments[0]);
    int center_y = atoi(configuration.arguments[1]);
    int target_width = atoi(configuration.arguments[2]);
    int target_height = atoi(configuration.arguments[3]);

    crop_and_resize(configuration.filenames[0], center_x, center_y, target_width, target_height);
}

if (strncmp(configuration.command, "scale_nearest", 26) == 0) {
    float scale_factor = strtof(configuration.arguments[0], NULL);
    char* input_file = configuration.filenames[0];

    scale_nearest(input_file, scale_factor);
}

if (strncmp(configuration.command, "scale_bilinear", 27) == 0) {
    float scale_factor = atof(configuration.arguments[0]);
    const char* input_file = configuration.filenames[0];
    scale_bilinear(input_file, scale_factor);
}

}

/*
./build/freud.exe -f ./images/input/image.jpeg -c tenth_pixel
*/
