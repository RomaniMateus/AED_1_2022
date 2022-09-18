#include <stdlib.h>
#include <stdio.h>

int somaArray(int *, int, int *, int);

int main()
{
    
    int array1[5]= {1,2,3,4,5}, array2[5] = {1,2,3,4,5}, array3[6] = {1,2,3,4,5,6}, array4[5] = {1,2,3,4,5}, resultado1, resultado2;

    resultado1 = somaArray(array1, 5, array2, 5);

    if (resultado1 == 1)
    {
        printf("\nA soma deu certo!");
    }
    else
    {
        printf("\nA soma deu errado...");
    }

    resultado2 = somaArray(array3, 6, array4, 5);

    if (resultado2 == 1)
    {
        printf("\nA soma deu certo!");
    }
    else
    {
        printf("\nA soma deu errado...");
    }
    
    return 0;
}

int somaArray(int *array1, int tamanho1, int *array2, int tamanho2)
{

    int array3[5];

    if (tamanho1 != tamanho2)
    {
        return 0;
    }
    else
    {

        for (int i = 0; i < tamanho1; i++, array1++, array2++)
        {
            *array3 = *array1 + *array2;
        }

        return 1;
    }
    
}