#include <stdlib.h>
#include <stdio.h>

int main()
{
    float array[10];

    for (int i = 0; i < 10; i++)
    {
        printf("\nEndereco do float %i: %i", (i+1), &array[i]);
    }
    
    return 0;
}
