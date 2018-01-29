//
// Created by pawel on 29.01.18.
//

#ifndef GTK_FIFO_H
#define GTK_FIFO_H

#include <stdbool.h>

struct pipes {
    FILE *fifo_in, *fifo_out;
    int isA;
} ;

typedef struct pipes *PipesPtr;

PipesPtr initPipes(int argc, char *argv[]);
void     sendStringToPipe(PipesPtr channel, const char *data);
bool     getStringFromPipe(PipesPtr channel, char *buffer, size_t size);
void     closePipes(PipesPtr channel);


#endif //GTK_FIFO_H
