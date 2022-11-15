#include "SparseMatrix.h"

void errorMessage()
{
    printf("\nThis is an invalid option!!");
}
void printMenu()
{
    printf("Select an option: ");
    printf("\n(1)Insert a value (to delete a value, set his value to 0):");
    printf("\n(2)Display matrix");
    printf("\n(3)Leave program");
}

void getValueAndCoordinates(int* value, int* insertionLine, int* insertionColumn)
{
    printf("\nwhat number do you want to insert?");
    scanf("%d", value);
    printf("\nIn what line do you want to insert the given value?");
    scanf("%d", insertionLine);
    printf("\nIn what column do you want to insert the given value?");
    scanf("%d", insertionColumn);  
}

void initializeMatrix(pMATRIX matrix)
{
    int lines, columns;
    printf("Number of lines: ");
    scanf("%d", &lines);
    printf("Number of columns: ");
    scanf("%d", &columns);
    matrix = (pMATRIX) malloc(sizeof(MATRIX));

    matrix->lines = lines;
    matrix->columns = columns;
    matrix->A = (pNODE*) malloc(lines * sizeof(pNODE));

    for (int i = 0; i < lines; i++)
        matrix->A[i] = NULL;
}

int invalidNumber(pMATRIX matrix,int* line, int* column)
{
    return *line < 0 || *line >= matrix->lines || *column < 0 || *column >= matrix->columns;
}

void destroyNode(pMATRIX matrix, pNODE previous, pNODE present, int* line)
{
    if (previous == NULL)
        matrix->A[*line] = present->next;
    else
        previous->next = present->next;

    free(present);
}

int assignValue(pMATRIX matrix, int* line, int* column, int* value)
{
    if (invalidNumber(matrix, line, column))
        return 0;
    else
    {
        
        pNODE previous = NULL;
        pNODE present = matrix->A[*line];

        while (present != NULL && present->column < *column) //searching for the node
        {
            previous = present;
            present = present->next;
        }

        if (present != NULL && present->column == *column) //assigning value to an existing node
        {
            if (*value == 0)
                destroyNode(matrix, previous, present, line);
            else
                present->value = *value;
        }
        else //assigning value to a non-existing node
        {
            pNODE newNode = (pNODE) malloc(sizeof(NODE));
            newNode->column = *column;
            newNode->value = *value;
            newNode->next = present;

            if (previous == NULL)
                matrix->A[*line] = newNode;   
        }
        return 1;
    }   
}

// int accessValue(pMATRIX matrix, int* line, int* column)
// {
//     if (invalidNumber(matrix, line, column))
//         return 0;
//     else
//     {
//         pNODE present = matrix->A[*line];

//         while (present != NULL && present->column < *column)
//             present = present->next;
//         if (present != NULL && present->column == *column)
//             return present->value;
//         return 0;
//     }
// }

void printMatrix(pMATRIX matrix)
{
    printf("\nprinting matrix");
}