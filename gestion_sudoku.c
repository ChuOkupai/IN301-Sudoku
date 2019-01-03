#include "gestion_sudoku.h"
#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>

// Stocke une action (clic sur une case ou appuie sur V)
typedef struct action ACTION;
struct action
{
	int    n;           // L'ancienne valeur
	int    etat;        // L'ancien état de la case
	int    l;           // Indice ligne où est stocké la valeur type dans le tableau
	int    c;           // Indice colonne où est stocké la valeur type dans le tableau
	ACTION *precedente; // Pointeur vers l'action précédente
};

struct pile
{
	ACTION *derniere; // Pointeur vers la dernière action
	int    max;       // Nombre d'actions actuellement stockées
};

void	erreur(int code)
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
	if (code != ERR_SOLUTION)
		exit(EXIT_FAILURE);
}

// Alloue la mémoire d'un tableau de int de taille 9 x 9
int**	tab_malloc()
{
	int **t;
	
	t = (int**)malloc(9 * sizeof(int*));
	if (! t)
		erreur(ERR_MALLOC);
	for (int i = 0; i < 9; i++)
	{
		t[i] = (int*)malloc(9 * sizeof(int));
		if (! t[i])
			erreur(ERR_MALLOC);
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
		erreur(ERR_MALLOC);
	S.P->derniere = NULL;
	S.P->max = 0;
	return S;
}

SUDOKU	sudoku_ajoute_action(SUDOKU S, int n, int etat, int l, int c)
{
	ACTION *A;
	
	A = (ACTION*)malloc(sizeof(ACTION));
	if (! A)
		erreur(ERR_MALLOC);
	A->n = n;
	A->etat = etat;
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

int		sudoku_n_valide(SUDOKU S, int l, int c, int n)
{
	if (! n)
		return 1;
	int i;
	
	for (i = 0; i < 9; i++)
		if (S.val[l][i] == n || S.val[i][c] == n)
			return 0;
	for (i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (S.val[l - l % 3 + i][c - c % 3 + j] == n)
				return 0;
	return 1;
}

SUDOKU	sudoku_modifier_case(SUDOKU S, int i, int j)
{
	if (S.etat[i][j] == DEPART)
		return S;
	for (int n = S.val[i][j] + 1; n < 11; n++)
		if (n == 10)
		{
			if (! S.val[i][j])
				break;
			S = sudoku_ajoute_action(S, S.val[i][j], S.etat[i][j], i, j);
			S.val[i][j] = 0;
			S.etat[i][j] = TRAVAIL;
		}
		else if (sudoku_n_valide(S, i, j, n))
		{
			S = sudoku_ajoute_action(S, S.val[i][j], S.etat[i][j], i, j);
			S.val[i][j] = n;
			S.etat[i][j] = TRAVAIL;
			break;
		}
	return S;
}

SUDOKU	sudoku_annule(SUDOKU S)
{
	if (! S.P->max)
		return S;
	S.val[S.P->derniere->l][S.P->derniere->c] = S.P->derniere->n;
	S.etat[S.P->derniere->l][S.P->derniere->c] = S.P->derniere->etat;
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
		if (! sudoku_n_valide(S, i, j, k))
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
		erreur(ERR_SOLUTION);
	else if (! sudoku_est_termine(S))
		erreur(ERR_SOLUTION);
	return S;
}

int		sudoku_est_termine(SUDOKU S)
{
	int n;
	
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (! S.val[i][j])
				return 0;
			else
			{
				n = S.val[i][j];
				S.val[i][j] = 0;
				if (! sudoku_n_valide(S, i, j, n))
				{
					S.val[i][j] = n;
					return 0;
				}
				S.val[i][j] = n;
			}
	return 1;
}

/* Vide la pile d'actions */
SUDOKU	sudoku_vide_pile(SUDOKU S)
{
	while (S.P->max)
		S = sudoku_supprime_action(S);
	return S;
}

void	sudoku_quitte(SUDOKU S)
{
	for (int i = 0; i < 9; i++)
	{
		free(S.val[i]);
		free(S.etat[i]);
	}
	free(S.val);
	free(S.etat);
	free(S.nom);
	sudoku_vide_pile(S);
	free(S.P);
	exit(EXIT_SUCCESS);
}