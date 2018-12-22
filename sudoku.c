#include <uvsqgraphics.h>
#include "constantes.h"
#include "afficher.h"
#include "gestion_sudoku.h"
#include "lire_ecrire.h"

SUDOKU	jouer(SUDOKU S)
{
	POINT	P = { -1, -1 };
	char	k = 0;
	int		a = 0; // Pour passer une adresse en paramètre (puisque la fonction ne gère pas les pointeurs NULL)
	
	wait_key_arrow_clic(&k, &a, &P);
	if (P.x != -1 && P.y != -1 && P.y <= LARGEUR) // Clic dans une case
		S = sudoku_modifier_case(S, (8 - P.y / TAILLE_CASE), P.x / TAILLE_CASE);
	else if (k == 'U')  // Undo
		S = sudoku_annule(S);
	else if (k == 'V') // Trouve
		S = sudoku_trouve(S);
	else if (k == 'S') // Sauve
		printf("Sauvegarde\n");
	else if (k == 'Q') // Quitte
		exit(EXIT_SUCCESS);
	return S;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		afficher_erreur(ERR_ARGC, 1);
	SUDOKU S;
	
	S = lire_fichier(argv[1]);
	initialiser_fenetre_graphique();
	while (1)
	{
		sudoku_afficher(S);
		affiche_all();
		S = jouer(S);
	}
	sudoku_afficher(S);
	terminer_fenetre_graphique();
}
