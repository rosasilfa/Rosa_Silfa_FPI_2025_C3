#include <stdio.h>

/* CUENTA CARACTERES.
EL PROGRAMA, AL RECIBIR COMO DATOS UNA CADENA DE CARACTERES Y UN CARACTER,
CUENTA CUANTAS VECES SE ENCUENTRA EL CARACTER EN LA CADENA. */

int cuenta(char *, char);      /* PROTOTIPO DE FUNCION. */

void main(void)
{
    char car, cad[50];
    int res;
    printf("\nIngrese la cadena de caracteres: ");
    gets(cad);
    fflush(stdin);
    printf("\nIngrese el caracter: ");
    car = getchar();
    res = cuenta(cad, car);
    printf("\n\n%c se encuentra %d veces en la cadena %s", car, res, cad);
}

int cuenta(char *cad, char car)
/* ESTA FUNCION SE UTILIZA PARA OBTENER EL NUMERO DE VECES QUE SE ENCUENTRA
EL CARACTER EN LA CADENA. */
{
    int i = 0, r = 0;
    while (cad[i] != '\0')
    {
        if (cad[i] == car)
            r++;
        i++;
    }
    return (r);
}
