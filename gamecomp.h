#ifndef GTK_GAMECOMP_H
#define GTK_GAMECOMP_H

#include <gtk/gtk.h>

void createBoard();
void updateBoard();
int choosenField(GtkWidget *widget, gpointer data);

typedef struct{
    int x;
    int y;
} coordinates;

GtkWidget *gameField;
int gameBoard[10][10];
GtkWidget *Board[10][10];
int Player;
int boardSize;

#endif //GTK_GAMECOMP_H
