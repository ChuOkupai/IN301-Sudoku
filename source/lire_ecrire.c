#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_sudoku.h"

SUDOKU	lire_fichier(char *nom)
{
	FILE	*F;
	SUDOKU	S;
	int		c, i, j;
	
	S.grille = (char**)malloc(9 * sizeof(char*));
	if (! S.grille)
		return S; // erreur allocation mémoire
	for (i = 0; i < 9; i++)
	{
		S.grille[i] = (char*)malloc(9 * sizeof(char));
		if (! S.grille[i])
			return S; // erreur allocation mémoire
	}
	return S;
}

void	ecrire_fichier(SUDOKU S)
{
	
}