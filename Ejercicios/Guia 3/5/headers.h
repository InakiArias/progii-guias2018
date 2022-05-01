#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int largo;
    char *txt;
} Texto;

Texto crear(char *c);
void destruir(Texto t);

