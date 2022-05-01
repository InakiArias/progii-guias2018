#include <stdio.h>
#include <stdlib.h>

typedef struct a {
    int dato;
    struct a *izq, *der;
} nodo;

typedef nodo* Arbol;

Arbol creaNodo(int dato) {
    Arbol a = malloc(sizeof(nodo));

    a->dato = dato;
    a->izq = NULL;
    a->der = NULL;

    return a;
}

void preorden(Arbol nodo) {
    if (nodo != NULL) {
        printf("%d\n", nodo->dato);
        preorden(nodo->izq);
        preorden(nodo->der);
    }
}

void inorden(Arbol nodo) {
    if (nodo != NULL) {
        inorden(nodo->izq);
        printf("%d\n", nodo->dato);
        inorden(nodo->der);
    }
}

void postorden(Arbol nodo) {
    if (nodo != NULL) {
        postorden(nodo->izq);
        postorden(nodo->der);
        printf("%d\n", nodo->dato);
    }
}

int main()
{
    Arbol n1 = creaNodo(5);
    Arbol n2 = creaNodo(8);
    Arbol n3 = creaNodo(3);
    Arbol n4 = creaNodo(6);
    Arbol n5 = creaNodo(4);
    Arbol n6 = creaNodo(1);
    Arbol n7 = creaNodo(2);

    n1->izq = n2;
    n2->izq = n3;
    n2->der = n4;
    n1->der = n5;
    n5->izq = n6;
    n6->der = n7;

    preorden(n1); printf("\n");
    inorden(n1); printf("\n");
    postorden(n1); printf("\n");


    return 0;
}
