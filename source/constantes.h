#ifndef __CONSTANTES_H
#define __CONSTANTES_H

// Les différentes tailles
#define TAILLE_CASE   81                  // La taille d'une case
#define LARGEUR       (9*TAILLE_CASE)     // La taille horizontale de la fenêtre
#define HAUTEUR       ((9+1)*TAILLE_CASE) // La taille verticale de la fenêtre
#define TAILLE_POLICE ((2*TAILLE_CASE)/3) // La taille de la police des valeurs de départ et de travail
#define LARGEUR_TRAIT (TAILLE_CASE/27)    // La largeur des traits de séparation

// Les différentes couleurs
#define COUL_TITRE       0x7D75FF // Couleur du titre
#define COUL_FOND        0xE9BC89 // Couleur de fond d'une case
#define COUL_FOND_PB     0xFF2200 // Couleur de fond d'un case qui ne peut plus prendre aucune valeur
#define COUL_TRAIT       0x000000 // Couleur des traits de séparation
#define COUL_VAL_DEPART  0x000042 // Couleur de la police des valeurs de départ
#define COUL_VAL_TRAVAIL 0xBFBFBF // Couleur de la police des valeurs de travail

#endif /* constantes.h */