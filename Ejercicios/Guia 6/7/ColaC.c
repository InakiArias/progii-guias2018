#include <stdio.h>
#include <stdlib.h>
#include "ColaC.h"

#define ERROR -6666

Cola iniciaC() {
    Cola c;
    c.pri = c.ult = -1;
    return c;
}

int vaciaC(Cola c) {
    return c.pri == -1;
}

void poneC(Cola *c, tElementoC x) {
    if (c->pri == -1) {
        c->pri = c->ult = 0;
        c->datos[0] = x;
        return;
    }

    int nuevoUlt = (c->ult + 1) % TAM_COLA;

    if (nuevoUlt != c->pri) {
        c->ult = nuevoUlt;
        c->datos[nuevoUlt] = x;
    }
}

tElementoC consultaC(Cola c) {
    if (c.pri != -1)
        return c.datos[c.pri];

    return ERROR;
}

tElementoC sacaC(Cola *c) {
    if (c->pri != -1) {
        int nuevoPri = (c->pri + 1) % TAM_COLA;
        int res = c->datos[c->pri];

        if (c->pri == c->ult) {
            c->pri = c->ult = -1;
        }
        else {
            c->pri = nuevoPri;
        }

        return res;
    }

    return ERROR;
}
