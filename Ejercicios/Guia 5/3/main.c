#include "headers.h"

typedef PilaD Pila;

Pila cargaPila() {
    FILE *datos = fopen("datos.txt", "r");
    Pila p = iniciaPD();

    while (!feof(datos)) {
        int n;
        fscanf(datos, "%d", &n);
        ponePD(&p, n);
    }

    return p;
}

void muestraPila(Pila *p, int n) {
    if (!vaciaPD(*p) && n) {
        int num = sacaPD(p);
        muestraPila(p, n - 1);
        printf("%d\n", num);
        ponePD(p, num);
    }
}

int main()
{
    Pila pila = cargaPila();

    muestraPila(&pila, 10); putchar('\n');
    muestraPila(&pila, 4); putchar('\n');
    muestraPila(&pila, 1); putchar('\n');
    muestraPila(&pila, 2); putchar('\n');
    muestraPila(&pila, 2); putchar('\n');

    return 0;
}
