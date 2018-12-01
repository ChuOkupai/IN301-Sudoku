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

#include <stdio.h>

int	sudoku_n_valide(int **t, int i, int j, int n)
{
	int k;
	
	for (k = i; k >= 0; k--)
		if (t[k][j] == n)
			return 0;
	for (k = i + 1; k < 9; k++)
		if (t[k][j] == n)
			return 0;
	for (k = j; k >= 0; k--)
		if (t[i][k] == n)
			return 0;
	for (k = j + 1; k < 9; k++)
		if (t[i][k] == n)
			return 0;
	for (k = i - i % 3; k < (i - i % 3 + 3); k++)
		for (int l = j - j % 3; l < (j - j % 3 + 3); l++)
			if (t[k][l] == n)
				return 0;
	return 1;
}

SUDOKU	sudoku_modifier_case(SUDOKU S, int i, int j)
{
	if (! S.travail[i][j])
		return S;
	for (int n = 1; n < 10; n++)
		if (sudoku_n_valide(S.val, i, j, n))
		printf("%d", n);
	putchar('\n');
	return S;
}