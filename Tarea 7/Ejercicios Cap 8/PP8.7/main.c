#include <stdio.h>
#include <string.h>

/*ESCUELA.
EL PROGRAMA GENERA INFORMACION IMPORTANTE DE LOS ALUMNOS DE UNA ESCUELA. */

typedef struct   /*DECLARACION DE LA ESTRUCTURA MATPRO. */
{
    char mat[20];  /*MATERIA*/
    int pro;       //PROMEDIO.
} matpro;

typedef struct  //DECLARACION DE LAS ESTRUCTURA ALUMNO.
{
    int matri;  //MATRICULA.
    char nom[20]; //NOMBRE DEL ALUMNO.
    matpro cal[5]; //OBSERVA QUE CAL ES UN ARREGLO UNIDIMENSIONAL DE TIPO
                   //ESTRUCTURA MATPRO -LA ESTRUCTURA DEFINIDA EN PRIMER TERMINO.
} alumno;

void Lectura(alumno *, int);
void F1(alumno *, int);
void F2(alumno *, int);
void F3(alumno *, int);   //PROTOTIPO DE FUNCIONES.

void main(void)
{
    alumno ALU[50]; //ALU ES UN ARREGLO UNIDIMENSIONAL DE TIPO ALUMNO.
    int TAM;
    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > 50 || TAM < 1); //SE VERIFICA QUE EL TAMAÑO EL ARREGLO SEA CORRECTO
    Lectura(ALU, TAM);
    F1(ALU, TAM);
    F2(ALU, TAM);
    F3(ALU, TAM);
}

void Lectura(alumno A[], int T)
//ESTA FUNCION SE UTILIZA PARA LEER LA INFORMACION DE UN ARREGLO UNIDIMENSIONAL
//DE TIPO ESTRUCTURA ALUMNO DE T ELEMENTOS.
{
    int I, J;
    for(I=0; I<T; I++)
    {
        printf("\nIngrese los datos del alumno %d", I+1);
        printf("\nIngrese la matricula del alumno: ");
        scanf("%d", &A[I].matri);
        fflush(stdin);
        printf("Ingrese el nombre del alumno: ");
        gets(A[I].nom);
        for(J=0; J<5; J++)
        {
            printf("\tMateria %d: ", J+1);
            fflush(stdin);
            gets(A[I].cal[J].mat);
            printf("\tPromedio %d: ", J+1);
            scanf("%d", &A[I].cal[J].pro);
        }
    }
}

void F1(alumno A[], int T)
//ESTA FUNCION SE UTILIZA PARA OBTENER LA MATRICULA Y EL PROMEDIO GENERAL DE
// CADA ALUMNO.
{
    int I, J;
    float SUM;
    for(I=0; I<T; I++)
    {
        printf("\nMatricula del alumno: %d", A[I].matri);
        SUM = 0.0;
        for (J=0; J<5; J++)
            SUM = SUM + A[I].cal[J].pro;
        SUM = SUM / 5;
        printf("\tPromedio: %.2f", SUM);
    }
}

void F2(alumno A[], int T)
//ESTA FUNCION SE UTILIZA PARA OBTENER LAS MATRICULAS DE LOS ALUMNOS CUYA
//CALIFICACION EN LA TERCERA MATERIA ES MAYOR A 9.
{
    int I;
    printf("\nAlumnos con calificaciones mayor a 9 en la tercera materia");
    for (I=0; I<T; I++)
        if(A[I].cal[2].pro > 9)
        printf("\nMatricula del alumno: %d", A[I].matri);
}

void F3(alumno A[], int T)
//ESTA FUNCION SE UTILIZA PARA OBTENER EL PROMEDIO GENERAL DE LA CUARTA MATERIA.
{
    int I;
    float SUM = 0.0;
    for (I=0; I<T; I++)
        SUM = SUM + A[I].cal[3].pro;
    SUM = SUM / T;
    printf("\n\nPromedio de la cuarta materia: %.2f", SUM);
}
