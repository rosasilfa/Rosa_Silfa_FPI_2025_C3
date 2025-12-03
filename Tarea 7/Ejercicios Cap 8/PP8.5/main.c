#include <stdio.h>
#include <string.h>

//UNIONES.
//EL PROGRAMA MUESTRA LA MANERA COMO SE DECLARA UNA UNION, ASI COMO LA FORMA DE
//ACCESO A LOS CAMPOS DE LAS VARIABLES DE TIPO UNION TANTO PARA ASIGNACION
//DE VALORES COMO PARA LECTURA Y ESCRITURA.

union datos //DECLARACION DE UNA union
{
 char celular[15];
 char correo[20];
};

typedef struct //DECLARACION DE UNA ESTRUCTURA UTILIZANDO TYPEDEF.
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    union datos personales;
    //OBSERVA QUE UNO DE LOS CAMPOS DE LA ESTRUCTURA ALUMNO ES UNA UNION.
} alumno;

void Lectura(alumno a); //PROTOTIPO DE FUNCION.

void main(void)
{
    alumno a1 = {120, "Maria", "Contabilidad", 8.9, "5-158-40-50"}, a2, a3;
    //OBSERVA QUE SOLO EL PRIMER COMPONENTE DE UNA UNION PUEDE RECIBIR VALORES POR
    //MEDIO DE ESTE TIPO DE ASIGNACIONES.

    //PARA QUE PUEDAS OBSERVAR LAS DIFERENTES FORMAS EN QUE LOS CAMPOS DE LAS
    //VARIABLES DE TIPO ESTRUCTURA ALUMNO RECIBEN VALORES, INGRESAMOS LOS VALORES
    //DE LOS CAMPOS DE TRES FORMAS DIFERENTES. LOS CAMPOS DE A1 RECIBEN VALORES
    //DIRECTAMENTE, LOS CAMPOS A2 SE LEEN EN EL PROGRAMA PRINCIPAL, Y LOS CAMPOS
    //DE A3 RECIBEN VALORES A TRAVES DE UNA FUNCION.
    printf("Alumno 2\n");
    printf("Ingrese la matricula: ");
    scanf("%d", &a2.matricula);
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a2.nombre);
    fflush(stdin);
    printf("Ingrese la carrera: ");
    gets(a2.carrera);
    printf("Ingrese el promedio: ");
    scanf("%f", &a2.promedio);
    fflush(stdin);
    printf("Ingrese el correo electronico: ");
    gets(a2.personales.correo);
    //OBSERVA QUE EN LA VARIABLE A2 DE TIPO ESTRUCTURA ALUMNO EL SEGUNDO CAMPO DE LA
    //UNION RECIBE UN VALOR.
    printf("Alumno 3\n");
    Lectura(&a3); //SE LLAMA A UNA FUNCION PARA LEER LOS CAMPOS DE LA VARIABLE A3.
    //IMPRESION DE RESULTADOS.
    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.personales.celular);
    //OBSERVA QUE ESCRIBE EL VALOR DEL TELEFONO CELULAR ASIGNADO.
    puts(a1.personales.correo);
    //OBSERVA QUE SI TRATAMOS DE IMPRIMIR EL CAMPO CORREO, ESCRIBE BASURA.

    strcpy(a0.personales.correo, "hgimenez@hotmail.com");
    //SE INGRESA AHORA UN VALOR AL SEGUNDO CAMPO DE LA UNION DE LA VARIABLE A0.
    puts(a0.personales.celular);
    //AHORA ESCRIBE BASURA EN EL CAMPO DEL TELEFONO CELULAR.
    puts(a0.personales.correo);
    //ESCRIBE EL CONTENIDO DEL CAMPO (HGIMENEZ@HOTMAIL.COM

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.personales.celular);  //ESCRIBE BASURA
    puts(a2.personales.correo); //ESCRIBE EL CONTENIDO DEL SEGUNDO CAMPO

    printf("Ingrese el telefono celular del alumno 2: ");
    fflush(stdin);
    gets(a2.personales.celular);

    puts(a2.personales.celular); //ESCRIBE EL TELEFONO CELULAR INGRESADO
    puts(a2.personales.correo);  //AHORA ESCRIBE BASURA.

    printf("\nDatos del alumno 3\n");
    printf("%d\n", a3.matricula);
    puts(a3.nombre);
    puts(a3.carrera);
    printf("%.2f\n", a3.promedio);
    puts(a3.personales.celular);
    puts(a3.personales.correo); //ESCRIBE BASURA
}

void Lectura(alumno *a)
//LA FUNCION Lectura() SE UTILIZA PARA LEER LOS CAMPOS DE UNA VARIABLE DE TIPO
//ESTRUCTURA ALUMNO.
{
    printf("\nIngrese la matricula: ");
    scanf("%d", &(*a).matricula);
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a->nombre);
    fflush(stdin);
    printf("Ingrese la carrera: ");
    gets((*a).carrera);
    printf("Ingrese el promedio: ");
    scanf("%f", &a->promedio);
    printf("Ingrese el telefono celular: ");
    fflush(stdin);
    gets(a->personales.celular);
}
