#include "headers.h"
#define ORO 0
#define ESPADA 1
#define COPA 2
#define BASTO 3

#define PALOS 4
#define CANT_CARTAS 48
#define CANT_CARTASXPALO 12

const char* NOM_PALOS[] = {"Oro", "Espada", "Copa", "Basto"};

typedef PilaD Pila;

typedef struct {
    int puntaje;
    int ultPalo;
} Jugador;

void muestraPila(Pila *p) {
    if (!vaciaPD(*p)) {
        int n = sacaPD(p);
        muestraPila(p);
        printf("%d\n", n);
        ponePD(p, n);
    }
}

Pila creaMazo() {
    Pila mazo = iniciaPD();
    int auxi[CANT_CARTAS], i;

    for (i = 0; i < CANT_CARTAS; i++)
        auxi[i] = i;

    for (i = CANT_CARTAS - 1; i > 0; i--) {
        int n = rand() % i;
        int aux = auxi[n];
        auxi[n] = auxi[i];
        auxi[i] = aux;
    }

    for (i = 0; i < CANT_CARTAS; i++)
        ponePD(&mazo, auxi[i]);

    return mazo;
}

void cicloJuego() {
    srand(time(NULL));

    Pila mazo = creaMazo();
    int n;

    do {
        printf("Ingrese cantidad de jugadores: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("\n\n");

    Jugador *jugadores = malloc(sizeof(Jugador) * n);

    int turno = 0, i;

    for (i = 0; i < n; i++) {
        jugadores[i].puntaje = 0;
        jugadores[i].ultPalo = -1;
    }

    for (i = 0; i < CANT_CARTAS; i++) {
        printf("Jugador %d, presiona Enter para sacar una carta: ", turno + 1);
        fflush(stdin);
        getc(stdin);

        int carta = sacaPD(&mazo);
        int num = (carta % CANT_CARTASXPALO) + 1;
        int palo = carta / CANT_CARTASXPALO;

        printf("Sacaste el %d de %s.", num, NOM_PALOS[palo]);

        if (jugadores[turno].ultPalo == palo) {
            printf(" Duplicaste!");
            jugadores[turno].puntaje += num * 2;
        }
        else {
            jugadores[turno].puntaje += num;
        }

        printf(" Quedan %d cartas", CANT_CARTAS - i - 1);

        jugadores[turno].ultPalo = palo;
        turno = (turno + 1) % n;

        printf("\n\n");
    }

    printf("PUNTAJES:\n\n");
    int ganador = 0;

    for (i = 0; i < n; i++){
        printf("*Jugador %d: %d puntos\n", i + 1, jugadores[i].puntaje);
        if (jugadores[i].puntaje > jugadores[ganador].puntaje)
            ganador = i;
    }

    printf("\n\nGano el jugador %d!", ganador + 1);

    free(jugadores);
}

int main()
{

    cicloJuego();



    return 0;
}
