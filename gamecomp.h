#ifndef GTK_GAMECOMP_H
#define GTK_GAMECOMP_H

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

void initRotationButtons();
void createBoard();
void updateBoard();
void choosenField(GtkWidget *widget, gpointer data);

typedef struct{
    int x;
    int y;
} coordinates;

GtkWidget *gameField;
GtkWidget *upButtons;
GtkWidget *downButtons;
int gameBoard[10][10];
GtkWidget *Board[10][10];
GtkWidget *Rotation[10];
int Player;
int boardSize;
int moveStep;

/*Dodać rotation buttons
 * i odpowiadające im funkce
 * sensowne game marks
 * ogarnąć pliki kolejkowe
 * done :3
 */

#endif //GTK_GAMECOMP_H
