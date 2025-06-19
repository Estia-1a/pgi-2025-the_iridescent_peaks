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
        fprintf(stderr,"[Erreur] Echec de la lecture de l'image : %s\n", filename);
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
        fprintf(stderr, "[Erreur] Impossible d'écrire l'image de sortie.\n");
    } else {
        printf("[Succès] Image créée : image_out.bmp(rouge uniquement)\n");
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