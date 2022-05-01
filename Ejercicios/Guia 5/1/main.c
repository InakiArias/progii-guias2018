#include "headers.h"

int main()
{
    /*PilaE p = iniciaPE();

    int i;

    for (i=0; i<30; i++)
        ponePE(&p, 17);

    printf("%d\n", vaciaPE(p));
    printf("%d\n", p.tope);

    ponePE(&p, 30);

    printf("%d\n", sacaPE(&p));
    printf("%d\n", sacaPE(&p));
    printf("%d\n", consultaPE(p));*/

    //------------------------------------------------------------------------------------

    /*PilaD p = iniciaPD();

    printf("%d", VaciaPD(p));

    printf("%g\n", consultaPD(p));

    ponePD(&p, 25);
    ponePD(&p, 30);
    ponePD(&p, 45);
    ponePD(&p, 60);

    printf("%g\n", consultaPD(p));

    printf("%g\n", sacaPD(&p));
    printf("%g\n", sacaPD(&p));
    printf("%g\n", sacaPD(&p));
    printf("%g\n", sacaPD(&p));*/

    //------------------------------------------------------------------------------------

    Cola c = iniciaC();

    printf("%d\n", vaciaC(c));

    poneC(&c, 50);
    poneC(&c, 40);
    poneC(&c, 30);
    poneC(&c, 20);
    poneC(&c, 10);

    //printf("%d\n", consultaC(c));

    printf("%d\n", sacaC(&c));
    printf("%d\n", sacaC(&c));
    printf("%d\n", sacaC(&c));
    printf("%d\n", sacaC(&c));
    printf("%d\n", sacaC(&c));
    printf("%d\n", sacaC(&c));


    return 0;
}
