#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* CUENTA PALABRAS.
ESTE PRORAMA CALCULA EL NUMERO DE PALABRAS QUE HAY EN LA CADENA DE CARACTERES. */

int cuentap(char *);   /* PROTOTIPO DE FUNCION. */

void main(void)
{
    int i;
    char fra[50];
    printf("\nIngrese la linea de texto: ");
    gets(fra);
    strcat(fra, " ");    /* Se agrega un espacio en blanco al final de la cadena. */
    i = cuentap(fra);
    printf("\nLa linea de texto tiene %d palabras", i);
}

int cuentap(char *cad)
{
    /*LA FUNCION CUENTA EL NUMERO DE PALABRAS QUE HAY EN LA CADENA DE
    CARACTERES .*/
    char *cad0 = "";
    int i = 0;
    cad0 = strstr(cad, " "); /*SE LOCALIZA EL PRIMER ESPACIO EN BLANCO EN LA CADENA. */
    while (strstr(cad, " "))
    {
        strcpy(cad, cad0);
        i++;
        cad0 = strstr (cad + 1, " ");
        /* SE BUSCA UN ESPACIO EN BLANCO A PARTIR DE LA SIGUIENTE POSICION. */
    }
    return(i);
}
