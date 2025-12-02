#include <stdio.h>

/* CALCULA LA LONGITUD EN FORMA RECURSIVA.
EL PROGRAMA CALCULA DE MANERA RECURSIVA LA LONGITUD DE LA CADENA SIN UTILIZAR
LA FUNCION STRLEN. */

int cuenta(char *);    /* PROTOTIPO DE FUNCION. */

void main(void)
{
    int i;
    char cad[50];
    printf("\nIngrese la cadena de caracteres: ");
    gets(cad);
    i = cuenta(cad);
    printf("\nLongitud de la cadena: %d", i);
}

int cuenta(char *cadena)
/* ESTA FUNCION CALCULA LA LONGITUD DE LA CADENA EN FORMA RECURSIVA. ES
IMPORTANTE TENER CONOCIMIENTOS TANTO DE PILAS COMO DE RECURSIVIDAD PARA
COMPRENDER LA SOLUCION PROPUESTA, AUNQUE ESTA SEA MUY SIMPLE. OBSERVA QUE
MIENTRAS NO LLEGUEMOS AL ULTIMO CARACTER DE LA CADENA, INCREMENTAMOS LA
CUENTA EN UNO Y LLAMAMOS A LA FUNCION CON EL SIGUIENTE CARACTER. */
{
    if (cadena[0] == '\0')
        return 0;
    else
        return (1 + cuenta(&cadena[1]));
}
