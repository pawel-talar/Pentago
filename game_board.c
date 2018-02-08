#include "gamecomp.h"

void initRotationButtons()
{
    for(int i = 0; i < 4; i++)
    {
        if(i % 2 == 0)
            upRotation[i] = gtk_button_new_with_label("<--");
        else
            upRotation[i] = gtk_button_new_with_label("-->");
        gtk_box_pack_start(GTK_BOX(upButtons), upRotation[i], TRUE, TRUE, 1);
        g_signal_connect(upRotation[i], "clicked", G_CALLBACK(upQuartersRotating), i);
    }
    for(int i = 0; i < 4; i++)
    {
        if(i % 2 == 0)
            downRotation[i] = gtk_button_new_with_label("<--");
        else
            downRotation[i] = gtk_button_new_with_label("-->");
        gtk_box_pack_start(GTK_BOX(downButtons), downRotation[i], TRUE, TRUE, 1);
        g_signal_connect(downRotation[i], "clicked", G_CALLBACK(downQuartersRotating), i);
    }
}

void createBoard()
{
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            gameBoard[i][j] = 'F';
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
            if (gameBoard[i][j] == 'A')
            {
                GtkWidget *image = gtk_image_new_from_file("../img/A.png");
                g_object_ref(image);
                gtk_button_set_image(GTK_BUTTON(Board[i][j]), image);
            }
            else if (gameBoard[i][j] == 'B')
            {
                GtkWidget *image = gtk_image_new_from_file("../img/B.png");
                g_object_ref(image);
                gtk_button_set_image(GTK_BUTTON(Board[i][j]), image);
            }
            else if (gameBoard[i][j] == 'F')
            {
                GtkWidget *image = gtk_image_new_from_file("../img/free.png");
                g_object_ref(image);
                gtk_button_set_image(GTK_BUTTON(Board[i][j]), image);
            }
            else if(gameBoard[i][j] == 'C')
            {
                GtkWidget *image = gtk_image_new_from_file("../img/Awin.png");
                g_object_ref(image);
                gtk_button_set_image(GTK_BUTTON(Board[i][j]), image);
            }
            else if(gameBoard[i][j] == 'D')
            {
                GtkWidget *image = gtk_image_new_from_file("../img/Bwin.png");
                g_object_ref(image);
                gtk_button_set_image(GTK_BUTTON(Board[i][j]), image);
            }
            gtk_button_set_always_show_image(GTK_BUTTON(Board[i][j]), TRUE);
        }
    }
}