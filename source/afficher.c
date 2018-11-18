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

void	dessine_case(POINT P1, POINT P2, int i, int j, char val)
{
	POINT P3, P4;
	
	P3.x = P1.x + LARGEUR_TRAIT;
	P3.y = P2.y;
	draw_fill_rectangle(P1, P3, COUL_TRAIT);
	P3.y -= LARGEUR_TRAIT;
	P4.x = P2.x - LARGEUR_TRAIT;
	P4.y = P2.y;
	draw_fill_rectangle(P3, P4, COUL_TRAIT);
	P3.y = P1.y;
	P4.y = P1.y + LARGEUR_TRAIT;
	draw_fill_rectangle(P3, P4, COUL_TRAIT);
	P3.x = P2.x - LARGEUR_TRAIT;
	P3.y = P1.y;
	draw_fill_rectangle(P2, P3, COUL_TRAIT);
}

void	sudoku_afficher(SUDOKU S)
{
	POINT P1, P2, P3, P4;
	int i, j;
	
	fill_screen(COUL_FOND);
	P1.x = 0;
	P1.y = 0;
	P2.x = LARGEUR_TRAIT;
	P2.y = LARGEUR;
	P3.x = 0;
	P3.y = 0;
	P4.x = LARGEUR;
	P4.y = LARGEUR_TRAIT;
	for (i = 0; i < 5; i++)
	{
		draw_fill_rectangle(P1, P2, COUL_TRAIT);
		draw_fill_rectangle(P3, P4, COUL_TRAIT);
		P1.x += ((LARGEUR - LARGEUR_TRAIT) / 4);
		P2.x += ((LARGEUR - LARGEUR_TRAIT) / 4);
		P3.y += ((LARGEUR - LARGEUR_TRAIT) / 4);
		P4.y += ((LARGEUR - LARGEUR_TRAIT) / 4);
	}
}

void	old_sudoku_afficher(SUDOKU S)
{
	POINT P1, P2; int i, j;
	P1.x=0; P1.y=0; P2.x=0; P2.y=LARGEUR;
	
	fill_screen(burlywood);
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 9; j++)
		{
			draw_line(P1, P2, black);
			if (i==0) { P1.x=P1.x+67; P2.x=P1.x; }
			else { P1.y=P1.y+67; P2.y=P1.y; }
		}
		P1.x=0; P1.y=0; P2.x=LARGEUR; P2.y=0;
	}
	P1.x=0; P1.y=0; P2.x=4; P2.y=LARGEUR;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			draw_fill_rectangle(P1, P2, black);
			if (i==0)
			{
				P1.x=P1.x+200; P2.x=P1.x+4;
				if (j==2) { P1.x=P1.x-4; P2.x=P2.x-4; }
			}
			else
			{
				P1.y=P1.y+200; P2.y=P1.y+4;
				if (j==2) { P1.y=P1.y-4; P2.y=P2.y-4; }
			}
		}
		P1.x=0; P1.y=0; P2.x=LARGEUR; P2.y=4;
	}
}