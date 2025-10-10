#include <stdio.h>
#include <stdlib.h>
#define EDAD_MIN 0
#define EDAD_MAX 120

int main()
{
    //AND && OR || NOT!
    // == != > < <= =>
    //enunciado
    //0 2 es infante
    //3 a 10 es un niño
    //11 a 12 es un pre adolescente
    //13 a 17 es adolescente
    //18 a 40 mayor de edad
    //41 a 65 es adulto mayor
    //65 a EDAD_MAX es envejeciente
    int edad = EDAD_MIN;
    printf("\nIngresa la edad: ");
    scanf("%i", &edad);

    if (edad >= EDAD_MIN && edad <= EDAD_MAX)
      {
          if (edad >= EDAD_MIN && edad <=2)
          {
              printf("\nEs un infante");
          }
          else if(edad <= 10)
          {
             printf("\nEs un pre adolescente");
          } else if(edad <= 17)
          {
             printf("\nEs un adolescente");
          } else if(edad <= 40)
          {
             printf("\nEs mayor de edad");
          } else if(edad > 40 && edad <= 65)
          {
             printf("\nEs un adulto mayor");
          } else if(edad <= EDAD_MAX)
          {
             printf("\nEs un envejeciente");
          }
      }
      else
        {
            if(edad < EDAD_MIN)
          {
             printf("\n----Usted viene del pasado----");
          }

      if(edad > EDAD_MAX)
          {
             printf("\n---Usted es un banbiro---");
          }
            printf("\n----Edad fuera de rango valido----");
        }
        printf("\n----Fin----");
        return 0;
}
