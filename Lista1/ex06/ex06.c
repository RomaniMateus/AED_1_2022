#include <stdlib.h>
#include <stdio.h>

int somaDoDobro(int *, int *);

int main()
{
    int A, B, resultado;

    printf("Digite um valor para A: ");
    scanf("%i", &A);
    printf("Digite um valor para B: ");
    scanf("%i", &B);

    resultado = somaDoDobro(&A, &B);

    printf("\nA soma do dobro eh: %i\nAgora o valor de A eh: %i\nAgora o valor de B eh: %i", resultado, A, B);
    return 0;
}

int somaDoDobro(int *A, int *B)
{
    
    *A = (2 * *A);
    *B = (2 * *B);

    return (*A + *B);
}