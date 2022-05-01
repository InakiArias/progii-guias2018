#include <stdio.h>
#include <stdlib.h>

#define LARGO_ARR(a) sizeof(a) / sizeof(a[0])

typedef int TElemLista;

typedef struct n {
    TElemLista dato;
    struct n *sig;
} nodo;

typedef nodo* Lista;

void muestraLista(Lista l) {
    Lista p = l;

    while (p != NULL) {
        printf("%d\n", p->dato);
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

Lista creaLista(int arr[], int n) {
    Lista cabeza;
    Lista *p = &cabeza;

    int i = 0;

    while (i < n) {
        *p = creaNodo(arr[i]);
        p = &(*p)->sig;
        i++;
    }

    return cabeza;
}

void elimina(Lista *l, int pos) {
    if (*l == NULL || pos < 0)
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

void c(Lista *l1, Lista l2) {
    Lista p1 = *l1, p2 = l2;
    int pos = 0, borrados = 0;

    while (p2 != NULL) {
        while (p1 != NULL && pos < p2->dato) {
            p1 = p1->sig;
            pos++;
        }

        if (p1 != NULL) {
            elimina(l1, pos - borrados);
            borrados++;
        }

        p2 = p2->sig;
    }
}

int main()
{
    int arr1[] = {1,3,4,5,7,16,23}, arr2[] = {0,1,3,5,19};
    int n1 = LARGO_ARR(arr1), n2 = LARGO_ARR(arr2);

    Lista l1 = creaLista(arr1, n1), l2 = creaLista(arr2, n2);

    muestraLista(l1);
    muestraLista(l2);

    c(&l1, l2);

    muestraLista(l1);
    muestraLista(l2);

    return 0;
}
