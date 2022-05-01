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

int mul3(Arbol nodo) {
    if (nodo == NULL)
        return 0;
    if (nodo->dato % 3 == 0)
        return mul3(nodo->izq) + mul3(nodo->der) + nodo->dato;

    return mul3(nodo->izq) + mul3(nodo->der);
}

int hojas(Arbol nodo) {
    if (nodo == NULL)
        return 0;
    if (nodo->izq == NULL && nodo->der == NULL)
        return 1;

    return hojas(nodo->izq) + hojas(nodo->der);
}

int busca(Arbol nodo, int valor) {
    if (nodo == NULL)
        return 0;
    return nodo->dato == valor || busca(nodo->izq, valor) || busca(nodo->der, valor);
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

    printf("Mul3: %d\n", mul3(n1));
    printf("Hojas: %d\n", hojas(n1));
    int valor = 10;
    printf("Valor: %d Esta: %d", valor, busca(n1, valor));

    return 0;
}
