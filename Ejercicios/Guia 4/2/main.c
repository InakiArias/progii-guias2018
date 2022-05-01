#include <stdio.h>
#include <stdlib.h>

int prod(int a, int b) {
    return a ? b + prod(a - 1 , b) : 0 ;
}

void division(int a, int b, int *cociente, int *resto) {
    if (a < b) {
        *cociente = 0;
        *resto = a;
    }
    else {
        division(a - b, b, cociente, resto);

        (*cociente)++;
    }
}

int main()
{
    printf("%d\n", prod(3, 7));
    int cociente, resto;
    int a = 13, b = 6;

    division(a, b, &cociente, &resto);

    printf("%d / %d   c: %d, r: %d", a, b, cociente, resto);

    return 0;
}
