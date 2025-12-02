#include <stdio.h>
#include <string.h>

/* CUENTA CADENAS.
EL PROGRAMA, AL RECIBIR DOS CADENAS DE CARACTERES, CALCULA E IMPRIME CUANTAS
VECES SE ENCUENTRA LA SEGUNDA CADENA EN LA PRIMERA. */

void main(void)
{
    char cad1[50], cad2[50], *cad0 = "";
    int i = 0;
    printf("\n Inrese la primera cadena de caracteres: ");
    gets(cad1);
    printf("\n Ingrese la cadena a buscar: ");
    gets(cad2);
    strcpy(cad0, cad1);   /* SE COPIA LA CADENA ORIGINAL A CAD0. */
    cad0 = strstr (cad0, cad2);
    /* EN CAD0 SE ASIGNA EL APUNTADOR A LA PRIMERA OCURRENCIA DE LA CADENA CAD2.
    SI NO EXISTE SE ALMACENA NULL. */
    while (cad0 != NULL)
    {
        i++;
        cad0 = strstr (cad0 + 1, cad2);
        /* SE MODIFICA NUEVAMENTE LA CADENA, MOVIENDO EL APUNTADOR UNA
        POSICION. */
    }
    printf("\nEl numero de veces que aparece la seunda cadena es: %d", i);
}
