#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    float *array = malloc(sizeof(float) * n);

    int i;

    for (i = 0; i < n; i++) {
        scanf("%f", array + i);
    }

    for (i = 0; i < n; i++) {
        if (*(array + i) > 0)
            printf("%g\n", *(array + i));
    }

    free(array);

    return 0;
}
