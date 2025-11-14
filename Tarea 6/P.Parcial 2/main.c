#include <stdio.h>
#include <stdlib.h>

//Colores.
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[1;36m"
#define PURPLE "\033[0;35m"

typedef struct
{
    double real;
    double imag;
}
Complejo;

//Funciones básicas con double
double Sumar(double a, double b) {return a + b;}
double Restar(double a, double b) {return a - b;}
double Multiplicar(double a, double b) {return a * b;}
double Dividir(double a, double b)
{
if(b == 0)
    {
        printf(RED "Error: Division por cero. \n" RESET);
        return 0;
    }
    return a / b;
}

//Funciones con números complejos.
Complejo SumarComplejo(Complejo a, Complejo b)
{
    return(Complejo){a.real + b.real, a.imag + b.imag};
}
Complejo RestarComplejo(Complejo a, Complejo b)
{
    return(Complejo){a.real - b.real, a.imag - b.imag};
}
Complejo MultiplicarComplejo(Complejo a, Complejo b)
{
    return(Complejo){a.real * b.real, a.imag * b.imag};
}
Complejo DividirComplejo(Complejo a, Complejo b)
{
    double denom = b.real * b.real + b.imag * b.imag;
    if (denom == 0)
    {
        printf(RED "Error: División por cero en complejo. \n" RESET);
        return (Complejo){0,0};
    }
    return(Complejo){(a.real * a.real + a.imag * a.imag)/denom,
    (a.imag * b.real - a.real * b.imag)/denom};
}

//Funciones con matrices.
void LeerMatrices(int n, int m, double M[n][m])
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
    {
        printf(YELLOW "Elemento [%d][%d]: " RESET, i+1, j+1);
        scanf("%lf", &M[i][j]);
    }
}
void SumarMatrices(int n, int m, double A[n][m], double B[n][m], double R[n][m])
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        R[i][j] = A[i][j] + B[i][j];
}

void RestarMatrices(int n, int m, double A[n][m], double B[n][m], double R[n][m])
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        R[i][j] = A[i][j] - B[i][j];
}

void MultiplicarMatrices(int n, int m, int p, double A[n][m], double B[m][p], double R[n][p])
{
    for(int i=0; i<n; i++)
        for(int j=0; j<p; j++)
    {
        R[i][j] = 0;
        for(int k=0; k<m; k++)
            R[i][j] += A[i][k] * B[k][j];
    }
}

//Mostrar matriz.
void MostrarMatriz(int n, int m, double M[n][m])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            printf("%8.2lf ", M[i][j]);
        printf("\n");
    }
}

//Funcion para mostrar el menú principal
void MostrarMenu()
{
    printf(PURPLE "=====================================\n" RESET);
    printf(CYAN "       Bienvenido a CALCULUS C     \n" RESET);
    printf(PURPLE "============================\n\n" RESET);

    printf(YELLOW "\nSeleccione una opcion:\n" RESET);
        printf(YELLOW "---------------------------\n" RESET);
        printf(YELLOW "1. Operaciones con double\n" RESET);
        printf(YELLOW "2. Operaciones con numeros complejos\n" RESET);
        printf(YELLOW "3. Operaciones con matrices\n" RESET);
        printf(YELLOW "0. Salir\n" RESET);
        printf(YELLOW "--------------------------\n" RESET);
        printf("Opcion: ");
}

void MostrarMenuDouble()
{
        printf(YELLOW "\nOperaciones con double:\n" RESET);
        printf(YELLOW "--------------------------\n" RESET);
        printf(YELLOW "1. Sumar\n" RESET);
        printf(YELLOW "2. Restar\n" RESET);
        printf(YELLOW "3. Multiplicar\n" RESET);
        printf(YELLOW "4. Dividir\n" RESET);
        printf(YELLOW "0. Volver\n" RESET);
        printf(YELLOW "--------------------------\n" RESET);
        printf("Opcion: ");
}

void MostrarMenuComplejo()
{
    printf(YELLOW "\nOperaciones con numeros complejos:\n" RESET);
    printf(YELLOW "------------------------------------\n" RESET);
    printf(YELLOW "1. Sumar\n" RESET);
    printf(YELLOW "2. Restar\n" RESET);
    printf(YELLOW "3. Multiplicar\n" RESET);
    printf(YELLOW "4. Dividir\n" RESET);
    printf(YELLOW "0. Volver\n" RESET);
    printf(YELLOW "-------------------------------------\n" RESET);
    printf("Opcion: ");
}

void MostrarMenuMatrices()
{
    printf(YELLOW "\nOperaciones con matrices:\n" RESET);
    printf(YELLOW "----------------------------------\n" RESET);
    printf(YELLOW "1. Sumar\n" RESET);
    printf(YELLOW "2. Multiplicar\n" RESET);
    printf(YELLOW "0. Volver\n" RESET);
    printf(YELLOW "----------------------------------\n" RESET);
    printf("Opcion: ");
}

int main()
{
    int Opcion;
    do
    {
        MostrarMenu();
        scanf("%d", &Opcion);

        if(Opcion == 1)
        {
            double a, b;
            int op;
            do
            {
                MostrarMenuDouble();
                scanf("%d", &op);
            printf(YELLOW "Ingrese dos numeros: " RESET);
            scanf("%lf %lf", &a, &b);
            switch(op)
            {
                case 1: printf(GREEN "Resultado: %.2lf\n" RESET, Sumar(a,b));
                break;
                case 2: printf(GREEN "Resultado: %.2lf\n" RESET, Restar(a,b));
                break;
                case 3: printf(GREEN "Resultado: %.2lf\n" RESET, Multiplicar(a,b));
                break;
                case 4: printf(GREEN "Resultado: %.2lf\n" RESET, Dividir(a,b));
                break;
                default: printf(RED "Opcion invalida.\n" RESET);
            }
            } while(op!=0);
        }

        else if(Opcion == 2)
        {
            Complejo c1, c2, r;
            int op;
            do
            {
                MostrarMenuComplejo();
                scanf("%d", &op);
            printf(YELLOW "Ingrese el primer complejo (real imag): " RESET);
            scanf("%lf %lf", &c1.real, &c1.imag);
            printf(YELLOW "Ingrese el segundo complejo (real imag): " RESET);
            scanf("%lf %lf", &c2.real, &c2.imag);
            switch(op)
            {
            case 1: r = SumarComplejo(c1,c2);
            break;
            case 2: r = RestarComplejo(c1,c2);
            break;
            case 3: r = MultiplicarComplejo(c1,c2);
            break;
            case 4: r = DividirComplejo(c1,c2);
            break;
            default: printf(RED "Opcion invalida.\n" RESET);
            continue;
            }
            printf(GREEN "Resultado: %.2lf + %.2lfi\n" RESET, r.real, r.imag);
            }while(op!=0);
        }
        else if(Opcion == 3)
        {
            int n, m, p, op, opi;
            MostrarMenuMatrices();
            scanf("%d", &opi);
            printf(YELLOW "Ingrese filas y columnas de la primera matriz: " RESET);
            scanf("%d %d", &n, &m);
            double A[n][m];
            LeerMatrices(n,m,A);

            printf(YELLOW "Ingrese filas y columnas de la segunda matriz: " RESET);
            scanf("%d %d", &op, &op);
            double B[p][op];
            LeerMatrices(p, op, B);

            if(n==p && m==op)
            {
                double R[n][m];
                SumarMatrices(n,m,A,B,R);
                printf(GREEN "Suma de matrices:\n" RESET);
                MostrarMatriz(n,m,R);
            }
            if(m==p)
            {
                double R[n][op];
                MultiplicarMatrices(n,m,op,A,B,R);
                printf(GREEN "Multiplicacion de matrices:\n" RESET);
                MostrarMatriz(n,op,R);
            }
        }
    }
    while(Opcion != 0);
  printf(CYAN "Gracias por usar CALCULUS C. ¡Hasta pronto!\n" RESET);
return 0;
}




