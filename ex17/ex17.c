#include <stdlib.h>
#include <stdio.h>

void frac(float, int *, float *);

int main()
{
    float num, *fracao;
    int *inteiro;

    printf("Digite um valor para real: ");
    scanf("%f", &num);

    frac(num, inteiro, fracao);

    return 0;
}

void frac(float num, int *inteiro, float *fracao)
{
    int auxInteiro;
    float auxReal;

    inteiro = &auxInteiro;
    fracao = &auxReal;

    auxInteiro = (int) num;
    auxReal = num - ((int) num);

    printf("parte inteira: %i", *inteiro);
    printf("\nparte real: %f", *fracao);
}