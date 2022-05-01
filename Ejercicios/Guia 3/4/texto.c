#include "headers.h"

Texto crear(char *c) {
    Texto t;
    t.largo = 0;
    t.txt =c;

    while(*(c + t.largo)) {
        t.largo++;
    }

    return t;
}

void destruir(Texto t) {
    free(t.txt);
}
