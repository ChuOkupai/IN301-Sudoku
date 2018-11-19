#ifndef __SUDOKU_H
#define __SUDOKU_H

// Stockage du sudoku
typedef struct sudoku
{
	char	**val; // Stocke les valeurs
	char	*nom;  // Nom du fichier
	short	save;  // Numéro de sauvegarde du fichier actuel
}	SUDOKU;

// Alloue la mémoire à un sudoku
SUDOKU	mallocSUDOKU();

// Libère la mémoire allouée à un sudoku
void	freeSUDOKU(SUDOKU S);

// Retourne la valeur réelle stockée à l'index i, j
int	valGrille(SUDOKU S, int i, int j);
// Macro pour simplifier le code
#define VAL(I,J)	valGrille((SUDOKU)S, (int)I, (int)J)

// Système de pile avec ses fonctions de contrôle

// Element de la pile
typedef struct grille GRILLE;
struct grille
{
	char	**val;     // Stocke les valeurs
	GRILLE	*suivante; // Pointeur vers la grille suivante
};

typedef struct pile
{
	GRILLE	*premiere; // Pointeur vers la grille suivante
}	PILE;

// Alloue la mémoire à une pile
PILE*	mallocPILE();

// Ajoute une grille de sudoku à la pile si elle existe
void	push(PILE *P, SUDOKU S);

// Supprime la dernière grille de sudoku ajoutée si elle existe
void	pop(PILE *P);

// Renvoie la dernière grille de sudoku ajoutée si elle existe
char**	pick(PILE *P);

// Libère la mémoire allouée à la pile
void	freePILE(PILE *P);

#endif /* gestion_sudoku.h */