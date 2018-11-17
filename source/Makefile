CFLAGS = -g -Wall -c
CFLAGSGR = $(CFLAGS) `sdl-config --cflags`
LFLAGS = -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf
NOM = SOURSOU_Adrien

# Nettoyage
clean:
	rm -f *.o sudoku

run: sudoku
	./sudoku exemple1.sudoku

# Edition de lien du programme principal
sudoku: sudoku.o afficher.o gestion_sudoku.o lire_ecrire.o
	gcc -o $@ $^ $(LFLAGS)

# Compilation du programme principal
sudoku.o: sudoku.c lire_ecrire.h gestion_sudoku.h constantes.h
	gcc $(CFLAGSGR) $*.c

# Compilation des fichiers objets
afficher.o: afficher.c afficher.h gestion_sudoku.h constantes.h
	gcc $(CFLAGSGR) $*.c

gestion_sudoku.o: gestion_sudoku.c gestion_sudoku.h
	gcc $(CFLAGS) $*.c

lire_ecrire.o: lire_ecrire.c lire_ecrire.h gestion_sudoku.h
	gcc $(CFLAGS) $*.c

# Création de l'archive (rendu)
zip:
	rm -rf $(NOM)
	rm -rf $(NOM).zip
	mkdir $(NOM)
	cp Makefile $(NOM)
	cp *.h *.c $(NOM)
	cp A_LIRE.txt $(NOM)
	zip -r $(NOM).zip $(NOM)
	rm -rf $(NOM)