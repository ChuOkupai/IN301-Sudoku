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

void	sudoku_afficher_pb(int i, int j)
{
	POINT	P1, P2;
	
	P1.x = i * TAILLE_CASE;
	P1.y = j * TAILLE_CASE;
	P2.x = P1.x + TAILLE_CASE;
	P2.y = P1.y + TAILLE_CASE;
	draw_fill_rectangle(P1, P2, COUL_FOND_PB);
}

void	sudoku_afficher_val(SUDOKU S)
{
	POINT	P;
	COULEUR	C;
	char	buf[2];
	
	P.y = TAILLE_CASE >> 1;
	buf[1] = '\0';
	for (int i = 8; i >= 0; i--)
	{
		P.x = TAILLE_CASE >> 1;
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
	POINT	P1, P2, P3, P4, P5, P6, P7, P8;
	int		i, j;
	
	fill_screen(COUL_FOND);
	P1.x = 0;
	P1.y = 0;
	P2.y = LARGEUR;
	P3.x = 0;
	P4.x = P2.y;
	P5.x = P1.x + TAILLE_CASE;
	P5.y = 0;
	P6.y = P2.y;
	P7.x = 0;
	P8.x = P4.x;
	for (i = 0; i < 5; i++)
	{
		P2.x = P1.x + LARGEUR_TRAIT;
		P3.y = P1.x;
		P4.y = P2.x;
		// Rendu des traits principaux
		draw_fill_rectangle(P1, P2, COUL_TRAIT); // Verticaux
		draw_fill_rectangle(P3, P4, COUL_TRAIT); // Horizontaux
		P1.x += (LARGEUR - LARGEUR_TRAIT) / 3;
		if (i > 2)
			continue;
		for (j = 0; j < 2; j++)
		{
			P6.x = P5.x + (LARGEUR_TRAIT >> 1);
			P7.y = P5.x;
			P8.y = P6.x;
			// Rendu des traits secondaires
			draw_fill_rectangle(P5, P6, COUL_TRAIT); // Verticaux
			draw_fill_rectangle(P7, P8, COUL_TRAIT); // Horizontaux
			P5.x += TAILLE_CASE;
		}
		P5.x = P1.x + TAILLE_CASE + (LARGEUR_TRAIT >> 1);
	}
	P1.x = TAILLE_CASE / 8;
	P1.y = HAUTEUR - P1.x;
	aff_pol(S.nom, TAILLE_POLICE, P1, COUL_TITRE);
	sudoku_afficher_val(S);
}