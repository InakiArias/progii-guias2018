#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LARGO_MAX_STR 50

#define ERROR 0
#define COMPLETADO 1

typedef struct np {
    int documento;
    struct np *sig;
} nodoP;

typedef nodoP* ListaPasajero;

typedef struct nv {
    int codigo;
    int capacidad;
    char *fecha;
    ListaPasajero pasajeros;
    struct nv *sig;
} nodoV;

typedef nodoV* ListaVuelo;

typedef struct nd {
    char *nombre;
    ListaVuelo vuelos;
    struct nd *sig;
} nodoD;

typedef nodoD* ListaDestino;

ListaPasajero creaNodoPasajero(int documento) {
    ListaPasajero p = malloc(sizeof(nodoP));

    p->documento = documento;
    p->sig = NULL;

    return p;
}

ListaPasajero creaListaPasajeros(FILE *arch) {
    ListaPasajero cabeza;
    ListaPasajero *ptr = &cabeza;
    int documento;

    fscanf(arch, "%d", &documento);

    while (documento != 0) {
        *ptr = creaNodoPasajero(documento);

        fscanf(arch, "%d", &documento);

        ptr = &(*ptr)->sig;
    }

    return cabeza;
}

ListaVuelo creaNodoVuelo(int codigo, int capacidad, char fecha[]) {
    ListaVuelo p = malloc(sizeof(nodoV));

    p->codigo = codigo;
    p->capacidad = capacidad;
    p->fecha = malloc(sizeof(char) * (strlen(fecha) + 1));
    strcpy(p->fecha, fecha);
    p->sig = NULL;
    p->pasajeros = NULL;

    return p;
}

void insertaVueloOrdenado(ListaVuelo insertado, ListaVuelo *cabeza) {
    ListaVuelo *ptr = cabeza;

    while (*ptr != NULL && insertado->codigo > (*ptr)->codigo)
        ptr = &(*ptr)->sig;

    insertado->sig = *ptr;
    *ptr = insertado;
}

ListaVuelo creaListaVuelos(FILE *arch) {
    ListaVuelo cabeza;
    ListaVuelo aux;

    int codigo, capacidad;
    char fecha[LARGO_MAX_STR];

    fscanf(arch, "%d %d", &codigo, &capacidad);
    fgetc(arch);
    fgets(fecha, LARGO_MAX_STR, arch);
    strtok(fecha, "\n");

    while (fecha[0] != 'F') {
        aux = creaNodoVuelo(codigo, capacidad, fecha);
        aux->pasajeros = creaListaPasajeros(arch);
        insertaVueloOrdenado(aux, &cabeza);

        fscanf(arch, "%d %d", &codigo, &capacidad);
        fgetc(arch);
        fgets(fecha, LARGO_MAX_STR, arch);
        strtok(fecha, "\n");
    }

    return cabeza;
}

ListaDestino creaNodoDestino(char nombre[]) {
    ListaDestino p = malloc(sizeof(nodoD));

    p->nombre = malloc(sizeof(char) * (strlen(nombre) + 1));
    strcpy(p->nombre, nombre);
    p->sig = NULL;
    p->vuelos = NULL;

    return p;
}

ListaDestino creaListaDestinos(char *nomArch) {
    FILE *arch = fopen(nomArch, "r");

    if (arch == NULL)
        return NULL;

    ListaDestino cabeza;
    ListaDestino *ptr = &cabeza;
    char nombre[LARGO_MAX_STR];

    while (!feof(arch)) {
        fgets(nombre, LARGO_MAX_STR, arch);
        strtok(nombre, "\n");

        *ptr = creaNodoDestino(nombre);
        (*ptr)->vuelos = creaListaVuelos(arch);

        ptr = &(*ptr)->sig;
    }

    return cabeza;
}

void muestraListaDestinos(ListaDestino cabeza) {
    ListaDestino ptrDes = cabeza;
    ListaVuelo ptrVue;
    ListaPasajero ptrPas;

    while (ptrDes != NULL) {
        printf("%s:\n\n", ptrDes->nombre);

        ptrVue = ptrDes->vuelos;

        while (ptrVue != NULL) {
            printf("Cod. Vuelo: %d | Capacidad: %d | Fecha: %s | Docs. de pasajeros: \n", ptrVue->codigo, ptrVue->capacidad, ptrVue->fecha);

            ptrPas = ptrVue->pasajeros;

            while (ptrPas != NULL) {
                printf("*%d\n", ptrPas->documento);
                ptrPas = ptrPas->sig;
            }

            printf("\n");

            ptrVue = ptrVue->sig;
        }

        printf("\n\n");

        ptrDes = ptrDes->sig;
    }

    printf("\n\n");
}

int reserva(char *nomDestino, int codVuelo, int documento, ListaDestino cabeza) {
    ListaDestino ptrDes = cabeza;

    while (ptrDes != NULL && strcmp(ptrDes->nombre, nomDestino) != 0)
        ptrDes = ptrDes->sig;

    if (ptrDes == NULL)
        return ERROR;

    ListaVuelo ptrVue = ptrDes->vuelos;

    while (ptrVue != NULL && ptrVue->codigo != codVuelo)
        ptrVue = ptrVue->sig;

    if (ptrVue == NULL)
        return ERROR;

    ListaPasajero *ptrPas = &ptrVue->pasajeros;

    while (*ptrPas != NULL && (*ptrPas)->documento != documento)
        ptrPas = &(*ptrPas)->sig;

    if (*ptrPas != NULL)
        return ERROR;

    ListaPasajero nuevoPasajero = creaNodoPasajero(documento);

    nuevoPasajero->sig = *ptrPas;
    *ptrPas = nuevoPasajero;
    return COMPLETADO;
}

int cancelacion(char *nomDestino, int codVuelo, int documento, ListaDestino cabeza) {
    ListaDestino ptrDes = cabeza;

    while (ptrDes != NULL && strcmp(ptrDes->nombre, nomDestino) != 0)
        ptrDes = ptrDes->sig;

    if (ptrDes == NULL)
        return ERROR;

    ListaVuelo ptrVue = ptrDes->vuelos;

    while (ptrVue != NULL && ptrVue->codigo != codVuelo)
        ptrVue = ptrVue->sig;

    if (ptrVue == NULL)
        return ERROR;

    ListaPasajero *ptrPas = &ptrVue->pasajeros;

    while (*ptrPas != NULL && (*ptrPas)->documento != documento)
        ptrPas = &(*ptrPas)->sig;

    if (*ptrPas == NULL)
        return ERROR;

    ListaPasajero aux = *ptrPas;
    *ptrPas = (*ptrPas)->sig;
    free(aux);
    return COMPLETADO;
}

int agregaDestino(char *nomDestino, ListaDestino *cabeza) {
    ListaDestino *ptr = cabeza;

    while (*ptr != NULL && strcmp(nomDestino, (*ptr)->nombre) > 0)
        ptr = &(*ptr)->sig;

    if (*ptr != NULL && strcmp(nomDestino, (*ptr)->nombre) == 0)
        return ERROR;

    ListaDestino nuevoDestino = creaNodoDestino(nomDestino);

    nuevoDestino->sig = *ptr;
    *ptr = nuevoDestino;
    return COMPLETADO;
}

int agregaVuelo(char *nomDestino, int codVuelo, int capacidad, char *fecha, ListaDestino cabeza) {
    ListaDestino ptrDes = cabeza;

    while (ptrDes != NULL && strcmp(ptrDes->nombre, nomDestino) != 0)
        ptrDes = ptrDes->sig;

    if (ptrDes == NULL)
        return ERROR;

    ListaVuelo *ptrVue = &ptrDes->vuelos;

    while (*ptrVue != NULL && (*ptrVue)->codigo < codVuelo)
        ptrVue = &(*ptrVue)->sig;

    if (*ptrVue != NULL && (*ptrVue)->codigo == codVuelo)
        return ERROR;

    ListaVuelo nuevoVuelo = creaNodoVuelo(codVuelo, capacidad, fecha);
    nuevoVuelo->sig = *ptrVue;
    *ptrVue = nuevoVuelo;
    return COMPLETADO;
}

void muestraDestino(char *nomDestino, ListaDestino cabeza) {
    ListaDestino ptrDes = cabeza;

    while (ptrDes != NULL && strcmp(ptrDes->nombre, nomDestino) != 0)
        ptrDes = ptrDes->sig;

    if (ptrDes == NULL) {
        printf("%s: Destino no existe\n\n\n", nomDestino);
        return;
    }

    int cantReservas;
    ListaVuelo ptrVue = ptrDes->vuelos;
    printf("%s:\n", nomDestino);

    while (ptrVue != NULL) {
        printf("Cod. Vuelo: %d | Capacidad: %d | Fecha: %s | ", ptrVue->codigo, ptrVue->capacidad, ptrVue->fecha);

        ListaPasajero ptrPas = ptrVue->pasajeros;
        cantReservas = 0;

        while (ptrPas != NULL) {
            ptrPas = ptrPas->sig;
            cantReservas++;
        }

        printf("Cant. de Reservas: %d\n", cantReservas);

        ptrVue = ptrVue->sig;
    }

    printf("\n\n");
}




int main()
{
    ListaDestino listaDestinos = creaListaDestinos("Datos.txt");

    printf("%d\n", agregaDestino("Roma", &listaDestinos));
    printf("%d\n", agregaVuelo("Bariloche", 9, 450, "20/10/2022|23:56", listaDestinos));
    //printf("%d\n", reserva("Bariloche", 9, 12345, listaDestinos));

    muestraListaDestinos(listaDestinos);

    muestraDestino("Montevideo", listaDestinos);


    return 0;
}
