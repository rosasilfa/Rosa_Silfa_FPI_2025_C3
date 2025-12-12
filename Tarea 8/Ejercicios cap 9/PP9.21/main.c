#include <stdio.h>

//Examen de admision.
//El programa, al recibir como dato un arcivo de acceso directo que contiene
//informacion sobre los alumnos que presentaron el examen de admision a una
//universidad, enera informacion importante para el Departamento de Control
//Escolar

typedef struct //Declaracion de la estructura alumno
{
    int Clave;
    char Nombre[20];
    int Carrera;
    float Promedio;
    float Examen;
    char Telefono[12];
} Alumno;

float F1(FILE *);
void F2(FILE *, FILE *, FILE *, FILE *, FILE *, FILE *);
void F3(FILE *, FILE *, FILE *, FILE *, FILE *);  //Prototipo de funciones

void main(void)
{
    float pro;
    FILE *ap, *c1, *c2, *c3, *c4, *c5;
    ap = fopen("alu1.dat", "r");
    //Observa que los arcivos car1.dat, car2.dat, car3.dat, car4.dat, car5.dat se
    //abren en la modalidad para escribir y leer.
    c1 = fopen("car1.dat", "w+");
    c2 = fopen("car2.dat", "w+");
    c3 = fopen("car3.dat", "w+");
    c4 = fopen("car4.dat", "w+");
    c5 = fopen("car5.dat", "w+");
    if ((ap!=NULL) && (c1!=NULL) && (c2!=NULL) && (c3!=NULL) &&
        (c4!=NULL) && (c5!=NULL))
    {
        pro = F1(ap);
        printf("\nPromedio examen de admision: %.2f", pro);
        F2(ap, c1, c2, c3, c4, c5);
        F3(c1, c2, c3, c4, c5);
    }
    else
        printf("\nEl o los archivos no se pudieron abrir");
    fclose(ap);
    fclose(c1);
    fclose(c2);
    fclose(c3);
    fclose(c4);
    fclose(c5);
}

float F1(FILE *ap)

