#include <uvsqgraphics.h>
#include "constantes.h"
#include "afficher.h"
#include "gestion_sudoku.h"
#include "lire_ecrire.h"

/*SUDOKU jouer(SUDOKU S)
{
	POINT P = wait_clic();
	int ligne = ; // À écrire
	int colonne = ; // À écrire
	S = sudoku_modifier_case(S,i,j);
	return S;
}*/

int main(int argc, char **argv)
{
	if (argc < 2)
		exit(1);
	SUDOKU S;
	S = lire_fichier(argv[1]);
		printf("S.save=%d\n", S.save);
	//initialiser_fenetre_graphique();
	//sudoku_afficher(S);
	//terminer_fenetre_graphique();
	exit(0);
}
