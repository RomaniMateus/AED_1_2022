#include "ListaLinearED.h"

int listaVaziaLLED(ListaLinearED *lista)
{
  return lista->ultimo==0;
}

void inicializaListaLLED(ListaLinearED *lista)
{
  lista->inicioLista = NULL;
  lista->ultimo = 0;
}

void destroiListaLLED(ListaLinearED* lista)
{
  TipoNoh *ptrAux1, *ptrAux2;

  if(!listaVaziaLLED(lista))
  {
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    while(ptrAux1->prox != NULL)
    {
      free(ptrAux1);
      ptrAux1 = ptrAux2;
      ptrAux2 = ptrAux1->prox;
    }
    
    free(ptrAux1);
  }
  lista->inicioLista = NULL;
  lista->ultimo = 0;
}

void imprimeItemLLED(TipoItem item)
{
  printf("%i %s\n",item.chave,item.nome);
}

void imprimeListaLLED(ListaLinearED *lista)
{
  TipoNoh *ptrAux;
  if(!listaVaziaLLED(lista))
  {
    ptrAux = lista->inicioLista;
    while(ptrAux != NULL)
    {
      imprimeItemLLED(ptrAux->item);
      ptrAux = ptrAux->prox;
    }
  }
}

int insereNoFinalLLED(ListaLinearED *lista,TipoItem item)
{
  TipoNoh *novoNoh, *ptrAux;

  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh != NULL)
  {
    ptrAux = lista->inicioLista;
    if(!listaVaziaLLED(lista))
    {
      while(ptrAux->prox != NULL)
      {
        ptrAux = ptrAux->prox;
      }
      ptrAux->prox = novoNoh;
    }
    else
    {
      lista->inicioLista = novoNoh;
    }
    novoNoh->item = item;
    novoNoh->prox = NULL;
    lista->ultimo++;
    return 1;
  }

  return 0;
}

int insereNoInicioLLED(ListaLinearED *lista,TipoItem item)
{
  TipoNoh *novoNoh;

  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh != NULL)
  {
    novoNoh->item = item;
    novoNoh->prox = lista->inicioLista;
    lista->inicioLista = novoNoh;
    lista->ultimo++;
    return 1;
  }

  return 0;
}

int removeDoFinalLLED(ListaLinearED *lista,TipoItem *item)
{
  TipoNoh *ptrAux1, *ptrAux2;

  if(!listaVaziaLLED(lista))
  {
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    if(ptrAux2 == NULL)
    {
      lista->inicioLista = NULL;
      *item = ptrAux1->item;
      free(ptrAux1);
    }
    else
    {
      while(ptrAux2->prox != NULL)
      {
        ptrAux1 = ptrAux2;
        ptrAux2 = ptrAux2->prox;
      }
      ptrAux1->prox = NULL;
      *item = ptrAux2->item;
      free(ptrAux2);
    }
    lista->ultimo--;
    return 1;
  }

  return 0;
}

int removeDoInicioLLED(ListaLinearED *lista, TipoItem *item)
{
  TipoNoh *ptrAux;

  if(!listaVaziaLLED(lista))
  {
    ptrAux = lista->inicioLista;
    *item = ptrAux->item;
    lista->inicioLista = ptrAux->prox;
    free(ptrAux);
    lista->ultimo--;
    return 1;
  }
  
  return 0;
}

int adicionaNaPosicao(ListaLinearED* lista, TipoItem item, int posicao)
{
  TipoNoh *novoNoh, *ptrAux;
  int count = 1;

  if (posicao > lista->ultimo + 1)
  {
    return 0;
  }
  else
  {
    if (posicao == 1)
    {
      return insereNoInicioLLED(lista, item);
    }   
    
    ptrAux = lista->inicioLista;
    novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));

    novoNoh->item = item;

    if (novoNoh != NULL)
    {
      
      while (count != posicao - 1)
      {
        ptrAux = ptrAux->prox;
        count++;
      }
      
      novoNoh->prox = ptrAux->prox;
      ptrAux->prox = novoNoh;
      lista->ultimo++;
      return 1;
    }
    
    return 0;
  }
}

int retiraDaPosicao(ListaLinearED *lista, TipoItem *item, int posicao)
{
  TipoNoh *ptrAux1, *ptrAux2;
  int count = 1;
  
  ptrAux1 = lista->inicioLista;
  
  if (posicao > lista->ultimo + 1)
  {
    return 0;
  }
  else
  {
    if (posicao == 1)
    {
      return removeDoInicioLLED(lista, item);
    }
    
    while (count != posicao - 1 && ptrAux1->prox !=NULL)
    {
      ptrAux1 = ptrAux1->prox;
      count++;
    }
    
    if (count == posicao - 1)
    {
      ptrAux2 = ptrAux1->prox;
      ptrAux1->prox = ptrAux2->prox;
      free(ptrAux2);
      lista->ultimo--;
      return 1;
    }

    return 0;
  }
  
}