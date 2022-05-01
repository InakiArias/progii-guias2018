#include <stdio.h>
#include <stdlib.h>
#include "PilaE.h"

PilaE iniciaPE() {
    PilaE p;
    p.tope = -1;
    return p;
}

int vaciaPE(PilaE p) {
    return p.tope == -1;
}

void ponePE(PilaE *p, tElementoPE x) {
    if (p->tope < MAX_PE - 1) {
        p->tope++;
        p->pila[p->tope] = x;
    }
}

tElementoPE consultaPE(PilaE p) {
    if (p.tope != -1) {
        return p.pila[p.tope];
    }
    return -6666;
}

tElementoPE sacaPE(PilaE *p) {
    if (p->tope != -1) {
        return p->pila[p->tope--];
    }
    return -6666;
}
