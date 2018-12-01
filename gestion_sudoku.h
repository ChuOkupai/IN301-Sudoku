#ifndef __SUDOKU_H
#define __SUDOKU_H

typedef struct grille GRILLE;
struct grille;

typedef struct sudoku
{
	/** Stockage du sudoku **/
	int		**val;     // Stocke les valeurs
	int		**travail; // Si la case vaut 1, c'est une valeur de travail
	char	*nom;      // Nom du fichier
	int		save;      // Numéro de sauvegarde du fichier actuel
	
	/** Stockage des anciennes grilles **/
	GRILLE	*G;  // Pointeur vers la grille précédente
	int		max; // Nombre de grilles actuellement stockées
}	SUDOKU;

// Alloue la mémoire à un sudoku
SUDOKU	mallocSUDOKU();

// Si elle existe, ajoute une grille de sudoku à la liste
void	push(SUDOKU *S);

// Si elle existe, récupère la dernière grille de sudoku sauvegardée en mémoire
void	recover(SUDOKU *S);

// Libère la mémoire allouée à un sudoku
void	freeSUDOKU(SUDOKU *S);

#endif /* gestion_sudoku.h */