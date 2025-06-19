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

  return 0;
}
