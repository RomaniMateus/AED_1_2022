/* Construa um programa (main) que aloque em tempo de execução (dinamicamente)
uma matriz de ordem m x n (linha por coluna), usando 1+m chamadas a função
malloc. Agora, aproveite este programa para construir uma função que recebendo os
parametros m e n aloque uma matriz de ordem m x n e retorne um ponteiro para esta
matriz alocada. Crie ainda uma função para liberar a área de memória alocada pela
matriz. Finalmente, crie um novo programa (main) que teste/use as duas funções
criadas acima. */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int** alocaMatriz(int, int);
void preencheMatriz(int **, int);
void liberaMatriz(int **, int);

int main()
{
    int M, N, **matrizA, **matrizB;

    printf("Digite uma quantidade de linhas m: ");
    scanf("%i", &M);
    printf("\nDigite uma quantidade de colunas n: ");
    scanf("\n%i", &N);

    //alocando dinamicamente a matriz A
    matrizA = (int **) malloc(M*sizeof(int *));

    for(int i = 0; i < N; i++)
    {
        matrizA[i] = (int *) malloc(N*sizeof(int));
    }

    //alocando dinamicamente a matriz B
    matrizB = alocaMatriz(M, N);

    preencheMatriz(matrizA, N);
    printf("\n\n");
    preencheMatriz(matrizB, N);
    liberaMatriz(matrizA, N);
    liberaMatriz(matrizB, N);
    return 0;
}

int** alocaMatriz(int linha, int coluna)

{
    int **ponteiro;

    ponteiro =  (int **) malloc(linha * sizeof(int*));

    for (int i = 0; i < coluna; i++)
    {
        ponteiro[i] = (int *) malloc(coluna*sizeof(int));
    }
    
    return ponteiro;
}

void preencheMatriz(int **matriz, int coluna)
{
    srand(time(NULL));

    for (int i = 0; i < coluna; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            matriz[i][j] = rand()%101;
            printf("matriz[%i][%i]: %i\t", i, j, matriz[i][j]);
        }
        printf("\n");
    }
    
}

void liberaMatriz(int **matriz, int coluna)
{
    for (int i = 0; i < coluna; i++)
    {
        free(matriz[i]);
    }
    
    free(matriz);
}