#ifndef GTK_GAMECOMP_H
#define GTK_GAMECOMP_H

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void initRotationButtons();
void createBoard();
void updateBoard();
void choosenField(GtkWidget *widget, gpointer data);
void downQuartersRotating(GtkWidget *widget, gpointer data);
void upQuartersRotating(GtkWidget *widget, gpointer data);

typedef struct{
    int x;
    int y;
} coordinates;

char *player_id;
char *opp_id;

GtkWidget *window;
GtkWidget *gameField;
GtkWidget *upButtons;
GtkWidget *downButtons;
char gameBoard[10][10];
GtkWidget *Board[10][10];
GtkWidget *upRotation[5];
GtkWidget *downRotation[5];
bool isMy;
int boardSize;
int moveStep;

#endif //GTK_GAMECOMP_H
