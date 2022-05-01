#include "headers.h"

Cola cargaCola() {
    FILE *datos = fopen("datos.txt", "r");
    Cola c = iniciaC();

    while (!feof(datos)) {
        int n;
        fscanf(datos, "%d", &n);
        poneC(&c, n);
    }

    return c;
}

void muestraCola(Cola *c) {
    if (!vaciaC(*c)) {
        int n = sacaC(c);
        printf("%d\n", n);
        muestraCola(c);
        poneC(c, n);
    }
}

int main()
{
    Cola cola = cargaCola();

    muestraCola(&cola);
    muestraCola(&cola);
    muestraCola(&cola);

    return 0;
}
