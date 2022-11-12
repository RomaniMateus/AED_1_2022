#include "SparseMatrix.h"

void initializeMatrix(pMATRIX matrix, int line, int column)
{
    matrix->lines = line;
    matrix->columns = column;
    matrix->A = (pNODE*) malloc(line * sizeof(pNODE));

    for (int i = 0; i < line; i++)
        matrix->A[i] = NULL;
}

int invalidNumber(pMATRIX matrix,int line, int column)
{
    return line < 0 || line >= matrix->lines || column < 0 || column >= matrix->columns;
}

void destroyNode(pMATRIX matrix, pNODE previous, pNODE present, int line)
{
    if (previous == NULL)
        matrix->A[line] = present->next;
    else
        previous->next = present->next;

    free(present);
}

int assignValue(pMATRIX matrix, int line, int column, int value)
{
    if (invalidNumber(matrix, line, column))
        return 0;
    else
    {
        
        pNODE previous = NULL;
        pNODE present = matrix->A[line];

        while (present != NULL && present->column < column) //searching for the node
        {
            previous = present;
            present = present->next;
        }

        if (present != NULL && present->column == column) //assigning value to an existing node
        {
            if (value == 0)
                destroyNode(matrix, previous, present, line);
            else
                present->value = value;
        }
        else //assigning value to a non-existing node
        {
            pNODE newNode = (pNODE) malloc(sizeof(NODE));
            newNode->column = column;
            newNode->value = value;
            newNode->next = present;

            if (previous == NULL)
                matrix->A[line] = newNode;   
        }
        return 1;
    }   
}

int accessValue(pMATRIX matrix, int line, int column)
{
    if (invalidNumber(matrix, line, column))
        return 0;
    else
    {
        pNODE present = matrix->A[line];

        while (present != NULL && present->column < column)
            present = present->next;
        if (present != NULL && present->column == column)
            return present->value;
        return 0;
    }
}