#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct a {
    char *dato;
    struct a *izq, *der;
} nodo;

typedef nodo* Arbol;

Arbol creaNodo(char dato[]) {
    Arbol a = malloc(sizeof(nodo));

    a->dato = malloc(sizeof(char) * (strlen(dato) + 1));
    strcpy(a->dato, dato);
    a->izq = NULL;
    a->der = NULL;

    return a;
}

void preorden(Arbol nodo) {
    if (nodo != NULL) {
        printf("%s\n", nodo->dato);
        preorden(nodo->izq);
        preorden(nodo->der);
    }
}

void inorden(Arbol nodo) {
    if (nodo != NULL) {
        inorden(nodo->izq);
        printf("%s\n", nodo->dato);
        inorden(nodo->der);
    }
}

void postorden(Arbol nodo) {
    if (nodo != NULL) {
        postorden(nodo->izq);
        postorden(nodo->der);
        printf("%s\n", nodo->dato);
    }
}

void profRecu(Arbol nodo, int profActual, int *profundidad) {
    if (nodo != NULL) {
        profRecu(nodo->izq, profActual + 1, profundidad);
        profRecu(nodo->der, profActual + 1, profundidad);

        if (profActual > *profundidad)
            *profundidad = profActual;
    }
}

int profundidad(Arbol raiz) {
    int prof = 0;
    profRecu(raiz, 0, &prof);
    return prof;
}

int cadMasLarga(Arbol nodo) {
    if (nodo == NULL)
        return 0;

    int cadActual = strlen(nodo->dato);

    int cadIzq = cadMasLarga(nodo->izq);

    int masLarga = cadIzq > cadActual ? cadIzq : cadActual;

    int cadDer = cadMasLarga(nodo->der);

    masLarga = masLarga > cadDer ? masLarga : cadDer;

    return masLarga;
}

int hijosDerechos(Arbol nodo) {
    if (nodo == NULL)
        return 0;

    if (nodo->der != NULL)
        return hijosDerechos(nodo->izq) + hijosDerechos(nodo->der) + 1;
    else
        return hijosDerechos(nodo->izq) + hijosDerechos(nodo->der);
}

int main()
{
    Arbol n1 = creaNodo("Hola");
    Arbol n2 = creaNodo("Chauss");
    Arbol n3 = creaNodo("Jej");
    Arbol n4 = creaNodo("Como va");
    Arbol n5 = creaNodo("Adios");
    Arbol n6 = creaNodo("Bien bien");
    Arbol n7 = creaNodo("Hm");

    n1->izq = n2;
    n2->izq = n3;
    n2->der = n4;
    n1->der = n5;
    n5->izq = n6;
    n6->der = n7;


    preorden(n1); printf("\n");
    inorden(n1); printf("\n");
    postorden(n1); printf("\n");

    printf("Profundidad: %d\n", profundidad(n1));
    printf("Cad mas larga: %d\n", cadMasLarga(n1));
    printf("Hijos derechos: %d\n", hijosDerechos(n1));


    return 0;
}
