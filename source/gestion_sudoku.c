#include "gestion_sudoku.h"
#include <stdlib.h>

int	valGrille(SUDOKU S, int i, int j)
{
	// Si c'est un chiffre, le renvoie
	if (S.grille[i][j] < 10)
		return S.grille[i][j];
	// Sinon retourne la valeur - 48 (équivalent à '0' ou 110000 en binaire)
	return S.grille[i][j] ^ 48;
}

PILE*	creerPILE()
{
	PILE *P;
	
	P = malloc(sizeof(PILE*));
	if (! P)
		return P; // erreur allocation mémoire
	P->premiere[0] = NULL;
	P->save = 0;
	return P;
}

void	push(PILE *P, SUDOKU *S)
{
	if (! P)
		return;
	S->suivant = P->premiere[0];
	P->premiere[0] = S->grille;
}

void	pop(PILE *P)
{
	if (! P)
		return;
	if (! P->premiere)
		return;
	char **premiere;
	
	premiere = P->premiere[0];
	P->premiere[0] = premiere->suivante[0];
	free(premiere);
}

char**	pick(PILE *P)
{
	return (P) ? P->premiere[0] : NULL;
}

void	supprimerPile(PILE *P)
{
	if (! P)
		return;
	while (P->premiere[0])
		pop(P);
}