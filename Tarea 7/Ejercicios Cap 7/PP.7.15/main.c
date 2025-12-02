#include <stdio.h>
#include <ctype.h>

/* DECODIFICA.
EL PROGRAMA DECODIFICA UNA CADENA DE CARACTERES COMPUESTA POR NUMEROS Y
LETRAS. */

void interpreta(char *);    /* Prototipo de funcion. */

void main(void)
{
    char cad[50];
    printf("\nIngrese la cadena de caracteres: ");
    gets(cad);
    interpreta(cad);
}

void interpreta(char *cadena)
/* ESTA FUNCION SE UTILIZA PARA DECODIFICAR LA CADENA DE CARACTERES. */
{
    int i = 0, j, k;
    while (cad[i] != '\0')
    {
        if(isalpha(cad[i]))   /* SE UTILIZA ISALPHA PARA OBSERVAR SI EL CARACTER
                              ES UNA LETRA. */
        {
            k = cad[i - 1] - 48;
            /* EN LA VARIABLE ENTERA K SE ALMACENA EL ASCII DEL NUMERO - CONVERTIDO
            EN CARACTER- QUE NOS INTERESA, MENOS 48 CORRESPONDE AL ASCII
            DEL DIGITO 0. */
            for (j = 0; j < k; j++)
                putchar(cad[i]);
        }
        i++;
    }
}
