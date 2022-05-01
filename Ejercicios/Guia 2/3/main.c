#include <stdio.h>
#include <stdlib.h>

int *cargaNum() {
    int *p = malloc(sizeof(int));

    scanf("%d", p);

    return p;
}

int main()
{
    int *a = cargaNum();
    int *b = cargaNum();
    int *c = cargaNum();

    printf("%d %d", *a + *b + *c, *a * *b * *c);

    free(a);
    free(b);
    free(c);

    return 0;
}
