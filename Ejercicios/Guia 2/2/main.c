#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, a = 4, b = 5;
    p = &b;
    *p *= 2;
    printf("b=%d *p=%d\n", b, *p); // 10 10
    printf("&b=%p p=%p &p=%p\n", &b, p, &p); // A1 A1 A2
    b = *p *3;
    printf("b=%d *p=%d\n", b, *p); //30 30
    printf("&b=%p p=%p\n", &b, p); //A1 A1
    a = b;
    p = &a;
    (*p)++;
    printf("b=%d a=%d *p=%d\n", b, a, *p); //30 31 31
    printf("&b=%p &a=%p p=%p &p=%p \n", &b, &a, p, &p); //A1 A3 A3 A2

    return 0;
}
