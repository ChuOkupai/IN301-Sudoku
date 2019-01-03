#ifndef __SUDOKU_H
#define __SUDOKU_H

// Pile des clics précédents
typedef struct pile PILE;
struct pile;

typedef struct sudoku
{
	/** Stockage du sudoku **/
	int  **val;  // Stocke les valeurs
	int  **etat; // La case vaut soit DEPART, soit TRAVAIL, soit SOLUTION
	int  numero; // Numéro de la sauvegarde actuelle
	char *nom;   // Nom du fichier sans extension
	
	/** Stockage des actions précédentes **/
	PILE *P; // Pile des anciennes actions
}	SUDOKU;

// Affiche une erreur sur la sortie standard
/** Si l'erreur est critique, termine le programme **/
void	erreur(int code);

// Alloue la mémoire à un sudoku
SUDOKU	sudoku_malloc();

// Vérifie si n est déjà présent autour de la case
/** Renvoie 1 si n valide, 0 sinon **/
int		sudoku_n_valide(SUDOKU S, int l, int c, int n);

// Modifie une case si possible
SUDOKU	sudoku_modifier_case(SUDOKU S, int i, int j);

// Annule la dernière action
SUDOKU	sudoku_annule(SUDOKU S);

// Trouve une solution au sudoku si possible;
SUDOKU	sudoku_trouve(SUDOKU S);

// Vérifie si le sudoku est terminé
/** Renvoie 1 si vrai, 0 sinon **/
int		sudoku_est_termine(SUDOKU S);

// Libére la mémoire et quitte le programme
void	sudoku_quitte(SUDOKU S);

#endif /* gestion_sudoku.h */