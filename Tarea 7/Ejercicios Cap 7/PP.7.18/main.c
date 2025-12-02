#include <stdio.h>

/* CADENA INVERTIDA RESUELTA EN FORMA RECURSIVA. */

void inverso(char *);  /* PROTOTIPO DE FUNCION. */

void main(void)
{
    char fra[50];
    printf("\nIngrese la linea de texto: ");
    gets(fra);
    printf("\nEscribe la linea de texto en forma inversa: ");
    inverso(fra);
}

void inverso(char *cadena)
/* LA FUNCION INVERSO OBTIENE PRECISAMENTE EL INVERSO DE LA CADENA. LA SOLUCION
PRESENTADA ES SIMPLE, PERO PARA COMPRENDERLA ES NECESARIO TENER CONOCIMIENTOS
TANTO DE PILAS COMO DE RECURSIVIDAD. OBSERVA QUE MIENTRAS NO SE ENCUENTRE EL
CARACTER DE TERMINACION DE LA CADENA, SE LLAMA A LA FUNCION RECURSIVA CON
EL APUNTADOR AL SIUIENTE CARACTER DE LA CADENA. POR OTRA PARTE, QUEDA
PENDIENTE DE EJERCUTAR - ALMACENADO EN UNA PILA- EL CARACTER AL CUAL APUNTA
*CADENA. */
{
    if (cadena[0]!= '\0')
    {
        inverso(&cadena[1]);
        putchar(cadena[0]);
    }
}
