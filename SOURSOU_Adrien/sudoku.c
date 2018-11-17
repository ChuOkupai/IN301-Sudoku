#include<stdlib.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "afficher.h"
#include "gestion_sudoku.h"
#include "lire_ecrire.h"


int main (int argc, char *argv[]) {
    SUDOKU S;
    S = lire_fichier(argv[1]);
    initialiser_fenetre_graphique();
    sudoku_afficher(S);
    terminer_fenetre_graphique();
    exit(0);
}
