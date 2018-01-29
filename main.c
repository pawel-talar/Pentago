#include "gamecomp.h"
#include "fifo.h"

GtkWidget *window;
GtkWidget *actionSurf;

void endProgram(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    Player = 1;
    boardSize = 6;
    moveStep = 1;

    gchar header[30];
    sprintf(header, "Pentago!");
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), header);

    gameField = gtk_grid_new();
    actionSurf = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    upButtons = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    downButtons = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    initRotationButtons();
    createBoard();
    gtk_box_pack_end(GTK_BOX(actionSurf), downButtons, TRUE, TRUE, 1);
    gtk_box_pack_end(GTK_BOX(actionSurf), gameField, TRUE, TRUE, 1);
    gtk_box_pack_end(GTK_BOX(actionSurf), upButtons, TRUE, TRUE, 1);

    gtk_container_add(GTK_CONTAINER(window), actionSurf);

    g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(endProgram), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 50);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
