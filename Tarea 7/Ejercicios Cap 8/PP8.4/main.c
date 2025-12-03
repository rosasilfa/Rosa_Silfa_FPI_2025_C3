#include <stdio.h>
#include <string.h>

//ESCULA
//EL PROGRAMA GENERA INFORMACION ESTADISTICA DE LOS ALUMNOS DE UNA ESCUELA.

typedef struct //DECLARACION DE LA ESTRUCTURA ALUMNO UTILIZANDO UN TYPEDEF.
{
    int matricula;
    char nombre[30];
    float cal[5];
    //OBSERVA QUE EL CAMPO DE LA ESTRUCTURA ALUMNO ES UN ARREGLO UNIDIMENSIONAL
} alumno;

void Lectura(alumno, int T);
void F1(alumno *, int TAM); //PROTOTIPOS DE FUNCIONES
void F2(alumno *, int TAM);
void F3(alumno *, int TAM);

void main(void)
{
    alumno ARRE[50]; //SE DECLARA UN ARREGLO UNIDIMENSIONAL DE TIPO ALUMNO
    int TAM;
    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > 50 || TAM < 1); //SE VERIFICA QUE EL TAMAÑO DEL ARREGLO SEA CORRECTO
    Lectura(ARRE, TAM);
    F1(ARRE, TAM);
    F2(ARRE, TAM);
    F3(ARRE, TAM);
}

void Lectura(alumno A[], int T)
//LA FUNCION LECTURA SE UTILIZA PARA LEER UN ARREGLO UNIDIMENSIONAL DE TIPO
//ESTRUCTURA ALUMNO DE T ELEMENTOS
{
    int I, J;
    for (I=0; I<T; I++)
    {
        printf("\nIngrese los datos del alumno %d", I+1);
        printf("\nIngrese la matricula del alumno: ");
        scanf("%d", &A[I].matricula);
        fflush(stdin);
        printf("Ingrese el nombre del alumno: ");
        gets(A[I].nombre);
        for (J=0; J<5; J++)
        {
            printf("\tIngrese la calificacion %d del alumno %d: ", J+1, I+1);
            scanf("%f", A[I].cal[J]);
        }
    }
}

void F1(alumno A[], int T)
//LA FUNCION F1 OBTIENE LA MATRICULA Y EL PROMEDIO DE CADA ALUMNO.
{
    int I, J;
    float SUM, PRO;
    for (I=0; I<T; I++)
    {
        printf("\nMatricula del alumno: %d", A[I].matricula);
        SUM = 0.0;
        for (J=0; J<5; J++)
            SUM = SUM + A[I].cal[J];
        PRO = SUM / 5;
        printf("\t\tPromedio: %.2f", PRO);
    }
}

void F2(alumno A[], int T)
//LA FUNCION F2 OBTIENE LAS MATRICULAS DE LOS ALUMNOS CUYA CALIFICACION EN LA
//TERCERA MATERIA ES MAYOR A 9
{
    int I;
    printf("\nAlumnos con calificacion en la tercera materia > 9");
    for (I=0; I<T; I++)
        if (A[I].cal[2] > 9)
        printf("\nMatricula del alumno: %d", A[I].matricula);
}

void F3(alumno A[], int T)
//ESTA FUNCION OBTIENE EL PROMEDIO GENERAL DEL GRUPO DE LA MATERIA 4.
{
    int I;
    float PRO, SUM = 0.0;
    for (I=0; I<T; I++)
        SUM = SUM + A[I].cal[3];
    PRO = SUM / T;
    printf("\n\nPromedio de la materia 4: %.2f", PRO);
}
