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


void upQuartersRotating(GtkWidget *widget, gpointer data)
{
    int * a = data;
    if(moveStep == 1)
        printf("Najpierw wybierz pole!\n");
    else
    {
        int tab[4][4];
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                tab[i][j] = 0;
        if(a == 0)
        {
            for(int i = 0; i < boardSize/2; i++)
            {
                for(int j = 0; j < boardSize/2; j++)
                {
                    tab[i][j] = gameBoard[j][i];
                }
            }
            for(int i = 0; i < boardSize/2; i++)
            {
                for(int j = 0; j < boardSize/2; j++)
                {
                    gameBoard[i][j] = tab[i][j];
                }
            }
        }
    }
    updateBoard();
}

void downQuartersRotating(GtkWidget *widget, gpointer data)
{
    int * a = data;
    if(moveStep == 1)
        printf("Najpierw wybierz pole!\n");
}
