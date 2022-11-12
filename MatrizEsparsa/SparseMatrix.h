#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>

struct NODE
{
    int value;
    int column;
    struct NODE* next;
};

typedef struct NODE NODE;

typedef struct NODE* pNODE;

typedef struct
{
    pNODE* A;
    int lines;
    int columns;
} MATRIX;

typedef MATRIX* pMATRIX;

void initializeMatrix(pMATRIX, int, int);
int invalidNumber(pMATRIX, int, int);
void destroyNode(pMATRIX, pNODE, pNODE, int);
int assignValue(pMATRIX, int, int, int);
int accessValue(pMATRIX, int, int);
