#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PAL 50

typedef struct nj {
    char *nombre;
    int edad;
    struct nj *sig;
} nodoJ;

typedef nodoJ* ListaJug;

typedef struct ne {
    char *nombre;
    int puntaje;
    ListaJug jugadores;
    struct ne *sig;
} nodoE;

typedef nodoE* ListaEq;

ListaJug creaNodoJug(char nombre[], int edad) {
    ListaJug p = malloc(sizeof(nodoJ));

    p->nombre = malloc(sizeof(char) * (strlen(nombre) + 1));
    strcpy(p->nombre, nombre);

    p->edad = edad;

    p->sig = NULL;

    return p;
}

ListaJug creaListaJug(FILE *arch) {
    ListaJug cabeza;
    ListaJug *ptr = &cabeza;

    int edad;
    char nombre[TAM_PAL];

    fscanf(arch, "%d", &edad);
    fgetc(arch);
    fgets(nombre, TAM_PAL, arch);
    strtok(nombre, "\n");

    while (nombre[0] != '0') {
        *ptr = creaNodoJug(nombre, edad);

        fscanf(arch, "%d", &edad);
        fgetc(arch);
        fgets(nombre, TAM_PAL, arch);
        strtok(nombre, "\n");

        ptr = &(*ptr)->sig;
    }

    return cabeza;
}

ListaEq creaNodoEq(char nombre[], int puntaje) {
    ListaEq p = malloc(sizeof(nodoE));

    p->nombre = malloc(sizeof(char) * (strlen(nombre) + 1));
    strcpy(p->nombre, nombre);

    p->puntaje = puntaje;

    p->sig = NULL;

    return p;
}

void insertaEquipoOrdenado(ListaEq insertado, ListaEq *cabeza) {
    ListaEq *ptr = cabeza;

    while ((*ptr) != NULL && insertado->puntaje < (*ptr)->puntaje) {
        ptr = &(*ptr)->sig;
    }

    insertado->sig = *ptr;
    *ptr = insertado;
}

ListaEq creaListaEquipos(char *nomArch) {
    FILE *arch = fopen(nomArch, "r");

    if (arch == NULL)
        return NULL;

    ListaEq cabeza = NULL;
    ListaEq aux;

    char nombre[TAM_PAL];
    int puntaje;

    while (!feof(arch)) {
        fscanf(arch, "%d", &puntaje);
        fgetc(arch);
        fgets(nombre, TAM_PAL, arch);
        strtok(nombre, "\n");

        aux = creaNodoEq(nombre, puntaje);
        aux->jugadores = creaListaJug(arch);
        insertaEquipoOrdenado(aux, &cabeza);
    }

    fclose(arch);

    return cabeza;
}

void muestraEquipos(ListaEq cabeza) {
    ListaEq ptrEq = cabeza;
    ListaJug ptrJug;

    while (ptrEq != NULL) {
        printf("%s | Puntos: %d | Lista de Jugadores: \n", ptrEq->nombre, ptrEq->puntaje);

        ptrJug = ptrEq->jugadores;

        while (ptrJug != NULL) {
            printf("%s | Edad: %d\n", ptrJug->nombre, ptrJug->edad);
            ptrJug = ptrJug->sig;
        }

        printf("\n");

        ptrEq = ptrEq->sig;
    }
}

int main()
{
    ListaEq listaEquipos = creaListaEquipos("Datos.txt");

    muestraEquipos(listaEquipos);


    return 0;
}
