#include <stdlib.h>
#include <stdio.h>

int ordena(int *, int *, int *);

int main()
{
    int valor1, valor2, valor3, verificaIgualdade;

    printf("Digite o valor 1: ");
    scanf("%i", &valor1);
    printf("Digite o valor 2: ");
    scanf("%i", &valor2);
    printf("Digite o valor 3: ");
    scanf("%i", &valor3);

    verificaIgualdade = ordena(&valor1, &valor2, &valor3);

    printf("valor1: %i\nvalor2: %i\nvalor3: %i", valor1, valor2, valor3);
    return 0;
}

int ordena(int *valor1, int *valor2, int *valor3)
{
    int aux;

    if (*valor1 > *valor2)
    {
        if (*valor1 > *valor3)
        {
            aux = *valor3;
            *valor3 = *valor1;
            *valor1 = aux;
        }
        else
        {
            aux = *valor2;
            *valor2 = *valor1;
            *valor1 = aux;
        }
             
    }
    else
    {
        if (*valor2 > *valor3)
        {
            aux = *valor3;
            *valor3 = *valor2;
            *valor2 = aux;
        }
    
    }
    
    if (*valor1 == *valor2 && *valor1 == *valor3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
