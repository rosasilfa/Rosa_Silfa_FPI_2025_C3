#include <stdio.h>
#include <stdlib.h>

int longitud(char cad);  /* PROTOTIPO DE FUNCION. */

void main(void)
{
    int i, n, l = -1, p, t;
    char cad[50], FRA[20][50];
    printf("\nIngrese el numero de filas del arrelo: ");
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        printf("Ingrese la linea %d de texto: Maximo 50 caracteres: ", i+1);
        fflush(stdin);
        gets(FRA[i]); /* SE LEE LA CADENA DE CARACTERES DENTRO DEL CICLO. */
    }
    printf("\n");
    for (i=0; i<n; i++)
    {
        strcpy(cad, FRA[I]);
        t = longitud(cad);
        if (t > 1)
        {
            l = t;
            p = i;
        }
    }
    printf("\nLa cadena con mayor longitud es: ");
    puts(FRA[p]);
    printf("\nLongitud: %d", l);
}

int longitud(char *cadena)
/* ESTA FUNCION CALCULA LA LONITUD DE LA CADENA. ES INDETICA A LA FUNCION
CUENTA DEL PRORAMA 7.13. */
{
    int cue = 0;
    while (! cadena[cue] == '\0')
        cue++;
    return (cue);
}
