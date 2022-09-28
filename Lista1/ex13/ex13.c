#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void verificaStrings(char *, char *);

int main()
{
    char string1[10] = "abcde", string2[10] = "abcde", string3[10] = "abcde", string4[10] = "adecb";
    int resultado1, resultado2;

    verificaStrings(string1, string2);
    verificaStrings(string3, string4);

    return 0;
}

void verificaStrings(char *agulha, char *palheiro)
{
    char *Pagulha, *Ppalheiro;
    int marcador = 0;

    Pagulha = agulha;
    Ppalheiro = palheiro;

    for (int i = 0; i < 10; i++, Pagulha++, Ppalheiro++)
    {
        if (marcador == 1)
        {
            printf("\nstrings sao diferentes.");
            break;
        }
        else
        {
            if(*Pagulha != *Ppalheiro)
            {
                marcador = 1;
            }
        }
        
    }

    if (marcador == 0)
    {
        printf("\nAs strings sao iguais.");
    }
    
    
}