#ifndef __LIRE_ECRIRE_H
#define __LIRE_ECRIRE_H

// Lecture d'un fichier .sudoku et stockage dans une variable de type SUDOKU qui est renvoyée
SUDOKU	lire_fichier(char *nom);

// Ecriture d'un sudoku dans un fichier
SUDOKU	ecrire_fichier(SUDOKU S);

#endif /* lire_ecrire.h */