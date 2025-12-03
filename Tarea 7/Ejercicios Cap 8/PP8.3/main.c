#include <stdio.h>
#include <string.h>

//ESTRUCTURAS-3.
//EL PROGRAMA MUESTRA LA MANERA EN QUE SE DECLARA UNA ESTRUCTURA ANIDADA, ASI
// COMO LA FORMA DE ACCESO A LOS CAMPOS DE LAS VARIABLES O APUNTADORES DE TIPO
//ESTRUCTURA, TANTO PARA LECTURA COMO PARA ESCRITURA. SE UTILIZA ADEMAS UNA
//FUNCION QUE RECIBE COMO PARAMETRO UN APUNTADOR DE TIPO ESTRUCTURA.

typedef struct //DECLARACION DE LA ESTRUCTURA DOMICILIO UTILIZANDO UN TYPEDEF.
{
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
} domicilio;

struct empleado  //DECLARACION DE LA ESTRUCTURA ANIDADA EMPLEADO.
{
    char nombre[20];
    char departamento[20];
    float sueldo;
    domicilio direccion;  //DIRECCION ES UN CAMPO DE TIPO ESTRUCTURA
                          //DOMICILIO DE LA ESTRUCTURA EMPLEADO
};

void Lectura(struct empleado *a)
//FUNCION QUE PERMITE LEER LOS CAMPOS DE UN APUNTADOR DE TIPO ESTRUCTURA
//EMPLEADO.
{
    printf("\nIngrese el nombre del empleado: ");
    gets(a->nombre);
    fflush(stdin);
    printf("Ingrese el departamento de la empresa: ");
    gets(a->departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &a->sueldo);
    fflush(stdin);
    printf("--Ingrese la direccion del empleado-- -");
    printf("\n\tCalle: ");
    gets(a->direccion.calle);
    printf("\tNumero: ");
    scanf("%d", &a->direccion.numero);
    printf("\tCodigo Postal: ");
    scanf("%d", &a->direccion.cp);
    fflush(stdin);
    printf("\tLocalidad: ");
    gets(a->direccion.localidad);
}

void main(void)
{
    struct empleado e0 = {"Arturo", "Compras", 15500.75, "San Jeronimo", 120, 3490, "Toluca"};
    struct empleado *e1, *e2, e3, e4;
    //SE DECLARAN DIFERENTES VARIABLE Y APUNTADORES DE LA ESTRUCTURA EMPLEADO
    //PARA QUE EL LECTOR PUEDA APRECIAR TAMBIEN LAS DIFERENTES FORMAS EN QUE LOS
    //CAMPOS RECIBEN VALORES.
    //EN EL PROGRAMA PRINCIPAL SE LEEN LOS CAMPOS DE UNA VARIABLE, E3, Y UN
    //APUNTADOR DE TIPO ESTRUCTURA, *E1.
    e1 = new (struct empleado);
    printf("\nIngrese el nombre del empleado 1: ");
    scanf("%s", &(*e1).nombre);
    fflush(stdin);
    printf("Ingrese el departamento de la empresa: ");
    gets(e1->departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e1->sueldo);
    printf("-- -Ingrese la direccion del empleado-- -");
    printf("\n\tCalle: ");
    fflush(stdin);
    gets(e1->direccion, calle);
    printf("\tNumero: ");
    scanf("%d", &e1->direccion.numero);
    printf("\tCodigo Postal: ");
    scanf("%d", &e1->direccion.cp);
    printf("\tLocalidad: ");
    fflush(stdin);
    gets(e1->direccion.localidad);

    printf("\nIngrese el nombre del empleado 3: ");
    scanf("%s", &e3.nombre);
    fflush(stdin);
    printf("Ingrese el departamento de la empresa: ");
    gets(e3.departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e3.sueldo);
    printf("-- -Ingrese la direccion del empleado-- -");
    printf("\n\tCalle: ");
    fflush(stdin);
    gets(e3.direccion.calle);
    printf("\tNumero: ");
    scanf("%d", &e3.direccion.numero);
    printf("\tCodigo Postal: ");
    scanf("%d", &e3.direccion.cp);
    printf("\tLocalidad: ");
    fflush(stdin);
    gets(e3.direccion.localidad);
    //EN LA FUNCION LECTURA SE LEEN LOS CAMPOS DE UNA VARIABLE, E4, Y UN APUNTADOR DE TIPO ESTRUCTURA, *E2
    e2 = new (struct empleado);
    Lectura(e2);

    Lectura(&e4);

    printf("\nDatos del empleado 1\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s", e1->nombre, e1->departamento, e1>sueldo,
           e1->direccion.calle, e1->direccion.numero, e1->direccion.cp,
           e1->direccion.localidad);

           printf("\nDatos del empleado 4n");
           printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s", e4.nombre, e4.departamento, e4.sueldo,
                  e4.direccion.calle, e4.direccion.numero, e4.direccion.cp, e4.direccion.localidad);
}
