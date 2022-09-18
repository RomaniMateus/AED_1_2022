#include <stdio.h>
#include <stdlib.h>

void trocaValores(int *, int *);

int main() {

    int n1, n2;

    printf("Insira o valor para o n1: ");
    scanf("%i", &n1);
    printf("\nInsira o valor para o n2: ");
    scanf("%i", &n2);

    trocaValores(&n1, &n2);

    printf("\nValor de n1 depois da troca: %i", n1);
    printf("\nValor de n2 depois da troca: %i", n2);

    return 0;
}

void trocaValores(int * a, int * b) {
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}