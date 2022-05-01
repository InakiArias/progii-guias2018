#include <stdio.h>
#include <stdlib.h>

void creaArch(const char *nomarch) {
    FILE *arch = fopen(nomarch, "ab");
    float num;
    int i;

    for (i = 0; i < 2; i++) {
        scanf("%f", &num);
        fwrite(&num, sizeof(float), 1, arch);
    }

    fclose(arch);
}

void muestraArch(const char *nomarch) {
    FILE *arch = fopen(nomarch, "rb");
    float num;

    fread(&num, sizeof(float), 1, arch);

    while (!feof(arch)) {
        printf("%g\n", num);

        fread(&num, sizeof(float), 1, arch);
    }
}

int main()
{
    const char *nomarch = "arch";

    creaArch(nomarch);
    muestraArch(nomarch);


    return 0;
}
