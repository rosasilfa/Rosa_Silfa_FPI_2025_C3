#include <stdio.h>
#include <string.h>

/* ESTRUCTURAS-1.
EL PROGRAMA MUESTRA LA MANERA EN QUE SE DECLARA UNA ESTRUCTURA, ASI COMO LA
FORMA EN QUE SE TIENE ACCESO A LOS CAMPOS DE LAS VARIABLES DE TIPO ESTRUCTURA
TANTO PARA ASIGNACION DE VALORES COMO PARA LECTURAS Y ESCRITURA. */

struct alummno /*DECLACION DE LA ESTRUCTURA. */
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char direccion[20];
}; /* OBSERVA QUE LA DECLARACION DE UNA ESTRUCTURA TERMINA CON Y COMA. */

void main(void)
{
    /* OBSERVA QUE LAS VARIABLES DE TIPO ESTRUCTURA SE DECLARAN COMO CUALQUIER OTRA
    VARIABLE. A1, A2 Y A3 SON VARIABLES DE TIPO ESTRUCTURA ALUMNO. */
    /* LOS CAMPOS DE A1 RECIBEN VALORES DIRECTAMENTE. */

    char nom[20], car[20], dir[20];
    int mat;
    float pro;

    /* LOS CAMPOS DE A2 RECIBEN VALORES POR MEDIO DE UNA LECTURA. */
    printf("\nIngrese la matricula del alumno 2: ");
    scanf("%d", &a2.matricula);
    fflush(stdin);
    printf("Ingrese el nombre del alumno 2: ");
    gets(a2.nombre);
    printf("Ingrese la carrera del alumno 2: ");
    scanf("%f", &a2.carrera);
    printf("Ingrese el promedio del alumno 2: ");
    scanf("%f", &a2.promedio);
    fflush(stdin);
    printf("Ingrese la direccion del alumno 2: ");
    gets(a2.direccion);

    /*LOS CAMPOS DE A3 RECIBEN VALORES POR MEDIO DE ASIGNACIONES. */
    printf("\nIngrese la matricula del alumno 3: ");
    scanf("%d", &mat);
    a3.matricula = mata;
    fflush(stdin);
    printf("Ingrese el nombre del alumno 3: ");
    gets(nom);
    strcpy(a3.nombre, nom);
    printf("Ingrese la carrera del alumno 3: ");
    gets(car);
    strcpy(a3.carrera, car);
    printf("Ingrese el promedio del alumno 3: ");
    scanf("%f", &pro);
    a3.promedio = pro;
    fflush(stdin);
    printf("Ingrese la direccion del alumno 3: ");
    gets(dir);
    strcpy(a3.direccion, dir);

    /* OBSERVE LA FORMA EN QUE SE IMPRIMEN LOS CAMPOS DE A1 Y A2. */
    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2lf\n"m a1.promedio);
    puts(a1.direccion);

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    putc(a2.nombre;
    puts(a2.carrera);
    printf("%.2lf\n"m a2.promedio);
    puts(a2.direccion);

    /* OBSERVA OTRA FORMA DE ESCRIBIR LOS CAMPOS DE LA VARIABLE DE TIPO ESTRUCTURA
    A3. */
    printf("\nDatos del alumno 3\n");
    printf("%d \t %s \t %s \t %.2lf \t %s", a3.matricula, a3.nombre, a3.carrera, a3.promedio, a3.direccion);
}
