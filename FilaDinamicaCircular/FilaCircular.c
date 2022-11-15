#include "FilaCircular.h"

void inicializaFila(TipoFila *fila){
  fila->n = 0;
  fila->fim = NULL;
}

void destroiFila(TipoFila *fila){
  TipoItem item;
  while(!filaVazia(fila))
    retiraDaFila(fila,&item);
}

int filaVazia(TipoFila *fila){
  return fila->n==0;
}

int insereNaFila(TipoFila *fila,TipoItem item){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh!=NULL){
    if (!filaVazia(fila))
    {
        novoNoh->prox = fila->fim->prox;
        fila->fim->prox = novoNoh;
        fila->fim = novoNoh;
        fila->n++;
        return 1;
    }
    else
    {
        novoNoh->prox = novoNoh;
        fila->fim = novoNoh;
        fila->n++;
        return 1; 
    }
  }

  return 0;
}

int retiraDaFila(TipoFila *fila,TipoItem *item){
  TipoNoh *ptrAux;

  if(!filaVazia(fila)){

    if (fila->n != 1)
    {
        ptrAux = fila->fim->prox;
        fila->fim->prox = ptrAux->prox;

        free(ptrAux);
        fila->n--;
        return 1;
    }
    else
    {   ptrAux = fila->fim;
        fila->fim = NULL;
        free(ptrAux);
        fila->n--;
        return 1;
    }
  }

  return 0;
}

int imprimeFila(TipoFila *fila){
  TipoNoh *ptrAux;
  if(!filaVazia(fila)){
    ptrAux = fila->fim->prox;

    do
    {
        imprimeItem(ptrAux->item);

        ptrAux = ptrAux->prox;

    } while (ptrAux != fila->fim->prox);
    
    return 1;
  }
  return 0;
}

void imprimeItem(TipoItem item){
  printf("%i %s\n",item.chave,item.nome);
}