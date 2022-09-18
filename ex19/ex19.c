#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int *array, quantidade, maior = 0, count = 0;

    printf("Digite o tamanho do array: "); //capturando o tamanho do array
    scanf("%i", &quantidade);

    array = malloc(quantidade * sizeof(int)); //alocando o espaço dinamicamente

    for (int i = 0; i < quantidade; i++) //preenchendo o array com valores digitados pelo usuário
    {
        printf("\nDigite um valor inteiro para array[%i]: ", i);
        scanf("%i", &array[i]);
    }

    for (int j = 0; j < quantidade; j++)
    {
        if (array[j] >= maior)
        {
            maior = array[j];
            count = 0;
        }

        if (array[j] == maior)
        {
            count++;
        }
        
    }
    
    printf("O maior numero do array eh: %i\nQuantidade de aparicoes: %i", maior, count);

    free(array);
    return 0;
}
