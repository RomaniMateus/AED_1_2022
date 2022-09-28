#include <stdlib.h>
#include <stdio.h>

int main() {

    int a, b;

    if(&a > &b) {
        printf("\nO endereço de a eh o maior. Aqui esta: %d", &a);
    }
    else {
        printf("\nO endereco de b eh o maior. Aqui esta: %d", &b);
    }

    return 0;
}