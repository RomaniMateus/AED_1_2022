#include <stdlib.h>
#include <stdio.h>

int main()
{
    int array[10], *pArray;

    pArray = array;

    *pArray = 5;
    printf("array[0]: %i", *pArray);
    pArray++;

    for (int i = 1; i < 10; i++, pArray++)
    {
        *pArray = *(pArray - 1) + 1;
        printf("\narray[%i]: %i", i, *pArray);
    }
    
    return 0;
}
