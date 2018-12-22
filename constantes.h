#ifndef __CONSTANTES_H
#define __CONSTANTES_H

// Taille maximum de la pile
#define PILE_MAX 512

// Les différentes erreurs
#define ERR_ARGC      "Aucun fichier à charger"
#define ERR_EXTENSION "Le fichier ne se termine pas par .sudoku"
#define ERR_OUVERTURE "Impossible d'ouvrir le fichier"
#define ERR_FORMAT    "Format non reconnu"
#define ERR_MALLOC    "Impossible d'allouer la mémoire"
#define ERR_SOLUTION  "Solution impossible"
#define ERR_PVIDE     "Aucune action à annuler"

// Les différentes tailles
#define TAILLE_CASE    80                  // La taille d'une case
#define LARGEUR        (9*TAILLE_CASE)     // La taille horizontale de la fenêtre
#define HAUTEUR        ((9+1)*TAILLE_CASE) // La taille verticale de la fenêtre
#define TAILLE_POLICE  ((2*TAILLE_CASE)/3) // La taille de la police des valeurs de départ et de travail
#define LARGEUR_TRAIT  (TAILLE_CASE/20)    // La largeur des traits principaux
#define LARGEUR_TRAIT2 (LARGEUR_TRAIT/2)   // La largeur des traits secondaires

// Les différentes couleurs
#define COUL_TITRE       0x7D75FF // Couleur du titre
#define COUL_FOND        0xFFE2BB // Couleur de fond d'une case
#define COUL_FOND_PB     0xD41C00 // Couleur de fond d'un case qui ne peut plus prendre aucune valeur
#define COUL_TRAIT       0x000000 // Couleur des traits de séparation
#define COUL_VAL_DEPART  0x424242 // Couleur de la police des valeurs de départ
#define COUL_VAL_TRAVAIL 0xE28D44 // Couleur de la police des valeurs de travail

#endif /* constantes.h */