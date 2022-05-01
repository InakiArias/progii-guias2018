#include "headers.h"

typedef PilaD Pila;

Pila cargaPila(char op[]) {
    Pila p = iniciaPD();

    int i = 0;

    while (op[i]) {
        switch (op[i]) {
            case '(':
            case ')':
            case '{':
            case '}':
            case '[':
            case ']': ponePD(&p, op[i]);
        }

        i++;
    }

    return p;
}

void muestraPila(Pila *p) {
    if (!vaciaPD(*p)) {
        char c = sacaPD(p);
        muestraPila(p);
        putchar(c);
        ponePD(p, c);
    }
}

int opValida(char op[]) {
    Pila p = iniciaPD();
    int i = 0;

    while (op[i]) {
        switch (op[i]) {
            case '(':
            case '[':
            case '{': ponePD(&p, op[i]); break;

            case ')':
                if (consultaPD(p) != '(') return 0;
                else {sacaPD(&p); break;}
            case ']':
                if (consultaPD(p) != '[') return 0;
                else {sacaPD(&p); break;}
            case '}':
                if (consultaPD(p) != '{') return 0;
                else {sacaPD(&p); break;}
        }

        i++;
    }

    return vaciaPD(p);

}


int main()
{
    printf("%d", opValida("][(])"));

    return 0;
}
