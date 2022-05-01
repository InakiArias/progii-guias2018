#include <stdio.h>
#include <stdlib.h>

#define LARGO_ARR(a) sizeof(a) / sizeof(a[0])

typedef int TElemLista;

typedef struct n {
    TElemLista dato;
    struct n *sig;
} nodo;

typedef nodo* Lista;

void muestraLista(Lista l) {
    Lista p = l;

    while (p != NULL) {
        printf("%d\n", p->dato);
        p = p->sig;
    }

    printf("\n\n");
}

Lista creaNodo(TElemLista dato) {
    Lista p = malloc(sizeof(nodo));
    p->dato = dato;
    p->sig = NULL;
    return p;
}

Lista a(int arr[], int n) {
    int i;
    Lista l = NULL, p;

    for (i = 0; i < n; i++) {
        p = l;
        l = creaNodo(arr[i]);
        l->sig = p;
    }

    return l;
}

Lista b(int arr[], int n) {
    int i;
    Lista l = NULL, p;

    for (i = n - 1; i >= 0; i--) {
        p = l;
        l = creaNodo(arr[i]);
        l->sig = p;
    }

    return l;
}

void insertaOrdenado2(Lista *l, int dato) {
    Lista *t = l;

    while (*t != NULL && dato > (*t)->dato)
        t = &(*t)->sig;

    Lista nuevo = creaNodo(dato);
    nuevo->sig = *t;
    *t = nuevo;
}

void insertaOrdenado(Lista *l, int dato) {
    Lista actual = *l, anterior = NULL;

    while (actual != NULL && dato > actual->dato) {
        anterior = actual;
        actual = actual->sig;
    }

    Lista nuevo = creaNodo(dato);
    nuevo->sig = actual;

    if (anterior == NULL) {
        *l = nuevo;
    }
    else {
        anterior->sig = nuevo;
    }
}

Lista c(int arr[], int n) {
    int i;
    Lista l = NULL;

    for (i = n - 1; i >= 0; i--) {
        insertaOrdenado(&l, arr[i]);
    }

    return l;
}

int main()
{
    int arr[] = {1,5,1,40,23,35};
    int n = LARGO_ARR(arr);

    Lista l1 = a(arr, n);
    muestraLista(l1);

    Lista l2 = b(arr, n);
    muestraLista(l2);

    Lista l3 = c(arr, n);
    muestraLista(l3);



    return 0;
}
