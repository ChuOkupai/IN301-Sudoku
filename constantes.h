#ifndef __CONSTANTES_H
#define __CONSTANTES_H

// Taille maximum de la pile
#define PILE_MAX 256

// Les états possibles sur les cases
#define DEPART   0
#define TRAVAIL  1
#define SOLUTION 2

// Les différentes erreurs
#define ERR_ARGC      1
#define ERR_EXTENSION 2
#define ERR_OUVERTURE 3
#define ERR_FORMAT    4
#define ERR_MALLOC    5
#define ERR_SOLUTION  6

// Les différentes tailles
#define TAILLE_CASE    80                  // La taille d'une case
#define LARGEUR        (9*TAILLE_CASE)     // La taille horizontale de la fenêtre
#define HAUTEUR        ((9+1)*TAILLE_CASE) // La taille verticale de la fenêtre
#define TAILLE_POLICE  ((2*TAILLE_CASE)/3) // La taille de la police des valeurs de départ et de travail
#define LARGEUR_TRAIT  (TAILLE_CASE/20)    // La largeur des traits principaux
#define LARGEUR_TRAIT2 (LARGEUR_TRAIT/2)   // La largeur des traits secondaires

// Les différentes couleurs
#define COUL_TITRE    0x4F7EFF // Couleur du titre
#define COUL_GAGNE    0x00D700 // Couleur du "GAGNÉ"
#define COUL_FOND     0xFFE2BB // Couleur de fond d'une case
#define COUL_FOND_PB  0xD41C00 // Couleur de fond d'un case qui ne peut plus prendre aucune valeur
#define COUL_TRAIT    0x000000 // Couleur des traits de séparation
#define COUL_DEPART   0x424242 // Couleur de la police des valeurs de départ
#define COUL_TRAVAIL  0xE28D44 // Couleur de la police des valeurs de travail
#define COUL_SOLUTION 0x9E47E8 // Couleur de la police des valeurs trouvées lors de la résolution

#endif /* constantes.h */