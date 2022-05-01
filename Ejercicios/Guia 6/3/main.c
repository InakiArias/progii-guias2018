#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LARGO_ARR(a) sizeof(a) / sizeof(a[0])

#define TAM_PAL 30

typedef char* TElemLista;

typedef struct n {
    TElemLista dato;
    int cant;
    struct n *sig;
} nodo;

typedef nodo* Lista;

void muestraLista(Lista l) {
    Lista p = l;

    while (p != NULL) {
        printf("Cant: %d, Palabra: ", p->cant);
        puts(p->dato);
        p = p->sig;
    }

    printf("\n\n");
}

Lista creaNodo(char dato[]) {
    Lista p = malloc(sizeof(nodo));

    p->dato = malloc(sizeof(char) * (strlen(dato) + 1));
    strcpy(p->dato, dato);

    p->cant = 1;

    p->sig = NULL;

    return p;
}

void buscaPos(Lista l, char dato[], Lista *anterior, Lista *actual, int *datoEsta) {
    *actual = l;
    *anterior = NULL;

    while (*actual != NULL && strcmp(dato, (*actual)->dato) > 0) {
        *anterior = *actual;
        *actual = (*actual)->sig;
    }

    *datoEsta = *actual != NULL && strcmp(dato, (*actual)->dato) == 0;
}

Lista creaLista(char *rutaArch) {
    FILE *arch = fopen(rutaArch, "r");
    char str[TAM_PAL];
    Lista l = NULL;

    while (!feof(arch)) {
        fgets(str, TAM_PAL, arch);
        strtok(str, "\n");

        Lista actual, anterior;
        int datoEsta;

        buscaPos(l, str, &anterior, &actual, &datoEsta);

        if (datoEsta) {
            actual->cant++;
        }
        else if (anterior == NULL) {
            Lista nuevo = creaNodo(str);
            nuevo->sig = actual;
            l = nuevo;
        }
        else {
            Lista nuevo = creaNodo(str);
            nuevo->sig = actual;
            anterior->sig = nuevo;
        }

    }

    return l;

}

int main()
{
    Lista l = creaLista("Datos.txt");

    muestraLista(l);




    return 0;
}
