#include <stdio.h>

/* Declaración de cadenas de caracteres y asinacion de valores. */

void main(void)
{
    char *cad0;
    cad0 = "Argentina";       /* La declaración y la asinacion son correctas. */
    puts(cad0);

    cad0 = "Brasil";
    /* Correcto. Se modifica el contenido de la posicion en memoria a la que apunta
    la variable cad0 -apuntador de tipo cadena de caracteres. */
    puts(cad0);


    char *cad1 = "";
    gets(cad1);
    /* Correcto. Primero se le asina un valor a la posicion de memoria a la que
    apunta cad1. Lueo podemos modificar el contenido de esta posicion de memoria
    utilizando la funcion gets. */



    char cad2[20] = "Mexico";  /* Correcto. */
    puts(cad2);
    gets(cad2);
    /* El valor de una cadena (declarada como cadena[longitud]) se puede modificar
    por medio de lecturas o utilizando funciones de la biblioteca string.h
    (ejemplo 7.6). */


}
