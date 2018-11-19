#include "gestion_sudoku.h"
#include <stdlib.h>

SUDOKU	mallocSUDOKU()
{
	SUDOKU S;
	
	S.val = (char**)malloc(9 * sizeof(char*));
	S.travail = (char**)malloc(9 * sizeof(char*));
	if (! S.val || ! S.travail)
		exit(EXIT_FAILURE); // erreur allocation mémoire
	for (int i = 0; i < 9; i++)
	{
		S.val[i] = (char*)malloc(9 * sizeof(char));
		S.travail[i] = (char*)malloc(9 * sizeof(char));
		if (! S.val[i] || ! S.travail[i])
			exit(EXIT_FAILURE); // erreur allocation mémoire
	}
	return S;
}

void	freeSUDOKU(SUDOKU S)
{
	for(int i = 0; i < 9; i++)
		free(S.val[i]);
	free(S.val);
}

PILE*	nouvellePILE()
{
	PILE *P;
	
	P = malloc(sizeof(PILE*));
	if (! P)
		exit(EXIT_FAILURE); // erreur allocation mémoire
	P->premiere = NULL;
	return P;
}

void	push(PILE *P, SUDOKU S)
{
	if (! P || ! S.val)
		exit(EXIT_FAILURE); // Vide
	GRILLE *G;
	
	G = malloc(sizeof(GRILLE*));
	if (! G)
		exit(EXIT_FAILURE); // erreur allocation mémoire
	G->val = S.val;
	G->suivante = P->premiere;
	P->premiere = G;
}

void	pop(PILE *P)
{
	if (! P || ! P->premiere)
		exit(EXIT_FAILURE); // Vide
	GRILLE *G;
	
	G = P->premiere;
	P->premiere = G->suivante;
	free(G);
}

char**	pick(PILE *P)
{
	if (! P || P->premiere)
		exit(EXIT_FAILURE); // Vide
	return P->premiere->val;
}

void	freePILE(PILE *P)
{
	if (! P || ! P->premiere)
		exit(EXIT_FAILURE); // Vide
	while (P->premiere)
		pop(P);
}