#include <stdio.h>
#include <stdlib.h>

#define LARGO_ARR(a) sizeof(a) / sizeof(a[0])

typedef char TElemLista;

typedef struct n {
    TElemLista dato;
    struct n *sig;
} nodo;

typedef nodo* Lista;

void muestraLista(Lista l) {
    Lista p = l;

    while (p != NULL) {
        printf("%c\n", p->dato);
        p = p->sig;
    }

    printf("\n\n");
}

Lista creaNodo(TElemLista dato) {
    Lista p = malloc(sizeof(nodo));
    p->dato = dato;
    p->sig = NULL;
    return p;
}

Lista creaLista(char *str) {
    Lista cabeza;
    Lista *p = &cabeza;

    int i = 0;

    while (str[i]) {
        *p = creaNodo(str[i]);
        p = &(*p)->sig;
        i++;
    }

    return cabeza;
}

Lista creaLista2(char *str) {
    if (str[0] == 0)
        return NULL;

    Lista cabeza = creaNodo(str[0]), p = cabeza;

    int i = 1;

    while (str[i]) {
        p->sig = creaNodo(str[i]);
        p = p->sig;
        i++;
    }

    return cabeza;
}

int ordenada(Lista l) {
    if (l == NULL)
        return 1;

    Lista p = l;

    while (p->sig != NULL && p->dato <= p->sig->dato)
        p = p->sig;

    return p->sig == NULL;
}

void invierte(Lista *l) {
    Lista actual = *l, anterior = NULL, siguiente;

    while (actual != NULL) {
        siguiente = actual->sig;
        actual->sig = anterior;
        anterior = actual;
        actual = siguiente;
    }

    *l = anterior;
}

void elimina(Lista *l, int pos) {
    if (*l == NULL)
        return;

    if (pos == 0) {
        Lista aux = *l;
        *l = (*l)->sig;
        free(aux);
        return;
    }

    Lista actual = *l, anterior;
    int i = 0;

    while (actual != NULL && i < pos) {
        anterior = actual;
        actual = actual->sig;
        i++;
    }

    if (actual != NULL) {
        anterior->sig = actual->sig;
        free(actual);
    }

}

int main()
{
    Lista l = creaLista("Holas");

    muestraLista(l);

    printf("%d\n\n", ordenada(l));

    invierte(&l);

    muestraLista(l);


    elimina(&l, 0);
    elimina(&l, 0);
    elimina(&l, 0);
    elimina(&l, 0);
    elimina(&l, 0);
    elimina(&l, 0);
    elimina(&l, 0);

    muestraLista(l);



    return 0;
}
