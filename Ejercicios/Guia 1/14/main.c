#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 3, i, j;

    for (i = 0; i < n; i++)
        printf("#");

    printf("\n");

    for (i = 0; i < n - 2; i++) {
        printf("#");

        for (j = 0; j < n - 2; j++)
            printf(" ");

        printf("#\n");
    }

    for (i = 0; i < n; i++)
        printf("#");

    printf("\n");

    return 0;
}
