#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int dni;
    char sexo;
    struct n *sig;
} nodo;

typedef nodo* Lista;

Lista creaNodo(int dni, char sexo) {
    Lista p = malloc(sizeof(nodo));

    p->dni = dni;
    p->sexo = sexo;
    p->sig = NULL;

    return p;
}

void agregaVotante(int dni, char sexo, Lista *ult) {
    Lista nuevoVotante = creaNodo(dni, sexo);

    if (*ult == NULL) {
        *ult = nuevoVotante;
        (*ult)->sig = *ult;
    }
    else {
        nuevoVotante->sig = (*ult)->sig;
        (*ult)->sig = nuevoVotante;
        *ult = nuevoVotante;
    }
}

void muestraVotantes(Lista ultimo) {
    Lista ptr = ultimo->sig;

    do {
        printf("%d\n", ptr->dni);
        ptr = ptr->sig;
    } while (ptr != ultimo->sig);

}

int main()
{
    Lista listaVotantes = NULL;

    agregaVotante(5, 'M', &listaVotantes);
    agregaVotante(10, 'M', &listaVotantes);
    agregaVotante(20, 'M', &listaVotantes);

    muestraVotantes(listaVotantes);

    return 0;
}
