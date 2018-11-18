#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_sudoku.h"

SUDOKU	lire_fichier(char *nom)
{
	FILE	*F;
	SUDOKU	S;
	int		c, i, j, travail;
	
	S = mallocSUDOKU();
	if (! strstr(nom, ".sudoku")){printf("Erreur nom fichier!\n");
		return S;} // Erreur nom fichier
	F = fopen(nom, "r");
	if (! F)
		return S;
	while (*nom && (*nom < '0' || *nom > '9'))
		nom++;
	printf("%s\n", nom);
	S.save = atoi(nom);
	i = 0;
	j = 0;
	travail = 0;
	for (c = fgetc(F); c != EOF && i < 9 && j < 9; c = fgetc(F))
	{
		if (c == '*')
			travail = 1;
		else if (c >= '0' && c <= '9')
		{
			S.val[i][j] = (travail) ? c ^ 48: c;
			if (travail)
				travail = 0;
			j++;
		}
		else if (c == '.')
		{
			if (! travail)
			{
				// erreur syntaxe
			}
			else
				S.val[i][j] = 0;
			j++;
		}
		if (j == 9)
		{
			i++;
			j = 0;
		}
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			printf("%d", VAL(i, j));
		}
		printf("\n");
	}
	fclose(F);
	return S;
}

void	ecrire_fichier(SUDOKU S)
{
	
}