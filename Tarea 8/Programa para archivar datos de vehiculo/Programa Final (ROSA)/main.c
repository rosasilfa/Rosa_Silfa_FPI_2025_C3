#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEHICULOS 200
#define FILE_NAME "Vehiculos.txt"

//PROGRAMA FINAL FUNDAMENTOS DE PROGRAMACION I -- ROSA SILFA -- 20251674 -- 12 DE DICIEMBRE DE 2025

//ESTRUCTURA PARA ALMACENAR LOS DATOS DE UN VEHICULO
typedef struct {
char Marca[50];
char Modelo[50];
int Anio;
float Precio;
} Vehiculo;

//LISTADO DE VEHICULOS
Vehiculo vehiculos[MAX_VEHICULOS];
int Cantidad = 0;

void mostrarMenu()
{
    printf("\n\033[0;33m--- MENU ---\033[0m\n");
    printf("\033[0;33m1. Lista de vehiculos\033[0m\n");
    printf("\033[0;33m2. Agregar vehiculo\033[0m\n");
    printf("\033[0;33m3. Salir\033[0m\n");
    printf("Seleccione una opcion: ");
}

void listarVehiculos()
{
    if (Cantidad == 0) {
        printf("\033[0;31m\nNo hay vehiculos registrados. \n\033[0m");
    }
    else
    {
        printf("\n\033[0;33m--- Lista de Vehiculos ---\033[0m\n");
        for (int i = 0; i < Cantidad; i++)
        {
            printf("%d. Marca: %s | Modelo: %s | Año: %d | Precio: %.2f\n", i + 1, vehiculos[i].Marca, vehiculos[i].Modelo, vehiculos[i].Anio, vehiculos[i].Precio);
        }
    }
}

void guardarVehiculoenArchivo(const Vehiculo* v)
{
    FILE *f = fopen(FILE_NAME, "a");
    if (!f)
    {
        printf("\033[0;31m\nError: no se puedo abrir el archivo para escritura.\n\033[0m");
        return;
    }
    fprintf(f, "%s;%s;%d;%.2f", v->Marca, v->Modelo, v->Anio, v->Precio);
    fclose(f);
}

void cargardesdeArchivo()
{
    FILE *f = fopen(FILE_NAME, "r");
    if (!f)
    {
        return;
    }
    Vehiculo v;
    while (Cantidad < MAX_VEHICULOS && fscanf(f, "%49[^;];%49[^;];%d;%f\n", v.Marca, v.Modelo, &v.Anio, &v.Precio) == 4)
    {
        vehiculos[Cantidad++] = v;
    }

    fclose(f);
}

void agregarVehiculo()
{
    if (Cantidad >= MAX_VEHICULOS)
    {
        printf("\033[0;31m\nNo se pueden agregar mas vehiculos.\n\033[0m");
        return;
    }

    Vehiculo v;
    printf("\nIngrese la marca: ");
    scanf("%s", v.Marca);
    printf("Ingrese el modelo: ");
    scanf("%s", v.Modelo);
    printf("Ingrese el año: ");
    scanf("%d", &v.Anio);
    printf("Ingrese el precio: ");
    scanf("%f", &v.Precio);

    vehiculos[Cantidad] = v;
    Cantidad++;

    guardarVehiculoenArchivo(&v);

    printf("\033[0;32mVehiculo agregado exitosamente\n\033[0m");
}


int main()
{
    cargardesdeArchivo();

    int Opcion;
    do {
        mostrarMenu();
        scanf("%d", &Opcion);

        switch (Opcion)
        {
            case 1: listarVehiculos();
            break;
            case 2: agregarVehiculo();
            break;
            case 3: printf("\033[0;32m\nSaliendo del programa...\n\033[0m");
            break;
            default: printf("\033[0;31m\nOpcion invalida, intente de nuevo.\n\033[0m");
        }

    } while (Opcion != 3);
    return 0;
}
