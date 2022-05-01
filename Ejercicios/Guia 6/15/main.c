#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
    int dato;
    struct nd *sig, *ant;
} nodoD;

typedef nodoD* PNodo;

typedef struct {
    PNodo pri, ult;
} ListaD;

PNodo creaNodo(int dato) {
    PNodo p = malloc(sizeof(nodoD));

    p->dato = dato;
    p->sig = NULL;
    p->ant = NULL;

    return p;
}

int largoLista (ListaD listaDoble) {
    PNodo ptr = listaDoble.pri;
    int i = 0;

    while (ptr != NULL) {
        ptr = ptr->sig;
        i++;
    }

    return i;
}

PNodo buscaPos(int n, PNodo pri) {
    int i = 0;
    PNodo ptr = pri;

    while (ptr != NULL && i < n) {
        ptr = ptr->sig;
        i++;
    }

    return ptr;
}

void agregaAlMedio(ListaD *listaDoble, int dato) {
    if (listaDoble->pri == NULL) {
        listaDoble->pri = listaDoble->ult = creaNodo(dato);
        return;
    }

    int largo = largoLista(*listaDoble);
    int medio = (largo - 1) / 2;

    PNodo ptrAnterior = buscaPos(medio, listaDoble->pri);

    PNodo nuevoNodo = creaNodo(dato);
    nuevoNodo->ant = ptrAnterior;
    nuevoNodo->sig = ptrAnterior->sig;

    if (ptrAnterior->sig == NULL)
        listaDoble->ult = nuevoNodo;
    else
        ptrAnterior->sig->ant = nuevoNodo;

    ptrAnterior->sig = nuevoNodo;
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

void elimina(ListaD *listaDoble, int pos) {
    PNodo eliminado = buscaPos(pos, listaDoble->pri);

    if (eliminado == NULL)
        return;

    if (eliminado->ant != NULL)
        eliminado->ant->sig = eliminado->sig;
    else
        listaDoble->pri = eliminado->sig;

    if (eliminado->sig != NULL)
        eliminado->sig->ant = eliminado->ant;
    else
        listaDoble->ult = eliminado->ant;
}

int main()
{
    ListaD listaDoble; listaDoble.pri = NULL; listaDoble.ult = NULL;

    agregaAlMedio(&listaDoble, 1);
    agregaAlMedio(&listaDoble, 2);
    agregaAlMedio(&listaDoble, 3);
    agregaAlMedio(&listaDoble, 4);
    agregaAlMedio(&listaDoble, 5);
    agregaAlMedio(&listaDoble, 6);
    agregaAlMedio(&listaDoble, 7);

    muestraListaD(listaDoble);
    muestraListaDReves(listaDoble);

    elimina(&listaDoble, 2);
    elimina(&listaDoble, 2);
    elimina(&listaDoble, 4);
    elimina(&listaDoble, 0);

    muestraListaD(listaDoble);
    muestraListaDReves(listaDoble);

    return 0;
}
