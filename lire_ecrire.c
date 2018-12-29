#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_sudoku.h"
#include "constantes.h"

// récupère le numéro de sauvegarde sur le nom du fichier
int		recupere_numero(char *nom)
{
	int		len;
	int		n;
	
	len = strlen(nom) - 7;
	if (len > 4)
		return n = atoi(nom + len - 3);
	return 0;
}

// supprime l'extension et éventuellement le numéro associé
char*	supprime_extension(char *nom)
{
	char	*dst;
	int		len;
	
	len = strlen(nom) - 7;
	if (len > 4)
	{
		int n = atoi(nom + len - 3);
		if (n && n < 1000)
			len -= 4;
	}
	dst = (char*)malloc((len + 1) * sizeof(char));
	if (! dst)
		erreur(ERR_MALLOC, 1);
	strncpy(dst, nom, len);
	dst[len] = '\0';
	printf("dst = %s\n", dst);
	return dst;
}

SUDOKU	lire_fichier(char *nom)
{
	FILE	*F;
	SUDOKU	S;
	int		c, i, j, travail;
	
	if (! strstr(nom, ".sudoku\0"))
		erreur(ERR_EXTENSION, 1);
	S = sudoku_malloc();
	S.numero = recupere_numero(nom);
	printf("n = %d\n", S.numero);
	S.nom = supprime_extension(nom);
	F = fopen(nom, "r");
	if (! F)
		erreur(ERR_OUVERTURE, 1);
	i = 0;
	j = 0;
	travail = 0;
	for (c = fgetc(F); i < 9; c = fgetc(F))
	{
		if (c == EOF)
			erreur(ERR_FORMAT, 1);
		if (c == '*')
			travail = 1;
		else if ((c >= '0' && c <= '9') || c == '.')
		{
			S.val[i][j] = (c == '.') ? 0 : c ^ 48;
			S.etat[i][j] = (travail || c == '.') ? TRAVAIL : DEPART;
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

// création d'un nouveau nom de fichier
char*	nouveau_nom(int numero, char *nom)
{
	char	*dst;
	int		len;
	
	len = strlen(nom) + 11;
	dst = (char*)malloc((len + 1) * sizeof(char));
	if (! dst)
		erreur(ERR_MALLOC, 1);
	sprintf(dst, "%s.%03d.sudoku", nom, numero);
	dst[len] = '\0';
	return dst;
}

SUDOKU	ecrire_fichier(SUDOKU S)
{
	FILE	*F;
	char	*nom;
	
	if (S.numero == 999)
		S.numero = 1;
	else
		S.numero++;
	nom = nouveau_nom(S.numero, S.nom);
	F = fopen(nom, "w");
	if (! F)
		erreur(ERR_OUVERTURE, 1);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (! S.val[i][j])
				fputc('.', F);
			else
			{
				if (S.etat[i][j])
					fputc('*', F);
				if (S.val[i][j])
					fputc(S.val[i][j] + '0', F);
			}
		}
		fputc('\n', F);
	}
	fclose(F);
	printf("information: Grille sauvegardée dans le fichier %s\n", nom);
	free(nom);
	return S;
}