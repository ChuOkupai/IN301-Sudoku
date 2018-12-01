#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_sudoku.h"

SUDOKU	lire_fichier(char *nom)
{
	FILE	*F;
	SUDOKU	S;
	int		c, i, j, travail;
	
	S.val = NULL;
	if (! strstr(nom, ".sudoku\0"))
		exit(EXIT_FAILURE); // Erreur nom fichier
	S = sudoku_malloc();
	S.nom = nom;
	F = fopen(nom, "r");
	if (! F)
		exit(EXIT_FAILURE); // Fichier inexistant
	i = 0;
	j = 0;
	travail = 0;
	for (c = fgetc(F); c != EOF && i < 9; c = fgetc(F))
	{
		if (c == '*')
			travail = 1;
		else if ((c >= '0' && c <= '9') || c == '.')
		{
			S.val[i][j] = (c == '.') ? 0 : c ^ 48;
			S.travail[i][j] = (travail ||c == '.') ? 1 : 0;
			travail = 0;
			j++;
		}
		if (j == 9)
		{
			i++;
			j = 0;
		}
	}
	fclose(F);
	return S;
}

void	ecrire_fichier(SUDOKU *S)
{
	(void)S;
}