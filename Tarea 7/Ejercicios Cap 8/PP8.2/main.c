#include <string.h>

//ESTRUCTURAS-2.
//EL PROGRAMA MUESTRA LA MANERA EN QUE SE DECLARA UNA ESTRUCTURA, ASI COMO LA
//FORMA EN QUE SE TIENE ACCESO A LOS CAMPOS DE LOS APUNTADORES DE TIPO ESTRUCTURA
//TANTO PARA LA LECTURA COMO PARA ESCRITURA. SE UTILIZA ADEMAS UNA FUNCION QUE
//RECIBE COMO PARAMETRO UN APUNTADOR DE TIPO ESTRUCTURA.
struct alumno //DECLARACION DE LA ESTRUCTURA
{
    int matricula;
    char nombre[20];
    char carrera[20];  //CAMPOS DE LA ESTRUCTURA ALUMNO
    float promedio;
    char direccion[20];
};

void Lectura(struct alumno *); //PROTOTIPO DE FUNCION

void main(void)
{
    struct alumno a0 = {120, "Maria", "Contabilidad", 8.9, "Queretaro"};
    struct alumno *a3, *a4, *a5, a6;
    //OBSERVA QUE LAS VARIABLES *A3, *A4 Y *A5 SE DECLARAN COMO APUNTADORES DE
    //TIPO ESTRUCTURA ALUMNO. A6 ES UNA VARIABLE DE TIPO ESTRUCTURA ALUMNO.

    a3 = &a0; //EN ESTE CASO AL APUNTADOR DE TIPO ESTRUCTURA ALUMNO A3
    //SE LE ASIGNA LA DIRECCION DE LA VARIABLE DE TIPO ESTRUCTURA ALUMNO, A0.

    a4 = new (struct alumno);
    //NOTA QUE AL APUNTADOR A4 ES NECESARIO ASIGNARLE UNA DIRECCION DE MEMORIA.
    //PARA TENER ACCESO A LOS CAMPOS DE UN APUNTADOR DE TIPO ESTRUCTURA, UTILIZA UNO
    //DE LOS DOS FORMATOS SIGUIENTES:
    //apuntador->campo
    //o bien
    //(*apuntador).campo
    //EN LA LECTURA DE LOS CAMPOS DE LA VARIABLE A4 SE UTILIZAN COMO EJEMPLO AMBOS
    //FORMATOS.
    printf("\nIngrese la matricula del alumno 4: ");
    scanf("%d", &(*a4).matricula);
    fflush(stdin);
    printf("Ingrese el nombre del alumno 4: ");
    gets(a4->nombre);
    printf("Ingrese la carrera del alumno 4: ");
    gets((*a4).carrera);
    printf("Ingrese promedio del alumno 4: ");
    scanf("%f", &a4->promedio);
    fflush(stdin);
    printf("Ingrese la direccion del alumno 4: ");
    gets(a4->direccion);

    a5 = new (struct alumno);
    Lectura(a5); //EN ESTE CASO SE PASA EL APUNTADOR DE TIPO ESTRUCTURA ALUMNO
    //A5 A LA FUNCION LECTURA.

    Lectura(&a6); //EN ESTE CASO SE PASA LA VARIABLE DE TIPO ESTRUCTURA ALUMNO A6,
    //A LA FUNCION LECTURA. OBSERVA QUE EN ESTE CASO DEBEMOS UTILIZAR EL OPERADOR DE
    //DIRECCION PARA PRECER A LA VARIABLE.
    printf("\nDatos del alumno 3\n");
    //OBSERVA LA FORMA DE ESCRIBIR LOS CAMPOS DE LOS APUNTADORES DE TIPO
    //ESTRUCTURA.
    printf("%d\t%s\t%s\t%.2f\t%s", a3->matricula, a3->nombre, a3->carrera,
           a3->promedio, a3->direccion);

           printf("\nDatos del alumno 4\n");
           printf("%d\t%s\t%s\t%.2f\t%s", a4->matricula, a4->nombre, a4->carrera,
                  a4->promedio, a4->direccion);

                  printf("\nDatos del alumno 5\n");
                  printf("%d\t%s\t%s\t%f\t%s", a5->matricula, a5->nombre, a5->carrera,
                         a5->promedio, a5->direccion);
        printf("\nDatos del alumno 6\n");
        //OBSERVA LA FORMA DE ESCRIBIR LOS CAMPOS DE LA VARIABLE TIPO ESTRUCTURA.
        printf("%d\t%s\t%s\t%.2f\t%s", a6.matricula, a6.nombre, a6.carrera,
               a6.promedio, a6.direccion);
}

void Lectura(struct alumno *a)
//ESTA FUNCION PERMITE LEER LOS CAMPOS DE UN PAUNTADOR DE TIPO ESTRUCTURA
//ALUMNO.
{
    printf("\nIngrese la matricula del alumno: ");
    scanf("%d", &(*a).matricula);
    fflush(stdin);
    printf("Ingrese el nombre del alumno: ");
    gets(a->nombre);
    fflush(stdin);
    printf("Ingrese la carrera del alumno: ");
    gets((*a).carrera);
    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &a->promedio);
    fflush(stdin);
    printf("Ingrese la direccion del alumno: ");
    gets(a->direccion);
}

