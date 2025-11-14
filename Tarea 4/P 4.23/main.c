#include <stdio.h>

void trueque(int *x, int *y)
{
    int tem;
    tem = *x;
    *x = *y;
    *y = tem;
}

int suma(int x)
{
    return (x + x);
}
int main()
{
    int a = 5, b = 10;

    printf("Antes del trueque: a=%d, b=%d\n", a, b);
    trueque(&a, &b);
    printf("Después del trueque: a=%d, b=%d\n", a, b);

    int resultado = suma(7);
    printf("La suma doble de 7 es: %d\n", resultado);
    return 0;
}


