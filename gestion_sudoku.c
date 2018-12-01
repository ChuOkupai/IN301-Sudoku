#include "gestion_sudoku.h"
#include <stdlib.h>

// Alloue la mémoire d'un tableau de int de taille 9x9
int**	tab_malloc()
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

// Libère la mémoire d'un tableau de int de taille 9x9
void	tab_free(int **t)
{
	if (! t)
		return;
	for (int i = 0; i < 9; i++)
		free(t[i]);
	free(t);
}

SUDOKU	sudoku_malloc()
{
	SUDOKU S;
	
	S.val = tab_malloc();
	S.travail = tab_malloc();
	S.nom = NULL;
	S.A = NULL;
	S.max = 0;
	return S;
}

void	sudoku_free(SUDOKU S)
{
	if (S.val)
		tab_free(S.val);
	if (S.travail)
		tab_free(S.travail);
	//while (S->max)
		//pop(S);
}

/*void	push(SUDOKU *S)
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

// Si elle existe, libère la mémoire de la dernière action sauvegardée
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
}*/