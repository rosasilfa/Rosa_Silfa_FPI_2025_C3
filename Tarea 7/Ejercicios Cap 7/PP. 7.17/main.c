#include <stdio.h>
#include <string.h>

/* CADENA INVERTIDA.
ESTE PROGRAMA OBTIENE LA CADENA INVERTIDA. */

char * inverso(char *);   /*PROTOTIPO DE FUNCION. */

void main(void)
{
    char fra[50], aux[50];
    printf("\nIngrese la linea de texto: ");
    gets(fra);
    strcpy(aux, inverso(fra)); /* SE COPIA A AUX EL RESULTADO DE LA FUNCION
    INVERSO. */
    printf("\nEscribe la linea de texto en forma inversa: ");
    puts(aux);
}

char * inverso(char *cadena)
/* LA FUNCION CALCULA EL INVERSO DE UNA CADENA Y REGRESA EL RESULTADO AL
PROGRAMA PRINCIPAL. */
{
    int i = 0, j, lon;
    char cad;
    lon = strlen(cadena);
    j = lon-1;
    while (i < ((lon -1) / 2))
        /* OBSERVA QUE EL REEMPLAZO DE LOS CARACTERES SE DEBE REALIZAR SOLAMENTE
        HASTA LA MITAD DE LA CADENA. */
    {
        cad = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = cad;
        i++;
        j--;
    }
    return (cadena);
}
