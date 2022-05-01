#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *aBinario(int num) {
    static char result[64] = "";
    char intermedio[64];

    int actual = num;

    while (actual != 0) {
        strcpy(intermedio, actual % 2 == 0 ? "0" : "1");
        strcat(intermedio, result);
        strcpy(result, intermedio);
        actual /= 2;
    }

    return result;
}

int main()
{
    puts(aBinario(10));

    return 0;
}
