#include <stdlib.h>
#include <stdio.h>

int main()
{
    int tamanho, *array;

    printf("Digite um tamanho para o array: ");
    scanf("%i", &tamanho);

    array = malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++)
    {
        printf("\nDigite um valor inteiro para array[%i]:", i);
        scanf("%i", array);
    }
    
    return 0;
}
