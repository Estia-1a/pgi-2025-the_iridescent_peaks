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
