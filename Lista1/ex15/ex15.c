#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void imprimeArray(char *);

int main()
{

    char array[10] = "1234567890";

    imprimeArray(array);

    return 0;
}

void imprimeArray(char *array)
{
    char *Parray;
    Parray = array;

    for (int i = 0; i < 10; i++, Parray++)
    {
        printf("\narray[%i]: %c", i, *Parray);
    }
    
}