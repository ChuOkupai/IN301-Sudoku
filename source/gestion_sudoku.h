#ifndef __SUDOKU_H
#define __SUDOKU_H

// Stockage du sudoku
typedef struct sudoku SUDOKU;
struct sudoku
{
	char	**val; // Stocke les valeurs
	short	save;  // Numéro de sauvegarde du fichier actuel
};

// Retourne la valeur réelle stockée à l'index i, j
int	valGrille(SUDOKU S, int i, int j);
// Macro pour simplifier le code
#define VAL(I,J)	valGrille((SUDOKU)S, (int)I, (int)J)

// Système de pile avec ses fonctions de contrôle
typedef struct pile PILE;
typedef struct pile
{
	char	**val;     // Stocke les valeurs
	PILE	*suivante; // Pointeur vers la grille suivante
};

// Alloue la mémoire à une pile
PILE*	creerPILE();

// Ajoute une grille de sudoku à la pile si elle existe
void	push(PILE *P, char **val);

// Supprime la dernière grille de sudoku ajoutée si elle existe
void	pop(PILE *P);

// Renvoie la dernière grille de sudoku ajoutée si elle existe
char**	pick(PILE *P);

//	Supprime toute la pile
void	supprimerPile(PILE *P);

#endif /* gestion_sudoku.h */