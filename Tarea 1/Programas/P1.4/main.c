#include <stdio.h>

/*Superficie del tri�ngulo.
El programa, al recibir como datos la base y la altura de un tri�ngulo,
calcula su superficie.

BAS, ALT y SUP: variables de tipo real. */

void main(void)
{
    float BAS, ALT, SUP;
    printf("Ingrese la base y la altura del triangulo: ");
    scanf("%f %f", &BAS, &ALT);
    SUP = BAS * ALT / 2;
    printf("\nLa superficie del triangulo es: %5.2f", SUP);
}
