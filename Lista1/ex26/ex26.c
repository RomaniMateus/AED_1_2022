#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int raizes(float, float, float, float *, float *);

int main()
{
    int resultado;
    float A, B, C, X1, X2;

    printf("Equacao quadratica do tipo AX^2 + BX +C");

    printf("\nDigite um valor para o coeficiente A: ");
    scanf("%f", &A);
    
    while (A == 0)
    {
        printf("\nDigite um valor diferente de zero: ");
        scanf("%f", &A);
    }
    
    printf("\nDigite um valor para o coeficiente B: ");
    scanf("%f", &B);

    printf("\nDigite um valor para o coeficiente C: ");
    scanf("%f", &C);

    resultado = raizes(A, B, C, &X1, &X2);

    switch (resultado)
    {
    case 0:

        printf("\nNao existem raizes reais");
        break;
    case 1:

        printf("\nExistem duas raizes porem elas sao iguais");
        printf("\nraiz X1: %.2f", X1);
        printf("\nraiz X2: %.2f", X2);
        break;

    default:

        printf("\nExistem duas raizes e elas sao diferentes");
        printf("\nraiz X1: %.2f", X1);
        printf("\nraiz X2: %.2f", X2);
        break;
    }
    return 0;
}

int raizes(float A, float B, float C, float *X1, float *X2)
{
    float delta = B * B - 4 * A * C;

    if (delta < 0)
    {
        return 0;
    }
    else
    {
        *X1 =  (- B + sqrt(delta))/2 * A;
        *X2 = (- B - sqrt(delta))/ 2 * A;

        if (delta == 0)
        {
            return 1;
        }
        else
        {
            return 2;
        }
        
    }
    
}