#include <stdio.h>
#include <stdlib.h>

int suma(int *v, int n) {
    return n ? v[n] + suma(v, n - 1) : v[n];
}

void muestra(int v[], int n) {
    if (n > -1) {
        muestra(v, n - 1);
        printf("%d ", v[n]);
    }
}

void muestrareves(int v[], int n) {
    if (n > -1) {
        printf("%d ", v[n]);
        muestrareves(v, n - 1);
    }
}

int binaria(int v[], int valor, int izq, int der) {
    int medio = (izq + der) / 2;

    if (v[medio] == valor)
        return medio;
    if (izq >= der)
        return -1;
    if (v[medio] > valor)
        return binaria(v, valor, izq, medio - 1);

    return binaria(v, valor, medio + 1, der);
}

void mostrar(int matriz[3][3], int m, int n) {
    int i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", matriz[i][j]);

        printf("\n");
    }
}

int minimo(int matriz[3][3], int i, int j, int n) {
    if (i == 0 && j == 0)
        return matriz[0][0];

    int min;

    if (j > -1) {
        min = minimo(matriz, i, j - 1, n);
        return matriz[i][j] < min ? matriz[i][j] : min;
    }
    else {
        min = minimo(matriz, i - 1, n - 1, n);
        return matriz[i][j] < min ? matriz[i][j] : min;
    }

}

int main()
{
    int v[10] = {1,4,7,19,23,45,67,78,89,100};
    int n = 10;

    printf("%d\n", suma(v, n - 1));
    muestra(v, n - 1); printf("\n");
    muestrareves(v, n - 1); printf("\n");

    int val;

    for (val = 0; val <= 100; val++)
        //printf("Pos de %d: %d\n", val, binaria(v, val, 0, n - 1));

    n = 3;
    int m = 3;

    int matriz[3][3] = {{10,20,30},{40,50,60},{70,80,90}};


    mostrar(matriz, m, n);

    printf("Min: %d", minimo(matriz, m - 1, n - 1, n));


    return 0;
}
