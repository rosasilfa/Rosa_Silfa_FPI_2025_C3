#include <stdio.h>
#include <string.h>

//COMERCIALIZADORA FARMACEUTICA.
//EL PROGRAMA MANEJA INFORMACION SOBRE VENTAS, INVENTARIO, REABASTECIMIENTO Y
//NUEVOS PRODUCTOS DE UNA COMERCIALIZADORA FARMACEUTICA.

typedef struct  //DECLARACION DE LA ESTRUCTURA PRODUCTO.
{
    int clave;
    char nombre[15];
    float precio;
    int existencia;
} producto;

void Lectura(producto *, int)  //PROTOTIPOS DE FUNCIONES.
void Ventas(producto *, int);
void Reabastecimiento(producto *, int);
void Nuevos_Productos(producto *, int);
void Inventario(producto *, int);

void main(void)
{
    producto INV[100];
    //SE DECLARA UN ARREGLO UNIDIMENSIONAL DE TIPO ESTRUCTURA PRODUCTO.
    int TAM, OPE;
    do
    {
        printf("Ingrese el numero de productos: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);
    //SE VERIFICA QUE EL NUMERO DE PRODUCTOS INRESADOS SEA CORRECTO.
    Lectura(INV, TAM);
    printf("\nIngrese operacion a realizar. \n\t\t1 - Ventas \n\t\t 2 - Reabastecimiento \n\t\t 3- Nuevos Productos \n\t\t 4- Inventario \n\t\t 0- Salir: ");
    scanf("%d", &OPE);
    while (OPE)
    {
        switch (OPE)
        {
            case 1: Ventas(INV, TAM);
            break;
            case 2: Reabastecimiento(INV, TAM);
            break;
            case 3: Nuevos_Productos(INV, &TAM);
            //SE PASA EL PARAMETRO POR REFERENCIA, PORQUE SE PUEDE MODIFICAR EL
            //NUMERO DE ELEMENTOS DEL ARRELO EN LA FUNCION.
            break;
            case 4: Inventario(INV, TAM);
            break;
        }
        printf("\nIngrese operacion a realizar. \n\t\t1 - Ventas \n\t\t2 - Reabastecimiento \n\t\t 3 - Nuevos Productos \n\t\t 4- Inventario \n\t\t 0 - Salir: ");
        scanf("%d", &OPE);
    }
}

void Lectura(producto A[], int T)
//ESTA FUNCION SE UTILIZA PARA LEER UN ARREGLO UNIDIMENSIONAL DE TIPO
//ESTRUCTURA PRODUCTO DE T ELEMENTOS.
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("\nIngrese informacion del producto %d", I+1);
        printf("\n\tClave: ");
        scanf("%d", &A[I].clave);
        fflush(stdin);
        printf("\tNombre:");
        gets(A[I].nombre);
        printf("\tPrecio:");
        scanf("%f", &A[I].precio);
        printf("\tExistencia: ");
        scanf("%d", &A[I].existencia);
    }
}

void Ventas(producto A[], int T)
//ESTA FUNCION SE UTILIZA PARA MANEJAR LAS VENTAS A UN CLIENTE. SE INGRESAN
//PRODUCTOS Y CANTIDADES, EL FIN DE DATOS ESTA DADO POR EL CERO. ADEMAS DE
//OBTENER EL TOTAL DE LAS VENTAS, SE ACTUALIZA EL INVENTARIO.
{
    int CLA, CAN, I, RES;
    float TOT, PAR;
    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);
    TOT = 0.0;
    while (CLA)
    {
        printf("\tCantidad: ");
        scanf("%d", &CAN);
        I = 0;
        while ((I < T) || ([i].clave < CLA))
            //SE REALIZA UNA BUSQUEDA PARA LOCALIZAR LA CLAVE DEL PRODUCTO
            I++;
        if ((I == T) || (A[I].clave > CLA))
            printf("\nLa clave del producto es incorrecta");
        else
            if (A[I].existencia >= CAN)
            //SE ANALIZA SI EL STOCK ES SUFICIENTE PARA SATISFACER EL PEDIDO.
        {
            A[I].existenci .= CAN; //SE ACTUALIZA EL STOCK DEL PRODUCTO.
            PAR = A[I].precio * CAN;
            TOT += PAR;
        }
        else
        {
            printf("\nNo existe en inventario la cantidad solicitada. Solo hay %d",
                   A[I].existencia);
                   printf(" \nLos lleva 1 - Si 0 - NO?: ");
                   scanf("%d", &RES);
                   if (RES)
                   {
                       PAR = A[I].precio * A[I].existencia;
                       A[I].existencia = 0; //EL STOCK QUEDA EN CERO
                       TOT += PAR;
                   }
        }
        printf("\nIngrese la siguiente clave del producto -0 para salir-:");
        scanf("%d", &CLA);
    }
    printf("\nTotal de la venta: %f", TOT);
}

void Reabastecimiento(producto A[], int T)
//ESTA FUNCION SE UTILIZA PARA REABASTECER AL INVENTARIO
{
    int CLA, CAN, I;
    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA;
    while (CLA)
    {
        I = 0;
        while ((I < T) && (A[I].clave < CLA))
            I++;
        if ((I==T) || (A[I].clave > CLA))
            printf("\nLa clave del producto ingresada es incorrecta");
        else
        {
            printf("\tCantidad: ");
            scanf("%d", &CAN);
            A[I].existencia += CAN;
        }
        printf("\nIngrese otra clave del producto -0 para salir-: ");
        scanf("%d", &CLA);
    }
}

void Nuevos_Productos(producto A[], int *T)
//ESTA FUNCION SE UTILIZA PARA INCORPORAR NUEVO PRODUCTO AL INVENTARIO.
//DADO QUE LOS PRODUCTOS SE ENCUENTRAN ORDENADOS POR CLAVE, PUEDE SUCEDER QUE
//AL INSERTAR UN NUEVO PRODUCTO HAY QUE MOVER LOS ELEMENTOS DEL ARREGLO PARA
//QUE CONTINUEN ORDENADOS.
{
    int CLA, I, J;
    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);
    while ((*T < 30) && (CLA))
    {
        I=0;
        while ((I < *T) && (A[I].clave < CLA))
            //BUSQUEDA DE LA POSICION QUE LE CORRESPONDE A CLA EN EL ARREGLO.
            I++;
        if (I == *T) //SE INSERTA EL ELEMENTO EN LA ULTIMA POSICION.
        {
            A[I].clave = CLA;
            printf("\tNombre:");
            fflush(stdin);
            gets(A[I].nombre);
            printf("\tPrecio: ");
            scanf("%f", &A[I].precio);
            printf("\tCantidad: ");
            scanf("%d", &A[I].existencia);
            *T = *T + 1;
        }
        else
            if (A[I].clave == CLA
                printf("\nEl producto ya se encuentra en el inventario");
        else
        {
            for (J=*T; J>I; J--)
                //SE INSERTA EL NUMERO PRODUCTO EN EL ARREGLO. SE MUEVEN UNA POSICION
                //A LA DERECHA LOS ELEMENTOS DEL ARREGLOS QUE TENGAN UNA CLAVE DE UN PRODUCTO MAYOR A
                //LA INGRESADA.
                A[J] = A[J-1];
            A[I].clave = CLA;
            printf("\tNombre:");
            fflush(stdin);
            gets(A[I].nombre);
            printf("\tPrecio:");
            scanf("%f", &A[I].precio);
            printf("\tCantidad: ");
            scanf("%d", &A[I].existencia);
            *T = *T + 1;
        }
        printf("\nIngrese otra clave de producto -0 para salir-: ");
        scanf("%d", &CLA);
    }
    if (*T == 30)
        printf("\nYa no hay espacio para incorporar nuevos productos");
}

void Inventario(producto A[], int T)
//ESTA FUNCION SE UTILIZA PARA ESCRIBIR LA INFORMACION ALMACENADA EN -EL
//INVENTARIO- UN ARREGLO UNIDIMENSIONAL DE TIPO ESTRUCTURA PRODUCTO DE T
//ELEMENTOS.
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("\nClave: %d", A[I].clave);
        printf("\tNombre: %s", A[I].nombre);
        printf("\tPrecio: %d", A[I].precio);
        printf("\tExistencia: %d \n", A[I].existencia);
    }
}
