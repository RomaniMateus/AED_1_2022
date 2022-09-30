#include <stdlib.h>
#include <stdio.h>

void verificaMaioreMenor(int, int, int *, int *);

int main()
{
    int maior, menor, temp1, temp2;

    printf("Digite um numero: ");
    scanf("%i", &temp1);
    printf("\nDigite outro numero: ");
    scanf("%i", &temp2);

    verificaMaioreMenor(temp1, temp2, &maior, &menor);

    printf("\nEste eh o maior numero: %i", maior);
    printf("\nEste eh o menor numero: %i", menor);
    
    return 0;
}

void verificaMaioreMenor(int temp1, int temp2, int *maior, int *menor) 
{
    if (temp1 > temp2)
    {
        *maior = temp1;
        *menor = temp2;
    }
    else
    {
        *maior = temp2;
        *menor = temp1;
    }
    
}