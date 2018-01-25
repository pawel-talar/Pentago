#include <gtk/gtk.h>

GtkWidget *window;

static void endProgram(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    gchar header[30];
    sprintf(header, "Pentago!");
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), header);
    g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(endProgram), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
