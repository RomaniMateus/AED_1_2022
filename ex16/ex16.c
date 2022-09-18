#include <stdlib.h>
#include <stdio.h>

int main()
{
    int A = 5, *B, **C, ***D;

    B = &A;
    C = &B;
    D = &C;

    printf("Digite um valor para A: ");
    scanf("%i", &A);

    printf("\nO dobro de A eh: %i", *B * 2);

    printf("\nO triplo de A eh: %i", **C * 3);

    printf("\nO quadruplo de A eh: %i", ***D * 4);

    return 0;
}
