#include <uvsqgraphics.h>
#include "constantes.h"
#include "afficher.h"
#include "gestion_sudoku.h"
#include "lire_ecrire.h"

/*SUDOKU	jouer(SUDOKU S)
{
	POINT P = wait_clic();
	int ligne = ; // À écrire
	int colonne = ; // À écrire
	S = sudoku_modifier_case(S,i,j);
	return S;
}*/

void	sudoku_damier(SUDOKU S)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			sudoku_afficher_pb(S, i, j);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		exit(EXIT_FAILURE);
	SUDOKU S;
	S = lire_fichier(argv[1]);
	if (! S.val)
		exit(EXIT_FAILURE);
	initialiser_fenetre_graphique();
	sudoku_afficher(S);
	sudoku_damier(S);
	affiche_all();
	sudoku_free(S);
	terminer_fenetre_graphique();
}
