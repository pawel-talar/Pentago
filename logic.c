#include "gamecomp.h"

void choosenField(GtkWidget *widget, gpointer data)
{
    coordinates * A = malloc(sizeof(coordinates));
    A = data;
    int i = A->x;
    int j = A->y;
    if(moveStep == 2)
        printf("Wybrałeś już pole, teraz odwróć jedną ze ćwiartek!\n");
    else if(gameBoard[i][j] == 1 || gameBoard[i][j] == 2)
        printf("Pole zajete!\n");
    else
    {
        gameBoard[i][j] = Player;
        moveStep = 2;
    }
    updateBoard();
}