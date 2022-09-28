#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void preencheArray(int *, int);

int main()
{
    int array[10], valor = 1, *Parray;

    Parray = array;

    
    preencheArray(Parray, valor);

    for (int i = 0; i < 10; i++, Parray++)
    {
        printf("\narray[%i]: %i", i, *Parray);
    }

    return 0;
}

void preencheArray(int *Parray, int valor)
{
    for (int i = 0; i < 10; i++, Parray++)
    {
        *Parray = valor;
    }
    
}
