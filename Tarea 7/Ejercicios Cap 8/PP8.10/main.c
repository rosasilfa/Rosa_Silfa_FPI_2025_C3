#include <stdio.h>
#include <string.h>

/* VENDERORES.
EL PROGRAMA MANEJA INFORMACION SOBRE LAS VENTAS QUE REALIZAN LOS VENDEDORES DE
ARTICULOS DOMESTICOS DE UNA IMPORTANTE EMPRESA DE LA CIUDAD DE MEXICO. */

typedef struct /*DECLARACION DE LA ESTRUCTURA BANCO. */
{
    char noba[10];  /*NOMBRE DEL BANCO. */
    char nucu[10];  /*NUMERO DE CUENTA. */
} banco;

typedef union /*DECLARANCION DE LA UNION FPAGO. */
{
    banco che; /*CHEQUE. CAMPO DE TIPO ESTRUCTURA BANCO. */
    banco nomi;/*COMINA. CAMPO DE TIPO ESTRUCUTA BANCO. */
    char venta;/*VENTANILLA. */
} fpago;

 typedef struct /* Declaración de la estructuradomicilio. */
 {
 char cnu[20];         /* Calle y número. */
 char col[20];         /* Colonia. */
 char cp[5];           /* Código Postal. */
 char ciu[15];         /* Ciudad. */
 } domicilio;

 typedef struct /*DECLARACION DE ESTRUCTURA VENDEDOR. */
 {
     int num; /* numero de vendendro. */
     char nom[20]; /* nombre del vendedor. */
     float ven[12]; /* ventas del año. Arrelo unidimensional de tipo rea. */
     domicilio domi; /* domi es de tipo estructura dominicilio. */
     float sal; /*salario mensual. */
     fpago pago; /*pao es de tipo union fpago. */
     int cla; /*clave forma de pago. */
 } vendedor;

 void Lectura(vendedor *, int);
 void F1(vendedor *, int);
 void F2(vendedor *, int); /*prototipo de funciones. */
 void F3(vendedor *, int);
 void F4(vendedor *, int);

 void main(void)
 {
     vendedor VENDEDORES[100];
     /* DECLARACION DEL ARREGLO UNIDIMENSIONAL DE TIPO ESTRUCTURA VENDEDOR. */
     int TAM;
     do
     {
         printf("Ingrese el numero de vendedores: ");
         scanf("%d", &TAM);
     }
     while (TAM > 100 || TAM < 1);
     /* se verifica que el numero de elementos del arrelo sea correcto. */
     Lectura(VENDEDORES, TAM);
     F1(VENDEDORES, TAM);
     F2(VENDEDORES, TAM);
     F3(VENDEDORES, TAM);
     F4(VENDEDORES, TAM);
     printf("\n\tFIN DEL PROGRAMA");
 }

 void Lectura(vendedor A[], int T)
 /* esta funcion se utiliza para leer un arreglo unidimensional de tipo
 estructura vendedor de T elementos. */
 {
     int I, J;
     for (I=0; I<T; I++)
     {
         printf("\n\tIngrese datos del vendedor %d", I+1);
         printf("\nNumero de vendedor: ");
         scanf("%d", &A[I].num);
         printf("Nombre del vendedor: ");
         fflush(stdin);
         gets(A[I].nom);
         printf("Ventas del año: \n");
         for(J=0; J<12; J++)
         {
             printf("\tMes %d: ", J+1);
             scanf("%f", &A[I].ven[J]);
         }
         printf("Domicilio del vendedor: \n");
         printf("\tCalle y numero: ");
         fflush(stdin);
         gets(A[I].domi.cnu);
         printf("\tColonia: ");
         fflush(stdin);
         gets(A[I].domi.col);
         printf("\tCodigo Postal: ");
         fflush(stdin);
         gets(A[I].domi.cp);
         printf("\tCiudad: ");
         fflush(stdin);
         gets(A[I].domi.ciu);
         printf("Salario del vendedor: ");
         scanf("%f", &A[I].sal);
         printf("Forma de Pao (Banco-1 Nomina-2 Ventanilla-3): ");
         scanf("%d", &A[I].cla);
         switch (A[I].cla)
         {
             case 1: {
                 printf("\tNombre del banco: ");
                 fflush(stdin);
                 gets(A[I].pago.che.noba);
                 printf("\tNumero de cuenta: ");
                 fflush(stdin);
                 gets(A[I].pago.che.nucu);
             }
             break;
            case 2:{
 printf("\tNombre del banco: ");
 fflush(stdin);
 gets(A[I].pago.nomi.noba);
 printf("\tNúmero de cuenta: ");
 fflush(stdin);
 gets(A[I].pago.nomi.nucu);
 }
 break;
 case 3: A[I].pago.venta = 'S';
 break;
         }
     }
 }

 void F1(vendedor A[], int T)
 /* ESTA FUNCION SE UTILIZA PARA GENERAR LAS VENTAS TOTALES ANUALES DE CADA UNO
 DE LOS VENDEDORES DE LA EMPRESA. */
 {
     int I, j;
     float SUM;
     printf("\n\t\tVentas totales de los vendedores");
     for (I=0; I<T; I++)
     {
         printf("\nVendedor: %d", A[I].num);
         SUM = 0.0;
         for (J=0; J<12; J++)
            SUM += A[I].ven[J];
         printf("\nVentas: %.2lf\n", SUM);
     }
 }

 void F2(vendedor A[], int)
 /* Esta funcion se utiliza para incrementar 5% el salario de todos aquellos
 vendedores cuyas ventas anuales superaron $1,500,000. */
 {
     int I, J;
     float SUM;
     printf("\n\t\tIncremento a los vendedores con Ventas > 1,500,000$");
     for (I=0; I<T; I++)
     {
         SUM = 0.0;
         for (J=0; J<12; J++)
            SUM += A[I].ven[J];
         if (SUM > 1500000.00)
         {
             A[I].sal = A[I].sal * 1.05;
             printf("\nNumero de empleado %d\nVentas: %2.f\nNuevo salario: %.2f", A[I].num, SUM, A[I].sal);
         }
     }
 }

 void F3(vendedor A[], int T)
 /* esta funcion se utiliza para generar un listado de todos aquellos
 vendedores que en el año vendieron menos de $300,000. */
 {
     int I, J;
     float SUM;
     printf("\n\t\tVendedores con ventas < 300,000");
     for (I=0; I<T; I++)
     {
         SUM = 0.0;
         for (J=0; J<12; J++)
            SUM += A[I].ven[J];
         if (SUM < 300000.00)
            printf("\nNumero de empleado: %d\nNombre: %s\nVentas: %.2f", A[I].num, A[I].nom, SUM);
     }
 }
void F4(vendedor A[], int T)
/* Esta funcion se usa para imprimir el numero de empleado, el nombre del
banco y el numero de cuenta de todos aquellos empleados a quienes se les
deposita su sueldo en cuenta de cheques. */
{
    int I;
    float SUM;
    printf("\n\t\tVendedores con cuenta en el banco");
    for (I=0; I<T; I++)
        if (A[I].cla == 1)
        printf("\nNumero de vendedor: %d\nBanco: %s\nCuenta: %s",
               A[I].num, A[I].pago.che.noba, A[I].pago.che.nucu);
}
