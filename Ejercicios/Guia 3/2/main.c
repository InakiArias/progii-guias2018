#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

int main()
{
    booleano b1 = crear(0);
    booleano b2 = crear(0);

    printf("%d", val(andd(b1,b2)));
    printf("%d", val(orr(b1,b2)));
    printf("%d", val(nott(b1)));
    printf("%d", val(nott(b2)));




    return 0;
}
