#include <uvsqgraphics.h>
#include "constantes.h"
#include "afficher.h"
#include "gestion_sudoku.h"
#include "lire_ecrire.h"

SUDOKU	jouer(SUDOKU S)
{
	POINT	P;
	char	k;
	int		a; // Pour passer une adresse en paramètre (puisque la fonction ne gère pas les pointeurs NULL)
	
	P.x = -1;
	P.y = -1;
	k = 0;
	a = 0;
	wait_key_arrow_clic(&k, &a, &P);
	if (P.x != -1 && P.y != -1 && P.y <= LARGEUR)
		S = sudoku_modifier_case(S, (8 - P.y / TAILLE_CASE), P.x / TAILLE_CASE);
	else if (k == 'U')
		printf("Undo\n");
	else if (k == 'V')
		printf("Trouve\n");
	else if (k == 'S')
		printf("Sauvegarde\n");
	else if (k == 'Q')
		exit(EXIT_SUCCESS);
	return S;
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
	while (1)
	{
		sudoku_afficher(S);
		affiche_all();
		S = jouer(S);
	}
	sudoku_afficher(S);
	terminer_fenetre_graphique();
	exit(EXIT_SUCCESS);
}
