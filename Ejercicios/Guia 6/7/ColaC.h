#define TAM_COLA 50

typedef int tElementoC;

typedef struct {
    tElementoC datos[TAM_COLA];
    int pri, ult;
} Cola;

Cola iniciaC();
int vaciaC(Cola c);
void poneC(Cola *c, tElementoC x);
tElementoC consultaC(Cola c);
tElementoC sacaC(Cola *c);



