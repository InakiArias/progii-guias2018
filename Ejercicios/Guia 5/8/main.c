#include "headers.h"

typedef PilaD Pila;

Pila cargaPila(char num[]) {
    Pila p = iniciaPD();

    int i = 0;

    while (num[i]) {
        ponePD(&p, num[i]);
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

void suma(Pila *num1, Pila *num2, Pila *sum, int carry) {
    if (!vaciaPD(*num1) && !vaciaPD(*num2)) {
        int n1 = sacaPD(num1) - '0';
        int n2 = sacaPD(num2) - '0';
        int s = n1 + n2 + carry;

        char dig;

        dig = (s % 10) + '0';
        carry = s / 10;

        suma(num1, num2, sum, carry);

        ponePD(sum, dig);

        ponePD(num1, n1 + '0');
        ponePD(num2, n2 + '0');
    }
    else if (!vaciaPD(*num1)) {
        int n1 = sacaPD(num1) - '0';
        int s = n1 + carry;

        char dig;

        dig = (s % 10) + '0';
        carry = s / 10;

        suma(num1, num2, sum, carry);

        ponePD(sum, dig);

        ponePD(num1, n1 + '0');
    }
    else if (!vaciaPD(*num2)) {
        int n2 = sacaPD(num2) - '0';
        int s = n2 + carry;

        char dig;

        dig = (s % 10) + '0';
        carry = s / 10;

        suma(num1, num2, sum, carry);

        ponePD(sum, dig);

        ponePD(num2, n2 + '0');
    }
    else if (carry) {
        ponePD(sum, '1');
    }
}

int main()
{
    Pila num1 = cargaPila("9001");
    Pila num2 = cargaPila("999");
    Pila sum;

    int i;

    for (i = 0; i < 500000; i++) {
        sum = iniciaPD();
        suma(&num1, &num2, &sum, 0);
    }


    muestraPila(&num1); putchar('\n');
    muestraPila(&num2); putchar('\n');
    muestraPila(&sum); putchar('\n');
    muestraPila(&num1); putchar('\n');
    muestraPila(&num2); putchar('\n');

    return 0;
}
