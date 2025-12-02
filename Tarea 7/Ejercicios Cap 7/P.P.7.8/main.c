#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* MINUSCUÑAS Y MAYUSCULAS.
EL PROGRAMA, AL RECIBIR COMO DATO UN ARREGLO UNIDIMENSIONAL DE TIPO
CADENA DE CARACTERES, DETERMINA EL NUMERO DE MINUSCULAS Y MAYUSCULAS
QUE HAY EN CADA CADENA. */

void minymay(char cad);       /* PROTOTIPO DE FUNCION. */

void main(void)
{
    int i, n;
    char FRA[20][50];
    /* OBSERVA COMO SE DECLARA EL ARRELO UNIDIMENSIONAL DE CADENA DE
    CARACTERES. */

    printf("\nIngrese el numero de filas del arreglo: ");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        /* PARA CADA FILA SE LEE LA CADENA CORRESPONDIENTE. */
        printf("Ingrese la linea %d de texto: ", i+1);
        fflush(stdin);
        gets(FRA[i]);
    }
    printf("\n\n");
    for (i=0; i<n; i++)
        minymay(FRA[i]);
}

void minymay(char *cadena)
/* ESTA FUNCION SE UTILIZA PARA CALCULAR EL NUMERO DE MINUSCULAS
Y MAYUSCULAS QUE HAY EN CADA CADENA. */
{
    int i = 0, mi = 0, ma = 0;
    while(cadena[i] != '\0')
    {
        if (islower(cadena[i]))
            mi++;
        else
            if(isupper(cadena[i]))
            ma++;
        i++
    }
    printf("\n\nNumero de letras minusculas: %d", mi);
    printf("\nNumero de letras mayusculas: %d", ma);
}
