#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float vel, velMax;
    char patente[7], fecha[30];
} medicion;

void creaArch(const char *nomDatos, const char *nomArch) {
    FILE *datos = fopen(nomDatos, "r");
    FILE *arch = fopen(nomArch, "wb");
    medicion medi;

    while (!feof(datos)) {
        fscanf(datos, "%s %f %f %s", medi.patente, &medi.vel, &medi.velMax, medi.fecha);

        if (medi.vel > 1.2 * medi.velMax)
            fwrite(&medi, sizeof(medicion), 1, arch);
    }
    fclose(datos);
    fclose(arch);
}

void muestraArch(const char *nomArch) {
    FILE *arch = fopen(nomArch, "rb");
    medicion medi;

    fread(&medi, sizeof(medicion), 1, arch);

    while (!feof(arch)) {
        printf("%s %f %f %s\n", medi.patente, medi.vel, medi.velMax, medi.fecha);
        fread(&medi, sizeof(medicion), 1, arch);
    }

    fclose(arch);
}



int main()
{
    const char *nomDatos = "datos.txt", *nomArch = "arch.dat";

    //creaArch(nomDatos, nomArch);
    muestraArch(nomArch);

    return 0;
}
