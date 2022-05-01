#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DOCENTE 0
#define ALUMNO 1
#define EXTERNO 2
#define DESC_DOCENTE 0.7
#define DESC_ALUMNO 0.9

typedef struct n {
    char *apellido, *nombre;
    int categ;
    struct n *ant, *sig;
} nodo;

typedef nodo* PNodo;

typedef struct {
    PNodo pri, ult;
} Lista;

PNodo creaNodo(char apellido[], char nombre[], int categ) {
    PNodo p = malloc(sizeof(nodo));

    p->apellido = malloc(sizeof(char) * (strlen(apellido) + 1));
    strcpy(p->apellido, apellido);
    p->nombre = malloc(sizeof(char) * (strlen(nombre) + 1));
    strcpy(p->nombre, nombre);
    p->categ = categ;
    p->ant = NULL;
    p->sig = NULL;

    return p;

}

void insertaOrdenado(PNodo insertado, Lista *listaInscriptos) {
    PNodo *ptr = &listaInscriptos->pri;
    PNodo anterior = NULL;

    while (*ptr != NULL && strcmp(insertado->apellido, (*ptr)->apellido) > 0) {
        anterior = *ptr;
        ptr = &(*ptr)->sig;
    }

    while (*ptr != NULL && strcmp(insertado->apellido, (*ptr)->apellido) == 0 && strcmp(insertado->nombre, (*ptr)->nombre) > 0) {
        anterior = *ptr;
        ptr = &(*ptr)->sig;
    }


    if (*ptr != NULL && strcmp(insertado->apellido, (*ptr)->apellido) == 0 && strcmp(insertado->nombre, (*ptr)->nombre) == 0) {
        (*ptr)->categ = insertado->categ;
        return;
    }

    insertado->sig = *ptr;

    insertado->ant = anterior;

    if (*ptr != NULL)
        (*ptr)->ant = insertado;
    else
        listaInscriptos->ult = insertado;

    *ptr = insertado;
}

void agregaInscripto(char apellido[], char nombre[], int categ, Lista *listaInscriptos) {
    PNodo nuevoInscripto = creaNodo(apellido, nombre, categ);
    insertaOrdenado(nuevoInscripto, listaInscriptos);
}

void muestraInscriptos(Lista listaInscriptos) {
    PNodo ptr = listaInscriptos.pri;

    while (ptr != NULL) {
        printf("%s, %s | Categ: %d\n", ptr->apellido, ptr->nombre, ptr->categ);
        //if (ptr->ant != NULL)
            //printf("Anterior", ptr->ant->apellido);
        ptr = ptr->sig;
    }

    printf("\n\n");

}

void muestraInscriptosReves(Lista listaInscriptos) {
    PNodo ptr = listaInscriptos.ult;

    while (ptr != NULL) {
        printf("%s, %s | Categ: %d\n", ptr->apellido, ptr->nombre, ptr->categ);
        ptr = ptr->ant;
    }

    printf("\n\n");

}

void iniciales(Lista *listaInscriptos) {
    agregaInscripto("Frias", "Joaquina", 1, listaInscriptos);
    agregaInscripto("Almada", "Gustavo", 2, listaInscriptos);
    agregaInscripto("Almada", "Roberto", 2, listaInscriptos);
    agregaInscripto("Almada", "Juan", 2, listaInscriptos);
    agregaInscripto("Becerra", "Gabriel", 2, listaInscriptos);
    agregaInscripto("Martinez", "Lautaro", 2, listaInscriptos);
    agregaInscripto("O", "Lautaro", 2, listaInscriptos);
    agregaInscripto("B", "Lautaro", 2, listaInscriptos);
    agregaInscripto("E", "Lautaro", 2, listaInscriptos);
    agregaInscripto("O", "Samir", 2, listaInscriptos);
}

float importeTotal(Lista listaInscriptos, float importe) {
    PNodo ptr = listaInscriptos.pri;
    float res = 0;

    while (ptr != NULL) {
        switch(ptr->categ) {
            case DOCENTE: res += DESC_DOCENTE * importe; break;
            case ALUMNO: res += DESC_ALUMNO * importe; break;
            default: res += importe; break;
        }
        ptr = ptr->sig;
    }

    return res;
}

int main()
{
    float importe = 100;
    Lista listaInscriptos; listaInscriptos.pri = NULL; listaInscriptos.ult = NULL;

    iniciales(&listaInscriptos);

    muestraInscriptos(listaInscriptos);
    muestraInscriptosReves(listaInscriptos);

    printf("%g", importeTotal(listaInscriptos, importe));

    return 0;
}
