/*Faça uma função que receba um valor n e crie dinamicamente um vetor de n
elementos e retorne um ponteiro. Crie uma função que receba um ponteiro para um
vetor e um valor n e imprima os n elementos desse vetor. Construa também uma
função que receba um ponteiro para um vetor e libere esta área de memória. Ao final,
crie uma função principal que leia um valor n e chame a função criada acima. Depois,
a função principal deve ler os n elementos desse vetor. Então, a função principal deve
chamar a função de impressão dos n elementos do vetor criado e, finalmente, liberar a
memória alocada através da função criada para liberação. */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void imprimeVetor(int *, int);
void liberaVetor(int *);

int main()
{
    int n, *vetor;
    printf("Digite um valor para N: ");
    scanf("%i", &n);

    vetor = malloc(n * sizeof(int)); //alocando dinamicamente o vetor

    srand(time(NULL)); //lendo os n elementos do vetor
    
    for (int i = 0; i < n; i++)
    {
        vetor[i] = rand() % 101;
    }

    imprimeVetor(vetor, n);

    liberaVetor(vetor);
    
    return 0;
}

void imprimeVetor(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n%i", vetor[i]);
    }
}

void liberaVetor(int *vetor)
{
    free(vetor);
}