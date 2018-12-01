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

// Libère la mémoire allouée à un sudoku
void	sudoku_free(SUDOKU S);

/*// Ajoute une action à la pile
void	push(SUDOKU *S);

// Récupère la dernière action sauvegardée en mémoire
void	recover(SUDOKU *S);*/

#endif /* gestion_sudoku.h */