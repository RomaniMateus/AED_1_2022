#include <stdlib.h>
#include <stdio.h>

int main() {
    
    int a, b;

    printf("Digite um valor para a: ");
    scanf("%i", &a);
    printf("\nDigite um valor para b: ");
    scanf("%i", &b);


    if(a > b) {
        printf("\na eh maior que b");
    }
    else {
        printf("\nb eh maior que a");
    }
    return 0;
}