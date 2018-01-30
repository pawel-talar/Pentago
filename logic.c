#include "gamecomp.h"
#include "fifo.h"

static void sendMove()
{
    gchar wejscie[boardSize*boardSize+2];
    wejscie[0] = playerTurn;
    int k = 1;
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            wejscie[k] = gameBoard[i][j];
            k++;
        }
    }
    sendStringToPipe(potoki, wejscie);
}

static void changePlayer()
{
    moveStep = 1;
    if(Player == 2)
        Player = 1;
    else
        Player = 2;
    sendMove();
    if(playerTurn == '1')
        playerTurn = '0';
    else
        playerTurn = '1';
}

static void rotateLeft(int quarter)
{
    char tab[boardSize/2+1][boardSize/2+1];
    char pom[boardSize/2+1][boardSize/2+1];
    for(int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            tab[i][j] = 'F';
            pom[i][j] = 'F';
        }
    }
    int i = 0;
    int j = 0;
    int n = 0;
    int m = 0;
    if(quarter == 1){
        i = 0;
        j = 0;
        n = boardSize/2;
        m = boardSize/2;
    }
    else if(quarter == 2)
    {
        i = 0;
        j = boardSize/2;
        n = boardSize/2;
        m = boardSize;
    }
    else if(quarter == 3)
    {
        i = boardSize/2;
        j = 0;
        n = boardSize;
        m = boardSize/2;
    }
    else if(quarter == 4)
    {
        i = boardSize/2;
        j = boardSize/2;
        n = boardSize;
        m = boardSize;
    }
    int k = i;
    int l = j;
    for(; i < n; i++)
    {
        for(; j < m; j++)
        {
            tab[i-k][j-l] = gameBoard[i][j];
        }
        j = l;
    }
    for(int x = 0; x < boardSize/2; x++)
        for(int y = 0; y < boardSize/2; y++)
            pom[boardSize/2-y-1][x] = tab[x][y];

    i = k;
    j = l;
    for(; i < n; i++)
    {
        for(; j < m; j++)
        {
            gameBoard[i][j] = pom[i-k][j-l];
        }
        j = l;
    }
    updateBoard();
    changePlayer();
}

static void rotateRight(int quarter)
{
    char tab[boardSize/2+1][boardSize/2+1];
    char pom[boardSize/2+1][boardSize/2+1];
    for(int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            tab[i][j] = 'F';
            pom[i][j] = 'F';
        }
    }
    int i = 0;
    int j = 0;
    int n = 0;
    int m = 0;
    if(quarter == 1){
        i = 0;
        j = 0;
        n = boardSize/2;
        m = boardSize/2;
    }
    else if(quarter == 2)
    {
        i = 0;
        j = boardSize/2;
        n = boardSize/2;
        m = boardSize;
    }
    else if(quarter == 3)
    {
        i = boardSize/2;
        j = 0;
        n = boardSize;
        m = boardSize/2;
    }
    else if(quarter == 4)
    {
        i = boardSize/2;
        j = boardSize/2;
        n = boardSize;
        m = boardSize;
    }
    int k = i;
    int l = j;
    for(; i < n; i++)
    {
        for(; j < m; j++)
        {
            tab[i-k][j-l] = gameBoard[i][j];
        }
        j = l;
    }
    for(int x = 0; x < boardSize/2; x++)
        for(int y = 0; y < boardSize/2; y++)
            pom[y][boardSize/2-x-1] = tab[x][y];

    i = k;
    j = l;
    for(; i < n; i++)
    {
        for(; j < m; j++)
        {
            gameBoard[i][j] = pom[i-k][j-l];
        }
        j = l;
    }

}


void upQuartersRotating(GtkWidget *widget, gpointer data)
{
    int * a = data;

    if((Player == 1 && player_id[0] == 'B') || (Player == 2 && player_id[0] == 'A'))
        printf("Teraz kolej przeciwnika!\n");
    else if(moveStep == 1)
        printf("Najpierw wybierz pole!\n");
    else
    {
        if(a == 0)
            rotateLeft(1);
        else if(a == (int *) 1)
            rotateRight(1);
        else if(a == (int *) 2)
            rotateLeft(2);
        else if(a == (int *) 3)
            rotateRight(2);
        updateBoard();
        changePlayer();
    }
}

void downQuartersRotating(GtkWidget *widget, gpointer data)
{
    int * a = data;
    if((Player == 1 && player_id[0] == 'B') || (Player == 2 && player_id[0] == 'A'))
        printf("Teraz kolej przeciwnika!\n");
    else if(moveStep == 1)
        printf("Najpierw wybierz pole!\n");
    else
    {
        if(a == (int *)1)
            rotateLeft(3);
        else if(a == (int *) 0)
            rotateRight(3);
        else if(a == (int *) 3)
            rotateLeft(4);
        else if(a == (int *) 2)
            rotateRight(4);
        updateBoard();
        changePlayer();
    }
}

void choosenField(GtkWidget *widget, gpointer data)
{
    coordinates * A = malloc(sizeof(coordinates));
    A = data;
    int i = A->x;
    int j = A->y;
    if((Player == 1 && player_id[0] == 'B') || (Player == 2 && player_id[0] == 'A'))
        printf("Teraz kolej przeciwnika!\n");
    else if(moveStep == 2)
        printf("Wybrałeś już pole, teraz odwróć jedną ze ćwiartek!\n");
    else if(gameBoard[i][j] == 'A' || gameBoard[i][j] == 'B')
        printf("Pole zajete!\n");
    else
    {
        gameBoard[i][j] = player_id[0];
        moveStep = 2;
    }
    updateBoard();
}