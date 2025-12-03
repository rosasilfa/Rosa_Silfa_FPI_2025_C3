#include <stdio.h>
#include <string.h>

/* BIENES RAICES.
EL PROGRAMA MANEJA INFORMACION SOBRE LAS PROPIEDADES QUE TIENE UNA EMPRESA
DE BIENES RAICES DE LA CIUDAD DE LIMA, PERU, TANTO PARA VENTA COMO PARA
RENTA. */

typedef struct /*DECLARACION DE LA ESCTRUCTURA UBICACION. */
{
    char zona[20];
    char calle[20];
    char colonia[20];  /*COLONIA. */
} ubicacion;

typedef struct  /*DECLARACION DE LA ESTRUCTURA PROPIEDADES. */
{
    char clave[5];
    float scu;  /*SUPERFICIE CUBIERTA. */
    float ste;  /*SUPERFICIE TERRENO. */
    char car[50]; /*CARACTERISTICAS. */
    ubicacion ubi; /*OBSERVA QUE ESTE CAMPO ES DE TIPO ESTRUCTURA
                   UBICACION. */
    float precio;
    char dispo;   /*DISPONIBILIDAD. */
} propiedades;

void Lectura(propiedades, int);
void F1(propiedades *, int);  /*PROTOTIPOS DE FUNCIONES.*/
void F2(propiedades *, int);

void main(void)
{
    propiedades PROPIE[100];
    /*SE DECLARA UN ARRELO UNIDIMENSIONAL DE TIPO ESTRUCTURA PROPIEDADES. */
    int TAM;
    do
    {
        printf("Ingrese el numero de propiedades: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);
    /* Se verifica que el tamaño del arreglo sea correcto. */
    Lectura(PROPIE, TAM);
    F1(PROPIE, TAM);
    F2(PROPIE, TAM);
}

void Lectura(propiedades A[], int T)
/*ESTA FUNCION SE UTILIZA PARA LEER UN ARREGLO UNIDIMENSIONAL DE TIPO ESTRUCTURA
PROPIEDADES DE T ELEMENTOS. */
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("\n\tIngrese datos de la propiedad %d", I + 1);
        printf("\nClave: ");
        fflush(stdin);
        gets(A[I].clave);
        printf("Superficie cubierta: ");
        scanf("%f", &A[I].scu);
        printf("Superficie terreno: ");
        scanf("%f", &A[I].ste);
        printf("Caracteristicas: ");
        fflush(stdin);
        gets(A[I].car);
        printf("\tZona: ");
        fflush(stdin);
        gets(A[I].ubi.zona);
        printf("\tCalle: ");
        fflush(stdin);
        gets(A[i].ubi.calle);
        printf("\tColonia: ");
        fflush(stdin);
        gets(A[I].ubi.colo);
        printf("Precio: ");
        scanf("%f", &A[I].precio);
        printf("Disponibilidad (Venta-V Renta-R): ");
        scanf("%c", &A[I].dispo);
    }
}

void F1(propiedades A[], int T)
/*ESTA FUNCION SE UTILIZA PARA GENERAR UN LISTADO DE LAS PROPIEDADES
DISPONIBLES PARA VENTA EN LA ZONA DE MIRAFLORES, CUYO VALOR OSCILA ENTRE
450,000 Y 650,000 NUEVOS SOLES. */
{
    int I;
    printf("\n\t\tListado de Propiedades para Venta en Miraflores");
    for (I=0; I<T; I++)
        if((A[I].dispo == 'V') && (strcmp(A[I].ubi.zona, "Miraflores") == 0))
        if((A[I].precio >= 450000) && (A[I].precio <= 650000))
    {
        printf("\nClave de la propiedad: ");
        puts(A[I].clave);
        printf("\nSuperficie cubierta: %f", A[I].scu);
        printf("\nSuperficie terreno: %f", A[I].ste);
        printf("\nCaracterísticas: ");
        puts(A[I].car);
        printf("Calle: ");
        puts(A[I].ubi.calle);
        printf("Colonia: ");
        puts(A[I].ubi.colo);
        printf("Precio: %.2f\n", A[I].precio);
    }
}

void F2(propiedades A[], int T)
/*AL RECIBIR COMO DATOS UNA ZONA GEOGRAFICA DE LIMA, PERU, Y UN CIERTO RANO
RESPECTO AL MONTO, ESTA FUNCION GENERA UN LISTADO DE TODAS LAS PROPIEDADES
DISPONIBLES PARA RENTA. */
{
    int I;
    float li, ls;
    char zon[20];
    printf("\n\t\tListado de Propiedades para Renta");
    printf("\nIngrese la zona geografica: ");
    fflush(stdin);
    gets(zon);
    printf("Ingrese el limite inferior del precio: ");
    scanf("%f", &li);
    printf("Ingrese el limite superior del precio: ");
    scanf("%f", &ls);
    for (I=0; I<T; I++)
        if ((A[I].dispo == 'R') && (strcmp(A[I].ubi.zona, zon) == 0))
        if ((A[I].precio >= li) && (A[I].precio <= ls))
    {
        printf("\nClave de la propiedad: ");
        puts(A[I].clave);
        printf("\nSuperficie cubierta: %d", A[I].scu);
        printf("\nSuperficie terreno: %d", A[I].ste);
        printf("\nCaracteristicas: ");
        puts(A[I].car);
        printf("Calle: ");
        puts(A[I].ubi.calle);
        printf("Colonia: ");
        puts(A[I].ubi.colo);
        printf("Precio: %.2f", A[I].precio);
    }
}
