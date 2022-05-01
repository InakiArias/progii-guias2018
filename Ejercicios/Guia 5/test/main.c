#include <stdio.h>
#include <stdlib.h>
#define REPETIR(a) int i; for(i = 0; i < a; i++)

int main()
{
    REPETIR(50) {
        printf("Hello world!\n");
        printf("Hello!\n");
    }

    return 0;
}
