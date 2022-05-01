typedef int tElementoPE;

#define MAX_PE 50

typedef struct {
    tElementoPE pila[MAX_PE];
    int tope;
} PilaE;

PilaE iniciaPE();
int vaciaPE(PilaE p);
void ponePE(PilaE *p, tElementoPE x);
tElementoPE consultaPE(PilaE p);
tElementoPE sacaPE(PilaE *p);
