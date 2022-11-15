#include <stdlib.h>
#include "SparseMatrix.h"

int main()
{
    int selectedOption, value, insertionLine, insertionColumn;

    pMATRIX matrix;

    initializeMatrix(matrix);

    do
    {
        printMenu();
        scanf("\n%d", &selectedOption);

        switch (selectedOption)
        {
            case 1:
                getValueAndCoordinates(&value, &insertionLine, &insertionColumn);
                assignValue(matrix, &insertionLine, &insertionColumn, &value);
            break;

            case 2:
                printMatrix(matrix);
            break;

            case 3:
                printf("\nLeaving program...");
            break;
        
            default:
                errorMessage();
            break;
        }
    } while (selectedOption != 3);

    return 0;
}