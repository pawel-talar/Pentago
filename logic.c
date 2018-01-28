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


void downQuartersRotating(GtkWidget *widget, gpointer data)
{
    int * a = data;
    if(moveStep == 1)
        printf("Najpierw wybierz pole!\n");
}
void upQuartersRotating(GtkWidget *widget, gpointer data)
{
    int * a = data;
    if(moveStep == 1)
        printf("Najpierw wybierz pole!\n");
}