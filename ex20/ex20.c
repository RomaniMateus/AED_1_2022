#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int negativos(float *, int);

int main()
{
    float *array;
    int tamanho, quantidade;

    printf("Digite um tamanho para o array:"); //lendo o tamanho do array
    scanf("%i", &tamanho);

    array = malloc(tamanho * sizeof(float)); //alocando dinamicamente o espaço de acordo com o tamanho lido

    for (int i = 0; i < tamanho; i++)
    {
        printf("\nDigite um valor real para array[%i]: ", i);
        scanf("%f", &array[i]);
    }
     
    quantidade = negativos(array, tamanho);

    printf("\nO numero de negativos neste array eh: %i", quantidade);
    free(array);
    return 0;
}

int negativos(float *vet, int N)
{
    int quantidade = 0;

    for (int i = 0; i < N; i++)
    {
        if (vet[i] < 0)
        {
            quantidade ++;
        }
        
    }
    
    return quantidade;
}