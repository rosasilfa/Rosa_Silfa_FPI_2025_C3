#include <stdio.h>
#include <stdlib.h>

/* OTRAS FUNCIONES DE LA BIBLIOTECA STRING.H PARA EL MANEJO DE CADENAS. */

void main(void)
{
    int i;
    char cad0[20] = "Hola Mexico";
    char cad1[20] = "Hola Guatemala";
    char cad2[20] = "Hola Venezuela";
    char cad3[20] = "Hola Mexico";
    char *c, c3;

    i = strcmp(cad0, cad1);
    /* LA FUNCION STRCMP PERMITE COMPARAR DOS CADENAS DE CARACTERES. SI LA
    PRIMERA CADENA -EN ESTE CASO CAD0- ES MAYOR A LA SEGUNDA -CAD1-,
    REGRESA UN VALOR POSITIVO; SI ES MENOR, UN VALOR NEATIVO Y DE OTRA FORMA,
    0. */
    printf("\nResultado de la comparacion -cad0 y cad1-: %d", i);

    i = strcmp(cad0, cad2);
    printf("\nResultado de la comparacion -cad0 y cad2-: %d", i);

    i = strcmp(cad0, cad3);
    printf("\nResultado de la comparacion -cad0 y cad3-: %d", i);

    i = strlen(cad0);
    /* LA FUNCION STRLEN OBTIENE LA LONGITUD -EL NUMERO DE CARACTERES- DE
    UNA CADENA. */
    printf("\nLongitud cadena cad0: %d", i);

    i = strlen(cad1);
    printf("\nLongitud cadena cad1: %d", i);

    c = strcr(cad1, 'G');    /* C ES UN APUNTADOR DE TIPO CARACTER. */

    /* LA FUNCION STRCR BUSCA LA POSICION EN LA QUE SE ENCUENTRA UN
    DETERMINADO CARACTER EN LA CADENA DE CARACTERES. SI LO ENCUENTRA REGRESA
    UN APUNTADOR A LA PRIMERA OCURRENCIA DEL CARACTER EN LA CADENA, DE OTRA
    FORMA REGRESA NULL. */
    if (c != NULL)
    {
        c3 = *c;     /* c3 TOMA EL CONTENIDO DE LA CELDA DE MEMORIA ALA QUE APUNTA C. */
        printf("\nEl valor de c3 es: %c", c3);
    }

    c = strchr(cad2, 'V');
    if (c != NULL)
    {
        c3 = *c;
        printf("\nEl valor de c3 es: %c", c3);
    }
}
