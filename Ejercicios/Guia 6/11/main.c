#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LARGO_MAX_STR 50
#define LETRAS 26

#define NO_ENCONTRADO 0
#define ERROR 0
#define ENCONTRADO 1
#define COMPLETADO 1

typedef struct nl {
    char *titulo;
    int anio;
    struct nl *sig;
} nodoL;

typedef nodoL* ListaLibro;

typedef struct nas {
    char *nombre;
    ListaLibro libros;
    struct nas *sig;
} nodoAS;

typedef nodoAS* ListaAutorOSocio;

ListaLibro creaNodoLibro(char titulo[], int anio) {
    ListaLibro p = malloc(sizeof(nodoL));

    p->anio = anio;
    p->titulo = malloc(sizeof(char) * (strlen(titulo) + 1));
    strcpy(p->titulo, titulo);
    p->sig = NULL;

    return p;
}

void insertaLibroOrdenado(ListaLibro insertado, ListaLibro *cabeza) {
    ListaLibro *ptr = cabeza;

    while (*ptr != NULL && strcmp(insertado->titulo, (*ptr)->titulo) > 0)
        ptr = &(*ptr)->sig;

    insertado->sig = *ptr;
    *ptr = insertado;
}

ListaAutorOSocio creaNodoAutorOSocio(char nombre[]) {
    ListaAutorOSocio p = malloc(sizeof(nodoAS));

    p->nombre = malloc(sizeof(char) * (strlen(nombre) + 1));
    strcpy(p->nombre, nombre);
    p->libros = NULL;
    p->sig = NULL;

    return p;
}

void iniciaArreglo(ListaAutorOSocio arr[]) {
    int i;

    for (i = 0; i < LETRAS; i++)
        arr[i] = NULL;
}

void muestraArreglo(ListaAutorOSocio arr[]) {
    int i;
    ListaAutorOSocio ptrAS;
    ListaLibro ptrLi;

    for (i = 0; i < LETRAS; i++){
        ptrAS = arr[i];

        if (ptrAS != NULL)
            printf("\nLetra %c:\n", i + 65);

        while(ptrAS != NULL) {
            printf("\tAutor: %s\n", ptrAS->nombre);

            ptrLi = ptrAS->libros;

            while (ptrLi != NULL) {
                printf("\t\tTitulo: %s | Edicion: %d\n", ptrLi->titulo, ptrLi->anio);

                ptrLi = ptrLi->sig;
            }

            ptrAS = ptrAS->sig;

            printf("\n");
        }
    }
}

void agregaLibroALista(char autor[], char titulo[], int anio, ListaAutorOSocio *cabeza) {
    ListaAutorOSocio *ptrAS = cabeza;
    ListaLibro nuevoLibro = creaNodoLibro(titulo, anio);

    while (*ptrAS != NULL && strcmp(autor, (*ptrAS)->nombre) > 0)
        ptrAS = &(*ptrAS)->sig;

    if (*ptrAS != NULL && strcmp(autor, (*ptrAS)->nombre) == 0) {
        insertaLibroOrdenado(nuevoLibro, &(*ptrAS)->libros);
        return;
    }

    ListaAutorOSocio nuevoAutor = creaNodoAutorOSocio(autor);
    nuevoAutor->libros = nuevoLibro;
    nuevoAutor->sig = *ptrAS;
    *ptrAS = nuevoAutor;
}

void agregaLibroAlArreglo(char autor[], char titulo[], int anio, ListaAutorOSocio arr[]) {
    int indice = toupper(autor[0]) - 65;

    agregaLibroALista(autor, titulo, anio, &arr[indice]);
}

int buscaLibro(char autor[], char titulo[], int anio, ListaAutorOSocio cabeza) {
    ListaAutorOSocio ptrAS = cabeza;

    while (ptrAS != NULL && strcmp(autor, ptrAS->nombre) != 0)
        ptrAS = ptrAS->sig;

    if (ptrAS == NULL)
        return NO_ENCONTRADO;

    ListaLibro ptrLi = ptrAS->libros;

    while (ptrLi != NULL && strcmp(titulo, ptrLi->titulo) != 0)
        ptrLi = ptrLi->sig;

    if (ptrLi == NULL || strcmp(titulo, ptrLi->titulo) != 0)
        return NO_ENCONTRADO;
    else
        return ENCONTRADO;
}

int registraPrestamo(char socio[], char autor[], char titulo[], int anio, ListaAutorOSocio arr[], ListaAutorOSocio *listaSocios) {
    int indice = toupper(autor[0]) - 65;

    if (buscaLibro(autor, titulo, anio, arr[indice])) {
        agregaLibroALista(socio, titulo, anio, listaSocios);
        return COMPLETADO;
    }
    else
        return ERROR;
}

void librosIniciales(ListaAutorOSocio arregloAutores[]) {
    iniciaArreglo(arregloAutores);

    agregaLibroAlArreglo("Galeano, Eduardo", "Venas Abiertas", 2010, arregloAutores);
    agregaLibroAlArreglo("Galeano, Eduardo", "Venas Abiertas", 2012, arregloAutores);
    agregaLibroAlArreglo("Galeano, Eduardo", "Venas Abiertas", 2014, arregloAutores);
    agregaLibroAlArreglo("Cortazar, Julio", "Las Armas Secretas", 1995, arregloAutores);
    agregaLibroAlArreglo("Christie, Agatha", "Muerte en el Nilo", 1995, arregloAutores);
    agregaLibroAlArreglo("Christie, Agatha", "Asesinato en el Oriente Express", 1995, arregloAutores);
}

void muestraSocios(ListaAutorOSocio listaSocios) {
    ListaAutorOSocio ptrAS = listaSocios;
    ListaLibro ptrLi;

    while(ptrAS != NULL) {
        printf("Socio: %s\n", ptrAS->nombre);

        ptrLi = ptrAS->libros;

        while (ptrLi != NULL) {
            printf("\tTitulo: %s | Edicion: %d\n", ptrLi->titulo, ptrLi->anio);

            ptrLi = ptrLi->sig;
        }

        ptrAS = ptrAS->sig;

        printf("\n");
    }

}

int cancelaPrestamo(char socio[], char titulo[], int anio, ListaAutorOSocio listaSocios) {
    ListaAutorOSocio ptrAS = listaSocios;
    ListaLibro *ptrLi;

    while (ptrAS != NULL && strcmp(socio, ptrAS->nombre) != 0)
        ptrAS = ptrAS->sig;

    if (ptrAS == NULL)
        return ERROR;

    ptrLi = &ptrAS->libros;

    while (*ptrLi != NULL && strcmp(titulo, (*ptrLi)->titulo) != 0)
        ptrLi = &(*ptrLi)->sig;

    if (*ptrLi == NULL)
        return ERROR;

    ListaLibro aux = *ptrLi;
    *ptrLi = (*ptrLi)->sig;
    free(aux);
    return COMPLETADO;
}


int main()
{
    ListaAutorOSocio arregloAutores[LETRAS];
    ListaAutorOSocio listaSocios = NULL;

    librosIniciales(arregloAutores);

    muestraArreglo(arregloAutores);

    registraPrestamo("Pepe", "Cortazar, Julio", "Las Armas Secretas", 1995, arregloAutores, &listaSocios);
    registraPrestamo("Pepe", "Christie, Agatha", "Asesinato en el Oriente Express", 1995, arregloAutores, &listaSocios);

    cancelaPrestamo("Pepe", "Asesinato en el Oriente Express", 1995, listaSocios);



    muestraSocios(listaSocios);


    return 0;
}
