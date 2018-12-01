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
}

void	sudoku_afficher_grille(SUDOKU S)
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

void	sudoku_afficher_val(SUDOKU S)
{
	POINT	P;
	COULEUR	C;
	char	buf[2];
	
	P.y = TAILLE_CASE / 2;
	buf[1] = '\0';
	for (int i = 8; i >= 0; i--)
	{
		P.x = TAILLE_CASE / 2;
		for (int j = 0; j < 9; j++)
		{
			if (S.val[i][j]) // Si la valeur est différente de 0
			{
				C = (S.travail[i][j]) ? COUL_VAL_TRAVAIL : COUL_VAL_DEPART;
				buf[0] = S.val[i][j] + 48;
				aff_pol_centre(buf, TAILLE_POLICE, P, C);
			}
			P.x += TAILLE_CASE;
		}
		P.y += TAILLE_CASE;
	}
}

void	sudoku_afficher(SUDOKU S)
{
	POINT	P;
	
	P.x = TAILLE_CASE / 8;
	P.y = HAUTEUR - P.x;
	fill_screen(COUL_FOND);
	aff_pol(S.nom, TAILLE_POLICE, P, COUL_TITRE);
	sudoku_afficher_grille(S);
	sudoku_afficher_val(S);
}

void	sudoku_afficher_pb0(SUDOKU S, int i, int j)
{
	POINT	P1, P2;
	
	P1.x = j * TAILLE_CASE;
	P1.y = i * TAILLE_CASE;
	P2.x = P1.x + TAILLE_CASE;
	P2.y = P1.y + TAILLE_CASE;
	draw_fill_rectangle(P1, P2, COUL_FOND_PB);
}

void	sudoku_afficher_pb(SUDOKU S, int i, int j)
{
	POINT	P1, P2;
	
	P1.x = j * TAILLE_CASE;
	P1.y = i * TAILLE_CASE;
	P2.x = P1.x + TAILLE_CASE;
	P2.y = P1.y + TAILLE_CASE;
	if (! i)
		P1.y += LARGEUR_TRAIT + 1;
	else if (i == 8)
		P2.y -= LARGEUR_TRAIT + 1;
	else if (i == 2 || i == 5)
		P2.y -= LARGEUR_TRAIT2 + 1;
	else if (i == 3 || i == 6)
		P1.y += LARGEUR_TRAIT2 + 1;
	i %= 3;
	if (! i || i == 1)
		P2.y -= LARGEUR_TRAIT2 / 2 + 1;
	if (i == 1 || i == 2)
		P1.y += LARGEUR_TRAIT2 / 2 + 1;
	if (! j)
		P1.x += LARGEUR_TRAIT + 1;
	else if (j == 8)
		P2.x -= LARGEUR_TRAIT + 1;
	else if (j == 2 || j == 5)
		P2.x -= LARGEUR_TRAIT2 + 1;
	else if (j == 3 || j == 6)
		P1.x += LARGEUR_TRAIT2 + 1;
	j %= 3;
	if (! j || j == 1)
		P2.x -= LARGEUR_TRAIT2 / 2 + 1;
	if (j == 1 || j == 2)
		P1.x += LARGEUR_TRAIT2 / 2 + 1;
	draw_fill_rectangle(P1, P2, COUL_FOND_PB);
}