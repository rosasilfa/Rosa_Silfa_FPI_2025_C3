#include <stdio.h>
#include <stdlib.h>

/* SUMA Y PROMEDIO.
EL PROGRAMA, AL RECIBIR COMO DATOS VARIAS CADENAS DE CARACTERES QUE
CONTIENEN REALES, LOS SUMA Y OBTIENE EL PROMEDIO DE LOS MISMOS. */

void main(void)
{
    char c, cad[10];
    int i = 0;
    float sum = 0.0;
    printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
    c = getchar();
    while (c == 'S')
    {
        printf("\nInrese la cadena de caracteres: ");
        fflush(stdin);
        gets(cad);
        i++;
        sum += atof(cad);
        printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
        c = getchar();
    }
    printf("\nSuma: %.2f", sum);
    printf("\nPromedio: %.2f", sum / i);
}
