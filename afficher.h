#include "gestion_sudoku.h"

#ifndef __AFFICHER_H
#define __AFFICHER_H

// Fonction a appeler au début poour créer la fenêtre grapĥique
void	initialiser_fenetre_graphique();

// Fonction qui affiche l'état courant du sudoku
void	sudoku_afficher(SUDOKU S);

// Affiche "GAGNÉ" sur l'écran
void	sudoku_affiche_gagne();

#endif /* afficher.h */