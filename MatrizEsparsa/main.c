#include <stdlib.h>
#include "SparseMatrix.h"

int main()
{
    int lines, columns, value, insertionLine, insertionColumn;
    pMATRIX matrix;

    matrix = (pMATRIX) malloc(sizeof(MATRIX));
    printf("Number of lines: ");
    scanf("%d", &lines);
    printf("Number of columns: ");
    scanf("%d", &columns);

    initializeMatrix(matrix, lines, columns);

    printf("\nwhat number do you want to insert?");
    scanf("%d", &value);
    printf("\nIn what line do you want to insert the given value?");
    scanf("%d", &insertionLine);
    printf("\nIn what column do you want to insert the given value?");
    scanf("%d", &insertionColumn);

    if (assignValue(matrix, insertionLine, insertionColumn, value))
    {
        printf("\nhere is your number: %d", matrix->A[insertionLine]->value);
    }
    else
        printf("\nsomething went wrong...");

    return 0;
}