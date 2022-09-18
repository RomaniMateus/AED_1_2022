#include <stdlib.h>
#include <stdio.h>

int main()
{
    int arrayInt[5], *Parray;
    Parray = arrayInt;

    for (int i = 0; i < 5; i++, Parray++)
    {
        printf("\nDigite um valor para arrayInt[%i]: ", i);
        scanf("%i", Parray);
    }
    
    Parray = arrayInt;

    for (int j = 0; j < 5; j++, Parray++)
    {
        printf("\n2 * arrayInt[%i]: %i", j, *Parray * 2);
    }
    
    return 0;
}
