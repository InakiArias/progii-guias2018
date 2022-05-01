#include "headers.h"

int main()
{
    char texto[20] = "Holiwisasd";

    Texto text = crear(texto);

    printf("%d\n", text.largo);
    puts(text.txt);

    destruir(text);

    char texto2[20] = "asd";

    printf("%d\n", text.largo);
    puts(text.txt);



    return 0;
}
