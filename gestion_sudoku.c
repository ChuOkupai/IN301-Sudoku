#include "gestion_sudoku.h"
#include <stdlib.h>

// Stocke une ancienne grille
struct grille
{
	int		**val;       // Stocke les valeurs
	GRILLE	*precedente; // Pointeur vers la grille précédente
};

// Alloue la mémoire d'un tableau de int de taille 9x9
int**	mallocTab()
{
	int	**t;
	
	t = (int**)malloc(9 * sizeof(int*));
	if (! t)
		exit(EXIT_FAILURE); // erreur allocation mémoire
	for (int i = 0; i < 9; i++)
	{
		t[i] = (int*)malloc(9 * sizeof(int));
		if (! t[i])
			exit(EXIT_FAILURE); // erreur allocation mémoire
	}
	return t;
}

SUDOKU	mallocSUDOKU()
{
	SUDOKU	S;
	
	S.val = mallocTab();
	S.travail = mallocTab();
	S.nom = NULL;
	S.save = 0;
	S.G = NULL;
	S.max = 0;
	return S;
}

void	push(SUDOKU *S)
{
	GRILLE	*G;
	
	G = (GRILLE*)malloc(sizeof(GRILLE));
	if (! G)
		exit(EXIT_FAILURE); // erreur allocation mémoire
	G->precedente = S->G;
	G->val = S->val;
	S->G = G;
	S->val = mallocTab();
	S->max++;
}

// Libère la mémoire d'un tableau de int de taille 9x9
void	freeTab(int **t)
{
	if (! t)
		return;
	for (int i = 0; i < 9; i++)
		free(t[i]);
	free(t);
}

// Si elle existe, libère la mémoire de la dernière grille de sudoku sauvegardée
void	pop(SUDOKU *S)
{
	if (! S || ! S->G)
		return;
	GRILLE	*G;
	
	G = S->G;
	S->G = S->G->precedente;
	freeTab(G->val);
	free(G);
	S->max--;
}

void	recover(SUDOKU *S)
{
	if (! S || ! S->G)
		return;
	if (S->val)
		freeTab(S->val);
	S->val = S->G->val;
	pop(S);
}

void	freeSUDOKU(SUDOKU *S)
{
	if (S->val)
		freeTab(S->val);
	if (S->travail)
		freeTab(S->travail);
	while (S->max)
		pop(S);
}