/* Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos
e passe esse vetor para uma função que vai ler os elementos desse vetor. Depois, no
programa principal, o vetor preenchido deve ser impresso. Além disso, antes de
finalizar o programa, deve-se liberar a área de memória alocada. */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void preencheVetor(int *, int);

int main()
{
    int n, *vetor;
    printf("Digite um valor para N: ");
    scanf("%i", &n);

    vetor = malloc(n * sizeof(int));

    preencheVetor(vetor, n);

    for (int i = 0; i < n; i++)
    {
        printf("\n%i", vetor[i]);
    }
    
    free(vetor);
    
    return 0;
}

void preencheVetor(int *vetor, int n)
{
    srand(time(NULL));
    
    for (int i = 0; i < n; i++)
    {
        vetor[i] = rand() % 101;
    }
    
}