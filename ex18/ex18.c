#include <stdlib.h>
#include <stdio.h>
#define P 3.14

void calc_esfera(float, float *, float *);

int main()
{
    float raio, area, volume;

    printf("Digite um numero real para o raio: ");
    scanf("%f", &raio);

    calc_esfera(raio, &area, &volume);
    
    printf("\nA area e: %.2f", area);
    printf("\nO volume e: %.2f", volume);

    return 0;
}

void calc_esfera(float R, float *area, float *volume)
{
    *area = 4* P * R * R;
    *volume = (4/3) * P * R * R * R;
}