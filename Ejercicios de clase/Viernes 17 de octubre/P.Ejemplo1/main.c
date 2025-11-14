#include <stdio.h>
#include <stdlib.h>

int main()
{
    //float son de 32 bits ocupan 4byte
    //double son de 64 bits 8byte
    double lineaF[3];
    double resultado = 0.0;
    double pro = 0.0;
    lineaF[0]= 1250.45;
    lineaF[1]= 120.00;
    lineaF[2]= 350.00;

    for(int i = 0; i<3; i++)
    {
        printf("\nLinea[%i]=%f",i,lineaF[i]);
        resultado += lineaF[i];
        pro = resultado/3;
    }
    printf("\nTotal: %f",resultado);
    printf("\nPromedio: %12lf", pro);
    return 0;
}
