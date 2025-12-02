#include <stdio.h>
#include <stdlib.h>

/* FUNCIONES DE LA BIBLIOTECA string.H PARA EL MANEJO DE CADENAS DE
CARACTERES. */

void main(void)
{
    char *cad0 = "Hola Mexico";
    char cad1[20], cad2[20], cad3[20] = ", buenos dias!!!";

    strcpy(cad1, cad0);
    /* LA FUNCION STRCPY PERMITE COPIAR UNA CADENA DE CARACTERES COMPLETA. EN ESTE
    CASO SE COPIA LA CADENA CAD0 A CAD1. SI EL ESPACIO RESERVADO PARA CAD1 ES
    MENOR QUE EL DE CAD0, SE GENERA UN ERROR EN LA EJECUCION DEL PROGRAMA. */
    printf("\nPrueba de la funcion strcpy. Se copia la cadena cad0 a cad1: %s\n", cad1);

    strcpy(cad1, cad3);
    printf("\nPrueba de la funcion strcpy. Se copia la cadena cad3 a cad1: %s\n", cad1);

    strcpy(cad1, "XX");
    printf("\nPrueba de la funcion strcpy. Se copia la cadena XX a cad1: %s\n", cad1);

    strcpy(cad2, cad0, 4);
    cad2[4] = '\0';
    /* LA FUNCION STRNCPY PERMITE COPIAR UN NUMERO DETERMINADO DE CARACTERES A
    OTRA CADENA DE CARACTERES. EN ESTE CASO SE COPIAN 4 CARACTERES DE LA CADENA
    CAD0 -SEUNDO ARGUMENTO- A CAD2 - PRIMER ARGUMENTO. SIEMPRE SE DEBE
    INCORPORAR AL FINAL DE LA CADENA EL CARACTER DE TERMINACION. SI EL ESPACIO
    RESERVADO PARA CAD2 ES MENOR QUE LO QUE SE PRETENDE COPIAR, SE ENERA
    UN ERROR EN LA EJECUCION DEL PROGRAMA. */
    printf("\nPrueba de la funcion strncpy. Se copian 4 caracteres de cad0 a cad2: %\n", cad2);
    strncpy(cad2, cad3, 3);
    cad2[3] = '\0';
    printf("\nPrueba de la funcion strncpy. Se copian 3 caracteres de cad3 a cad2: %s\n", cad2);
    strcat(cad0, cad3);
    /*LA FUNCION STRCAT PERMITE INCORPORAR UNA CADENA DE CARACTERES A OTRA
    CADENA DADA. EN ESTE CASO SE AGREGA LA CADENA CAD2 A CAD0. SI EL ESPACIO
    RESERVADO PARA CAD0 ES MENOR A LO QUE SE DEBE ALMACENAR SE GENERA UN ERROR
    DE EJECUCION. */
    printf("\nPrueba de la funcion strcat. Se incorpora la cadena cad3 a cad0: %s\n", cad0);

    strcat(cad1, "YY");
    printf("\nPrueba de la funcion strcat. Se incorpora la cadena YY a cad1: %s\n", cad1);

    strcat(cad2, " ");
    strncat(cad2, cad0, 4);
    printf("\nPrueba de la funcion strncat. Se incorporan 4 caracteres de cad0 a cad2: %s\n", cad2);
    /*LA FUNCION STRNCAT PERMITE INCORPORAR UN NUMERO DETERMINADO DE CARACTERES
    A UNA CADENA. EN ESTE CASO SE AGREGAN CUATRO CARACTERES DE LA CADENA CAD0
    A CAD2. SI EL ESPACIO DE CAD2 ES MENOR A LO QUE SE DEBE ALMACENAR OCURRE
    UN ERROR DE EJECUCION. */

    cad0 = strstr(cad0, "Mexico");
    printf("\nPrueba de la funcion strstr. Se trata de localizar la cadena Mexico dentro de cad0: %s\n", cad0);
    /*LA FUNCION STRSTR SE UTILIZA PARA LOCALIZAR UNA CADENA DE CARACTERES DENTRO
    DE OTRA CADENA. SI LA ENCUENTRA, RERESA UN APUNTADOR AL INICIO DE LA
    PRIMERA OCURRENCIA DE LA CADENA LOCALIZADA. DE OTRA FORMA, REGRESA NULL. */

    cad0 = strstr(cad0, "Guatemala");
    printf("\nPrueba de la funcion strstr. Se trata de localizar la cadena de Guatemala dentro de cad0: %s\n", cad0);
}
