#include <stdlib.h>
#include <stdio.h>

void minEmax(int*, int, int *, int *);

int main()
{
    int *array, *pArray, tamanho, min, max;

    pArray = *array;

    printf("Digite um tamanho para o array:"); //lendo o tamanho do array
    scanf("%i", &tamanho);

    array = malloc(tamanho * sizeof(float)); //alocando dinamicamente o espaço de acordo com o tamanho lido

    for (int i = 0; i < tamanho; i++)
    {
        printf("\nDigite um valor inteiro para array[%i]: ", i);
        scanf("%i", pArray);
        printf("array[%i]: %i", i, *pArray);

        pArray++;
    }

    minEmax(array, tamanho, &min, &max);

    printf("\nO maior elemento eh: %i", max);
    printf("\nO menor elemento eh: %i", min);

    return 0;
}

void minEmax(int *array, int tamanho, int *min, int *max)
{
    int auxMin = 0, auxMax = 0;

    for (int i = 0; i < tamanho; i++)
    {
        printf("\n*array: %i", *array);

        if (*array < auxMin)
        {
            auxMin = *array;
        }
        else
        {
            if (*array >auxMax)
            {
                auxMax = *array;
            }
            
        }

        array++;        
    }
    
}