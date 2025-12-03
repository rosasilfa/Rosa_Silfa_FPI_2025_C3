#include <stdio.h>
#include <string.h>

/* HOSPITAL.
EL PROGRAMA GENERA INFORMACION ACERCA DE LOS PACIENTES DE UN HOSPITAL. */

typedef struct  /*DECLARACION DE LA ESTRUCTURA DOMICILIO. */
{
    char cal[20];    /*CALLE. */
    int num;         /*NUMERO. */
    char col[20];    /*COLONIA. */
    char cp[5];      /*CODIGO POSTAL. */
    char ciu[20];    /*CIUDAD. */
} domicilio;

typedef struct /*DECLARACION DE LA ESTRUCTURA PACIENTE. */
{
    char nom[20]; /*NOMBRE Y APELLIDO. */
    int edad;
    char sexo;
    int con;      /*CONDICION. */
    domicilio dom; /*OBSERVA QUE EL CAMPO DOM ES DE TIPO ESTRUCTURA
                   DOMICILIO. */
    char tel[10];  /*TELEFONO:*/
} paciente;

void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);   /*PROTOTIPO DE FUNCIONES. */
void F3(paciente *, int);

void main(void)
{
    paciente HOSPITAL[100]; /*ARREGLO UNIDIMENSIONAL DE TIPO ESTRUCTURA
    PACIENTE. */
    int TAM;
    do
    {
        printf("Ingrese el numero de pacientes: ");
        scanf("%d", &TAM);
    }
    while (TAM > 50 || TAM < 1); /*SE VERIFICA QUE EL TAMAÑO DEL ARREGLO SEA
                                 CORRECTO. */
    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOPISTAL, TAM);
}

void Lectura(paciente A[], int T)
/*ESTA FUNCION SE UTILIZA PARA LEER UN ARREGLO UNIDIMENSIONAL DE TIPO
ESTRUCTURA PACIENTE DE T ELEMENTOS. */
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("\n\t\tPaciente %d", I+1);
        fflush(stdin);
        printf("\nNombre: ");
        gets(A[I].nom);
        printf("Edad: ");
        scanf("%d", &A[I].edad);
        printf("Sexo (F-M): ");
        scanf("%c", &A[I].sexo);
        printf("Condicion (1..5): ");
        scanf("%d", &A[I].con);
        fflush(stdin);
        printf("\tCalle: ");
        gets(A[I].dom.cal);
        printf("\tNumero: ");
        scanf("%d", &A[I].dom.num);
        fflush(stdin);
        printf("\tColonia: ");
        gets(A[I].dom.col);
        fflush(stdin);
        printf("\tCodigo Postal: ");
        gets(A[I].dom.cp);
        fflush(stdin);
        printf("\tCiudad: ");
        gets(A[I].dom.ciu);
        fflush(stdin);
        printf("Telefono: ");
        gets(A[I].tel);
    }
}

void F1(paciente A[], int T)
/*ESTA FUNCION SE UTILIZA PARA OBTENER EL PORCENTAJE TANTO DE HOMBRES COMO DE
MUJERES REGISTRADOS EN EL HOSPITAL. */
{
    int I, FEM, MAS, TOT;
    for (I=0; I<T; I++)
        switch (A[I].sexo)
    {
        case 'F': FEM++;
        break;
        case 'M': MAS++;
        break;
    }
    TOT = FEM + MAS;
    printf("\nPorcentaje de Hombres: %.2f%", (float)MAS / TOT * 100);
    printf("\nPorcentaje de Mujeres: %2.f%", (float)FEM / TOT * 100);
}

void F2(paciente A[], int T)
/*ESTA FUNCION SE UTILIZA PARA OBTENER EL NUMERO DE PACIENTES QUE INGRESARON AL
HOSPITAL EN CADA UNA DE LAS CATEGORIAS DE CONDICION. */
{
    int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0; C5 = 0;
    for (I=0; I<T; I++)
        switch (A[I].con)
    {
        case 1: C1++;
        break;
        case 2: C2++;
        break;
        case 3: C3++;
        break;
        case 4: C4++;
        break;
        case 5: C5++;
        break;
    }
    printf("\nNumero pacientes en condicion 1: %d", C1);
    printf("\nNumero pacientes en condicion 2: %d", C2);
    printf("\nNumeros pacientes en condicion 3: %d", C3);
    printf("\nNumero de pacientes en condicion 4: %d", C4);
    printf("\nNumero de pacientes en condicion 5: %d", C5);
}

void F3(paciente A[], int T)
/*LA FUNCION F3 SE UTILIZA PARA GENERAR EL NOMBRE Y TELEFONO DE TODOS LOS
PACIENTES QUE TUVIERON UNA CONDICION DE INRESO DE MAXIMA GRAVEDAD (5). */
{
    int I;
    printf("\nPacientes ingresados en estados de gravedad");
    for(I=0; I<T; I++)
        if(A[I].con == 5)
    {
        printf("\nNombre: %s\tTelefono: %s", A[I].nom, A[I].tel);
    }
}
