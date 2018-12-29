#ifndef __SUDOKU_H
#define __SUDOKU_H

// Stocke une action (clic sur une case ou appuie sur V)
typedef struct action ACTION;
struct action
{
	int    n;           // L'ancienne valeur
	int    l;           // Indice ligne où est stocké la valeur type dans le tableau
	int    c;           // Indice colonne où est stocké la valeur type dans le tableau
	ACTION *precedente; // Pointeur vers l'action précédente
};

typedef struct pile
{
	ACTION *derniere; // Pointeur vers la dernière action
	int    max;       // Nombre d'actions actuellement stockées
}	PILE;

typedef struct sudoku
{
	/** Stockage du sudoku **/
	int  **val;     // Stocke les valeurs
	int  **etat;    // La case vaut soit DEPART, soit TRAVAIL, soit SOLUTION
	int  numero;    // Numéro de la sauvegarde actuelle
	char *nom;      // Nom du fichier sans extension
	
	/** Stockage des actions précédentes **/
	PILE *P; // Pile des anciennes actions
}	SUDOKU;

// Affiche une erreur sur la sortie standard
/** Si critique != 0, termine le programme **/
void	erreur(int code, int critique);

// Alloue la mémoire à un sudoku
SUDOKU	sudoku_malloc();

// Vérifie si n est déjà présent autour de la case
int		sudoku_n_valide(int **val, int l, int c, int n);

// Modifie une case si possible
SUDOKU	sudoku_modifier_case(SUDOKU S, int i, int j);

// Annule la dernière action
SUDOKU	sudoku_annule(SUDOKU S);

// Trouve une solution au sudoku si possible;
SUDOKU	sudoku_trouve(SUDOKU S);

#endif /* gestion_sudoku.h */