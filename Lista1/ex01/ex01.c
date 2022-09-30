#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>


int main() {

    int inteiroAnterior, *inteiro;
    char caractereAnterior, *caractere;
    float realAnterior, *real;

    inteiro = &inteiroAnterior;
    caractere = &caractereAnterior;
    real = &realAnterior;

    *inteiro = 2;
    *caractere = 'b';
    *real = 3.0;

    printf("\nEste eh o inteiro armazenado: %i", *inteiro);
    printf("\nEste eh o caractere armazenado: %c", *caractere);
    printf("\nEste eh o valor do real armazenado: %f", *real);

    return 0;
}
