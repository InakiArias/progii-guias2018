#include "headers.h"

typedef PilaD Pila;

Pila cargaPila() {
    FILE *datos = fopen("datos.txt", "r");
    Pila p = iniciaPD();

    char c[5];

    while (!feof(datos)) {
        fgets(c, 5, datos);
        ponePD(&p, c[0]);
    }

    return p;
}

void muestraPila(Pila *p) {
    if (!vaciaPD(*p)) {
        char c = sacaPD(p);
        putchar(c);
        muestraPila(p);
        ponePD(p, c);
    }
}

int main()
{
    Pila pila = cargaPila();

    muestraPila(&pila); putchar('\n');
    muestraPila(&pila); putchar('\n');
    muestraPila(&pila); putchar('\n');
    muestraPila(&pila); putchar('\n');

    return 0;
}
