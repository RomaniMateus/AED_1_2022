#include ".\GeradorDeSenhas.h"

void inicializaFila(TipoFila *fila){
  fila->n = 0;
  fila->inicio = NULL;
  fila->fim = NULL;
}

void destroiFila(TipoFila *fila){
  TipoCliente cliente;
  while(!filaVazia(fila))
    retiraDaFila(fila);
}

int filaVazia(TipoFila *fila){
  return fila->n==0;
}

int insereNaFila(TipoFila *fila,TipoCliente cliente){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh!=NULL){
    if(!filaVazia(fila)){
      fila->fim->prox = novoNoh;
    }
    else{
      fila->inicio = novoNoh;
    }
    fila->n++;
    novoNoh->cliente = cliente;
    novoNoh->prox = NULL;
    fila->fim = novoNoh;
    return 1;
  }
  return 0;
}

int retiraDaFila(TipoFila *fila){

  TipoNoh *posicaoDaPrioridade, *aux;
  aux = fila->inicio;

  if (!filaVazia(fila))
  {
    posicaoDaPrioridade = buscaPrioridade(fila);

    if (posicaoDaPrioridade != NULL)
    {
      while (aux->prox != posicaoDaPrioridade)
        aux = aux->prox;
      
      aux->prox = posicaoDaPrioridade->prox;

      free(posicaoDaPrioridade);
      fila->n--;

      return 1;
    }
    else
    {
      posicaoDaPrioridade = fila->inicio;
      fila->inicio = fila->inicio->prox;
      free(posicaoDaPrioridade);

      fila->n--;

      return 1;
    }

  }

  return 0;

}

int imprimeFila(TipoFila *fila){
  TipoNoh *ptrAux;
  if(!filaVazia(fila)){
    ptrAux = fila->inicio;
    while(ptrAux!=NULL){
      imprimeCliente(ptrAux->cliente);
      printf("\n");
      ptrAux = ptrAux->prox;
    }
    return 1;
  }
  return 0;
}

void imprimeCliente(TipoCliente cliente){
  printf("\nNome: %s", cliente.nome);
  printf("\nPrioridade: %d", cliente.prioridade);
  printf("\nSenha: %d", cliente.senha);
}

void imprimeMenu(){
  printf("\nMenu");
  printf("\n1 - Retirar senha");
  printf("\n2 - Atender cliente");
  printf("\n3 - Imprimir fila");
  printf("\n4 - Sair");
}

void leDadosCliente(TipoCliente *cliente){
  printf("\nDados do cliente");
  printf("\nNome: ");
  getchar();
  fgets(cliente->nome,sizeof(cliente->nome),stdin);
  cliente->nome[strlen(cliente->nome)-1] = '\0';

  srand(time(NULL));

  cliente->prioridade = rand() % 2;  
  cliente->senha = rand() % 101;
}

TipoNoh* buscaPrioridade(TipoFila *fila){

  TipoNoh *auxBuscaPrioridade;
  auxBuscaPrioridade = fila->inicio;

  do
  {

    if (auxBuscaPrioridade->cliente.prioridade == 1)
      return auxBuscaPrioridade;
    else
      auxBuscaPrioridade = auxBuscaPrioridade->prox;

  } while (auxBuscaPrioridade != NULL);
  
  return NULL;
}