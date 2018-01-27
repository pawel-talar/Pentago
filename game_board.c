#include "gamecomp.h"

void initRotationButtons()
{

    gtk_box_pack_end()
}

void createBoard()
{
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            gameBoard[i][j] = 0;
            Board[i][j] = gtk_button_new_with_label(" ");
            coordinates * current = malloc(sizeof(coordinates));
            current->x = i;
            current->y = j;
            g_signal_connect(G_OBJECT(Board[i][j]), "clicked", G_CALLBACK(choosenField), current);
            gtk_grid_attach(GTK_GRID(gameField), GTK_WIDGET(Board[i][j]), j+1, i+1, 1, 1);
        }
    }
}

void updateBoard()
{
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            if(gameBoard[i][j] == 1)
                gtk_button_set_label(GTK_BUTTON(Board[i][j]), "X");
            else if(gameBoard[i][j] == 2)
                gtk_button_set_label(GTK_BUTTON(Board[i][j]), "O");
        }
    }
}