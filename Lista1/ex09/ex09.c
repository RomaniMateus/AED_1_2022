#include <stdlib.h>
#include <stdio.h>

int main()
{
    float matriz[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("\nEndereco de matriz[%i][%i]: %i", i, j, &matriz[i][j]);
        }
        
    }
    
    return 0;
}
