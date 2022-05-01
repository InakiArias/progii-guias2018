#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"

Cola iniciaC() {
    Cola c;
    c.pri = NULL;
    c.ult = NULL;
    return c;
}

int vaciaC(Cola c) {
    return c.pri == NULL;
}

void poneC(Cola *c, tElementoC x) {
    nodo *n = malloc(sizeof(nodo));

    n->dato = x;
    n->sig = NULL;

    if ((*c).pri) {
        (*c).ult->sig = n;
    }
    else {
        (*c).pri = n;
    }

    (*c).ult = n;
}

tElementoC consultaC(Cola c) {
    if (c.pri) {
        return c.pri->dato;
    }

    return -6666;
}

tElementoC sacaC(Cola *c) {
    if ((*c).pri) {
        tElementoC dato = (*c).pri->dato;
        nodo *n = (*c).pri;

        (*c).pri = (*c).pri->sig;

        if (!(*c).pri)
            (*c).ult = NULL;

        free(n);

        return dato;
    }

    return -6666;
}
