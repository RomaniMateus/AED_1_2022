#include <stdlib.h>
#include <stdio.h>

int main()
{
    int arrayInt[5];

    for (int i = 0; i < 5; i++)
    {
        printf("\nDigite um valor para arrayInt[%i]: ", i);
        scanf("%i", &arrayInt[i]);
    }

    for (int j = 0; j < 5; j++)
    {
        if (arrayInt[j] % 2 == 0)
        {
            printf("\narrayInt[%i]: %i", j, arrayInt[j]);
        }
        
    }
    
    return 0;
}
