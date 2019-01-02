#include <uvsqgraphics.h>
#include "constantes.h"
#include "gestion_sudoku.h"

void	initialiser_fenetre_graphique()
{
	init_graphics(LARGEUR, HAUTEUR);
	affiche_auto_off();
}

void	terminer_fenetre_graphique()
{
	wait_escape();
	exit(EXIT_SUCCESS);
}

void	sudoku_afficher_grille()
{
	POINT	PX1, PX2, PY1, PY2;
	int		distance;
	
	distance = 0;
	PX1.x = 0;
	PX1.y = 0;
	PX2.x = LARGEUR_TRAIT;
	PX2.y = LARGEUR;
	PY1 = PX1;
	PY2.x = LARGEUR;
	PY2.y = LARGEUR_TRAIT;
	for (int i = 0; i < 4; i++)
	{
		// Rendu des traits principaux
		draw_fill_rectangle(PX1, PX2, COUL_TRAIT); // Verticaux
		draw_fill_rectangle(PY1, PY2, COUL_TRAIT); // Horizontaux
		if (i == 3)
			break;
		for (int j = 0; j < 2; j++)
		{
			distance += TAILLE_CASE;
			PX1.x = distance - LARGEUR_TRAIT2 / 2;
			PX2.x = PX1.x + LARGEUR_TRAIT2;
			PY1.y = PX1.x;
			PY2.y = PX2.x;
			// Rendu des traits secondaires
			draw_fill_rectangle(PX1, PX2, COUL_TRAIT); // Verticaux
			draw_fill_rectangle(PY1, PY2, COUL_TRAIT); // Horizontaux
		}
		distance += TAILLE_CASE;
		// Cas particulier si dernier trait
		PX1.x = distance - ((i == 2) ? LARGEUR_TRAIT : LARGEUR_TRAIT2);
		PX2.x = PX1.x + LARGEUR_TRAIT;
		PY1.y = PX1.x;
		PY2.y = PX2.x;
	}
}

// Fonction qui affiche une case en rouge
void	sudoku_afficher_pb(int i, int j)
{
	POINT P1, P2;
	
	P1.x = j * TAILLE_CASE;
	P1.y = (8 - i) * TAILLE_CASE;
	P2.x = P1.x + TAILLE_CASE;
	P2.y = P1.y + TAILLE_CASE;
	draw_fill_rectangle(P1, P2, COUL_FOND_PB);
}

void	sudoku_afficher(SUDOKU S)
{
	POINT	P;
	COULEUR	C;
	char	buf[2]; // Pour stocker le chiffre à afficher
	int		v;
	
	fill_screen(COUL_FOND);
	P.x = TAILLE_CASE / 8;
	P.y = HAUTEUR - P.x;
	aff_pol(S.nom, TAILLE_POLICE, P, COUL_TITRE);
	buf[1] = '\0';
	P.y = TAILLE_CASE / 2;
	for (int i = 8; i >= 0; i--)
	{
		P.x = TAILLE_CASE / 2;
		for (int j = 0; j < 9; j++)
		{
			if (! S.val[i][j])
			{
				v = 0;
				for (int n = 1; n < 10; n++)
					v += sudoku_n_valide(S, i, j, n);
				if (! v)
					sudoku_afficher_pb(i, j);
			}
			else // Si la valeur existe
			{
				if (S.etat[i][j] == DEPART)
					C = COUL_DEPART;
				else if (S.etat[i][j] == TRAVAIL)
					C = COUL_TRAVAIL;
				else
					C = COUL_SOLUTION;
				buf[0] = S.val[i][j] ^ 48;
				aff_pol_centre(buf, TAILLE_POLICE, P, C);
			}
			P.x += TAILLE_CASE;
		}
		P.y += TAILLE_CASE;
	}
	sudoku_afficher_grille();
}

void	sudoku_affiche_gagne()
{
	POINT	P;
	char	*buf = "GAGN" Eacute;
	
	P.x = 6.5 * TAILLE_CASE;
	P.y = HAUTEUR - TAILLE_CASE / 8;
	aff_pol(buf, TAILLE_POLICE, P, COUL_GAGNE);
}