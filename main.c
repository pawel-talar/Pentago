#include <gtk/gtk.h>
#include "gamecomp.h"

GtkWidget *window;

static void endProgram(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    Player = 1;
    gchar header[30];
    sprintf(header, "Pentago!");
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), header);

    gameField = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), gameField);

    createBoard(6);

    g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(endProgram), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 100);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
