typedef int tElementoC;

typedef struct nodo {
    tElementoC dato;
    struct nodo *sig;
} nodo;

typedef struct {
    nodo *pri, *ult;
} Cola;

Cola iniciaC();
int vaciaC(Cola c);
void poneC(Cola *c, tElementoC x);
tElementoC consultaC(Cola c);
tElementoC sacaC(Cola *c);
