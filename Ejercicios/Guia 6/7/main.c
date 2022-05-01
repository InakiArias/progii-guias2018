#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

typedef PilaD Pila;

#define LARGO_ARR(a) sizeof(a) / sizeof(a[0])

typedef Cola TElemLista;

typedef struct n {
    TElemLista dato;
    struct n *sig;
} nodo;

typedef nodo* Lista;

Lista creaNodo(TElemLista dato) {
    Lista p = malloc(sizeof(nodo));
    p->dato = dato;
    p->sig = NULL;
    return p;
}

Cola creaCola(int arr[], int n) {
    Cola c = iniciaC();
    int i;

    for (i = 0; i < n; i++)
        poneC(&c, arr[i]);

    return c;
}

void agregaCola(Lista *l, Cola c) {
    if (*l == NULL) {
        *l = creaNodo(c);
        return;
    }
    Lista ptr = *l;

    while (ptr->sig != NULL)
        ptr = ptr->sig;

    ptr->sig = creaNodo(c);
}

int maximo(Cola *c) {
    int max = sacaC(c);
    int n;

    while (!vaciaC(*c)) {
        n = sacaC(c);
        if (n > max)
            max = n;
    }

    return max;
}

Pila maximos(Lista l) {
    Pila p = iniciaPD();

    Lista ptr = l;

    while (ptr != NULL) {
        ponePD(&p, maximo(&ptr->dato));
        ptr = ptr->sig;
    }

    return p;
}


int main()
{
    int arr1[] = {1,3,4,50,7,16,23}, arr2[] = {233,1000,3,5,19,2400,35}, arr3[] = {100,7,45,23};
    int n1 = LARGO_ARR(arr1), n2 = LARGO_ARR(arr2), n3 = LARGO_ARR(arr3);

    Cola c1 = creaCola(arr1, n1), c2 = creaCola(arr2, n2), c3 = creaCola(arr3, n3);

    Lista l = NULL;

    agregaCola(&l, c1);
    agregaCola(&l, c2);
    agregaCola(&l, c3);

    Pila p = maximos(l);

    while (!VaciaPD(p))
        printf("%d\n", sacaPD(&p));

    return 0;
}
