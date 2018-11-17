#include <stdio.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "gestion_sudoku.h"

void initialiser_fenetre_graphique() {
	init_graphics(LARGEUR,HAUTEUR);
	affiche_auto_off();
}

void terminer_fenetre_graphique() {
	wait_escape();
}


void sudoku_afficher(SUDOKU S) {
}
