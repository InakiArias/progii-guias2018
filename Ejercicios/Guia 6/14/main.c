#include <stdio.h>
#include <stdlib.h>

#define LARGO_ARR(a) sizeof(a) / sizeof(a[0])

typedef struct n {
    int dato;
    struct n *sig;
} nodo;

typedef nodo* Lista;

typedef struct nd {
    int dato;
    struct nd *sig, *ant;
} nodoD;

typedef nodoD* PNodo;

typedef struct {
    PNodo pri, ult;
} ListaD;

Lista creaNodo(int dato) {
    Lista p = malloc(sizeof(nodo));

    p->dato = dato;
    p->sig = NULL;

    return p;
}

PNodo creaNodoDoble(int dato) {
    PNodo p = malloc(sizeof(nodoD));

    p->dato = dato;
    p->sig = NULL;
    p->ant = NULL;

    return p;
}

Lista a(int arr[], int n) {
    int i;
    Lista l, *p = &l;

    for (i = 0; i < n; i++) {
        *p = creaNodo(arr[i]);
        p = &(*p)->sig;
    }

    return l;
}

void muestraLista(Lista l) {
    Lista p = l;

    while (p != NULL) {
        printf("%d\n", p->dato);
        p = p->sig;
    }

    printf("\n\n");
}

Lista listaC(int arr[], int n) {
    Lista lc = creaNodo(arr[0]);
    lc->sig = lc;
    int i;

    for (i = 1; i < n; i++) {
        Lista nuevoDato = creaNodo(arr[i]);
        nuevoDato->sig = lc->sig;
        lc->sig = nuevoDato;
        lc = nuevoDato;
    }

    return lc;

}

void creaListaD(int arr[], int n, ListaD *listaDoble) {
    PNodo *actual = &listaDoble->pri;
    PNodo anterior = NULL;
    int i;

    for (i = 0; i < n; i++) {
        *actual = creaNodoDoble(arr[i]);
        (*actual)->ant = anterior;
        anterior = *actual;
        actual = &(*actual)->sig;
    }

    listaDoble->ult = anterior;
}

void muestraListac(Lista l) {
    Lista p = l->sig;

    do {
        printf("%d\n", p->dato);
        p = p->sig;
    } while (p != l->sig);

    printf("\n\n");
}

void muestraListaD(ListaD listaDoble) {
    PNodo ptr = listaDoble.pri;

    while (ptr != NULL) {
        printf("%d\n", ptr->dato);
        ptr = ptr->sig;
    }

    printf("\n\n");
}

void muestraListaDReves(ListaD listaDoble) {
    PNodo ptr = listaDoble.ult;

    while (ptr != NULL) {
        printf("%d\n", ptr->dato);
        ptr = ptr->ant;
    }

    printf("\n\n");
}

int main()
{
    int arr[] = {1,5,1,40,23,35};
    int n = LARGO_ARR(arr);

    Lista l = a(arr, n);
    muestraLista(l);

    Lista lc = listaC(arr, n);
    muestraListac(lc);

    ListaD ld; creaListaD(arr, n, &ld);
    muestraListaD(ld);
    muestraListaDReves(ld);



    return 0;
}
