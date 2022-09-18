#include <stdlib.h>
#include <stdio.h>

void metodoSoma(int *, int *);

int main()
{
    int A = 2, B = 3;

    metodoSoma(&A, &B);

    printf("\nEste eh o valor de A: %i", A);
    printf("\nEste eh o valor de B: %i", B);    
    return 0;
}

void metodoSoma(int *A, int *B)
{
    *A = *A + *B;
}
