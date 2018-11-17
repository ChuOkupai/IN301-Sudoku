#include "gestion_sudoku.h"
#include <stdlib.h>

int	valGrille(SUDOKU S, int i, int j)
{
	// Si c'est un chiffre, le renvoie
	if (S.val[i][j] < 10)
		return S.val[i][j];
	// Sinon retourne la valeur - 48 (équivalent à '0' ou 110000 en binaire)
	return S.val[i][j] ^ 48;
}

SUDOKU	mallocSUDOKU()
{
	SUDOKU S;
	
	S.val = (char**)malloc(9 * sizeof(char*));
	if (! S.val)
		return S; // erreur allocation mémoire
	for (int i = 0; i < 9; i++)
	{
		S.val[i] = (char*)malloc(9 * sizeof(char));
		if (! S.val[i])
			return S; // erreur allocation mémoire
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
		return P; // erreur allocation mémoire
	P->premiere = NULL;
	return P;
}

void	push(PILE *P, SUDOKU S)
{
	if (! P || ! S.val)
		return;
	GRILLE *G;
	
	G = malloc(sizeof(GRILLE*));
	if (! G)
		return; // erreur allocation mémoire
	G->val = S.val;
	G->suivante = P->premiere;
	P->premiere = G;
}

void	pop(PILE *P)
{
	if (! P || ! P->premiere)
		return;
	GRILLE *G;
	
	G = P->premiere;
	P->premiere = G->suivante;
	free(G);
}

char**	pick(PILE *P)
{
	if (! P || P->premiere)
		return NULL;
	return P->premiere->val;
}

void	freePILE(PILE *P)
{
	if (! P || ! P->premiere)
		return;
	while (P->premiere)
		pop(P);
}