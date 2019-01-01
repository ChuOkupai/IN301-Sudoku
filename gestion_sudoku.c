#include "gestion_sudoku.h"
#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>

void	erreur(int code, int critique)
{
	printf("erreur: ");
	switch (code)
	{
		case ERR_ARGC:
			puts("Aucun fichier à charger");
			break;
		case ERR_EXTENSION:
			puts("Le fichier ne se termine pas par .sudoku");
			break;
		case ERR_OUVERTURE:
			puts("Impossible d'ouvrir le fichier");
			break;
		case ERR_FORMAT:
			puts("Format non reconnu");
			break;
		case ERR_MALLOC:
			puts("Impossible d'allouer la mémoire");
			break;
		case ERR_SOLUTION:
			puts("Solution impossible");
			break;
	}
	if (critique)
		exit(EXIT_FAILURE);
}

// Alloue la mémoire d'un tableau de int de taille 9 x 9
int**	tab_malloc()
{
	int **t;
	
	t = (int**)malloc(9 * sizeof(int*));
	if (! t)
		erreur(ERR_MALLOC, 1);
	for (int i = 0; i < 9; i++)
	{
		t[i] = (int*)malloc(9 * sizeof(int));
		if (! t[i])
			erreur(ERR_MALLOC, 1);
	}
	return t;
}

SUDOKU	sudoku_malloc()
{
	SUDOKU S;
	
	S.val = tab_malloc();
	S.etat = tab_malloc();
	S.nom = NULL;
	S.P = (PILE*)malloc(sizeof(PILE));
	if (! S.P)
		erreur(ERR_MALLOC, 1);
	S.P->derniere = NULL;
	S.P->max = 0;
	return S;
}

SUDOKU	sudoku_ajoute_action(SUDOKU S, int n, int l, int c)
{
	ACTION *A;
	
	A = (ACTION*)malloc(sizeof(ACTION));
	if (! A)
		erreur(ERR_MALLOC, 1);
	A->n = n;
	A->l = l;
	A->c = c;
	A->precedente = S.P->derniere;
	if (S.P->max == PILE_MAX) // Pile pleine (pire des cas)
	{
		ACTION *B, *C;
		
		B = S.P->derniere;
		for (int i = 1; i < PILE_MAX - 1; i++)
			B = B->precedente;
		C = B->precedente;
		B->precedente = NULL;
		free(C);
		S.P->max--;
	}
	S.P->derniere = A;
	S.P->max++;
	return S;
}

SUDOKU	sudoku_supprime_action(SUDOKU S)
{
	if (S.P->max == 1)
	{
		free(S.P->derniere);
		S.P->derniere = NULL;
	}
	else
	{
		ACTION *A;
		
		A = S.P->derniere->precedente;
		free(S.P->derniere);
		S.P->derniere = A;
	}
	S.P->max--;
	return S;
}

int		sudoku_n_valide(int **val, int l, int c, int n)
{
	if (! n)
		return 1;
	int i;
	
	for (i = 0; i < 9; i++)
		if (val[i][c] == n || val[l][i] == n)
			return 0;
	for (i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (val[l - l % 3 + i][c - c % 3 + j] == n)
				return 0;
	return 1;
}

SUDOKU	sudoku_modifier_case(SUDOKU S, int i, int j)
{
	if (S.etat[i][j] == DEPART)
		return S;
	if (S.val[i][j] == 9)
		S.val[i][j] = 0;
	else
		for (int n = S.val[i][j] + 1; n < 10; n++)
		{
			if (sudoku_n_valide(S.val, i, j, n))
			{
				S = sudoku_ajoute_action(S, S.val[i][j], i, j);
				S.val[i][j] = n;
				S.etat[i][j] = TRAVAIL;
				break;
			}
			else if (n == 9)
			{
				S = sudoku_ajoute_action(S, S.val[i][j], i, j);
				S.val[i][j] = 0;
				S.etat[i][j] = TRAVAIL;
}
		}
	return S;
}

SUDOKU	sudoku_annule(SUDOKU S)
{
	if (! S.P->max)
		return S;
	S.val[S.P->derniere->l][S.P->derniere->c] = S.P->derniere->n;
	return sudoku_supprime_action(S);
}

// Résolution du sudoku
/** Renvoie 1 si impossible **/
int		sudoku_resolution(SUDOKU S, int n)
{
	if (n > 80)
		return 1;
	int i, j;

	i = n / 9;
	j = n % 9;
	if (S.val[i][j])
		return sudoku_resolution(S, n + 1);
	for (int k = 1; k < 10; k++)
	{
		if (! sudoku_n_valide(S.val, i, j, k))
			continue;
		S.val[i][j] = k;
		S.etat[i][j] = SOLUTION;
		if (sudoku_resolution(S, n + 1))
			return 1;
		else
			S.val[i][j] = 0;
	}
	return 0;
}

SUDOKU	sudoku_trouve(SUDOKU S)
{
	if (! sudoku_resolution(S, 0))
		erreur(ERR_SOLUTION, 0);
	return S;
}

int		sudoku_est_termine(SUDOKU S)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (! S.val[i][j])
				return 0;
	return 1;
}

void	sudoku_free(SUDOKU S)
{
	for (int i = 0; i < 9; i++)
	{
		free(S.val[i]);
		free(S.etat[i]);
	}
	free(S.val);
	free(S.etat);
	free(S.nom);
	while (S.P->max)
		S = sudoku_supprime_action(S);
	free(S.P);
}