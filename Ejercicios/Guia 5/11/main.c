#include "headers.h"
#define ERROR -6666

typedef PilaD Pila;

void muestraPila(Pila *p) {
    if (!vaciaPD(*p)) {
        char c = sacaPD(p);
        muestraPila(p);
        putchar(c);
        ponePD(p, c);
    }
}

int esOperador(char c) {
    switch(c) {
        case '+':
        case '-':
        case '*':
        case '/': return 1;
        default: return 0;
    }
}

int cuenta(int n1, int n2, char operador) {
    switch(operador) {
        case '+': return n1 + n2;
        case '-': return n1 - n2;
        case '*': return n1 * n2;
        case '/': return n1 / n2;
    }
    return ERROR;
}

int postfija(char operacion[]) {
    Pila p = iniciaPD();
    int i = 0;

    while (operacion[i]) {
        char c = operacion[i];

        if (isdigit(c))
            ponePD(&p, c - '0');
        else if (esOperador(c)) {
            int n1, n2;

            if (vaciaPD(p))
                return ERROR;
            else
                n2 = sacaPD(&p);

            if (vaciaPD(p))
                return ERROR;
            else
                n1 = sacaPD(&p);

            ponePD(&p, cuenta(n1, n2, c));
        }
        else
            return ERROR;

        i++;
    }

    int resultado = sacaPD(&p);

    if (!vaciaPD(p))
        return ERROR;

    return resultado;

}


int main()
{
    printf("%d", postfija("512+4*+3-"));

    return 0;
}
