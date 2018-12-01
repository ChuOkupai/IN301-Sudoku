#ifndef __SUDOKU_H
#define __SUDOKU_H

// Stocke une action (clic sur une case)
typedef struct action ACTION;
struct action
{
	int		i;         // Emplacement y de la valeur
	int		j;         // Emplacement x de la valeur
	int		val;       // Ancienne valeur
	ACTION	*precedente; // Pointeur vers l'action précédente
};

typedef struct sudoku
{
	/** Stockage du sudoku **/
	int		**val;     // Stocke les valeurs
	int		**travail; // Si la case vaut 1, c'est une valeur de travail
	char	*nom;      // Nom du fichier
	
	/** Stockage des actions précédentes (clic sur une case) **/
	ACTION	*A;  // Pointeur vers la dernière action
	int		max; // Nombre d'actions actuellement stockées
}	SUDOKU;

// Alloue la mémoire à un sudoku
SUDOKU	sudoku_malloc();

int	sudoku_n_valide(int **t, int i, int j, int n);

SUDOKU	sudoku_modifier_case(SUDOKU S, int i, int j);

#endif /* gestion_sudoku.h */