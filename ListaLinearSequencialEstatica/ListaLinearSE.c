#include "ListaLinearSE.h"

int listaVaziaLLSE(ListaLinearSE *lista)
{
    return lista->ultimo==0;
}

int listaCheiaLLSE(ListaLinearSE *lista)
{
    return lista->ultimo==MAX;
}

void inicializaLLSE(ListaLinearSE *lista)
{
    lista->ultimo = 0;
}

void destroiListaLLSE(ListaLinearSE *lista)
{
    lista->ultimo = 0;
}

void imprimeListaLLSE(ListaLinearSE *lista)
{

    for(int i=0;i<lista->ultimo;i++)
    {
        printf("%i %s\n",lista->itens[i].chave,lista->itens[i].nome);
    }
}


int insereNoFinalLLSE(ListaLinearSE *lista, TipoItem novoItem)
{
    int pos = lista->ultimo;

    if(!listaCheiaLLSE(lista))
    {
        lista->itens[pos] = novoItem;
        lista->ultimo++;
        return 1;
    }
    else
        return 0;
}

int insereNoInicioLLSE(ListaLinearSE *lista, TipoItem novoItem)
{
    int pos = lista->ultimo;

    if(!listaCheiaLLSE(lista))
    {
        for(int i=pos;i>0;i--)
        {
            lista->itens[i] = lista->itens[i-1];
        }

        lista->itens[0] = novoItem;
        lista->ultimo++;
        return 1;
    }
    else
        return 0;
}

int removeDoFinalLLSE(ListaLinearSE *lista,TipoItem *item)
{
    int pos = lista->ultimo;

    if(!listaVaziaLLSE(lista))
    {
        item->chave = lista->itens[pos-1].chave;
        strcpy(item->nome,lista->itens[pos-1].nome);
        lista->ultimo--;
        return 1;
    }
    else
        return 0;
}

int removeDoInicioLLSE(ListaLinearSE *lista,TipoItem *item)
{
    int pos = lista->ultimo;
    int i;

    if(!listaVaziaLLSE(lista))
    {
        item->chave = lista->itens[0].chave;
        strcpy(item->nome,lista->itens[0].nome);
        for(i=1;i<pos;i++)
        {
            lista->itens[i-1] = lista->itens[i];
        }
        lista->ultimo--;
        return 1;
    }
    else
        return 0;
}

int AdicionaNaPosicao(ListaLinearSE *lista, TipoItem item, int posicao)
{
    int x, posicaoReal = posicao - 1;

    if (posicao > lista->ultimo + 1)
    {
        return 0;
    }
    else
    {
        if (posicao == lista->ultimo + 1)
        {
            return x = insereNoFinalLLSE(lista, item);
        }
        else
        {
            lista->ultimo++;

            for (int i = lista->ultimo; i > 0 ; i--)
            {
                lista->itens[i] = lista->itens[i - 1];
            }
            
            lista->itens[posicaoReal] = item;

            return 1;
        }
        
    }
    
}