#include <stdio.h>
#include <stdlib.h>
#include "dupla.h"

int main()
{
    int a = 5, b = 6;

    dupla d = crear(a, b);

    printf("%d %d", primero(d), segundo(d));




    return 0;
}
