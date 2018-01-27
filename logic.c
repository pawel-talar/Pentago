#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "gamecomp.h"

int choosenField(GtkWidget *widget, gpointer data)
{
    coordinates * A = malloc(sizeof(coordinates));
    A = data;
    int i = A->x;
    int j = A->y;
    if(gameBoard[i][j] == 1 || gameBoard[i][j] == 2)
        printf("Pole zajete!\n");
    else
        gameBoard[i][j] = Player;
    updateBoard(boardSize);
    return 0;
}