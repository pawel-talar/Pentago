#ifndef GTK_GAMECOMP_H
#define GTK_GAMECOMP_H

#include <gtk/gtk.h>

void createBoard(int n);
void updateBoard(int n);

GtkWidget *gameField;
int gameBoard[10][10];
GtkWidget *Board[10][10];
int Player;

#endif //GTK_GAMECOMP_H
