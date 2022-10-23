#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000

typedef struct{
  int prioridade;
  int senha;
  char nome[30];
} TipoCliente;

struct noh{
  TipoCliente cliente;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef struct{
  int n;
  TipoNoh *inicio;
  TipoNoh *fim;
} TipoFila;

void inicializaFila(TipoFila*);
void destroiFila(TipoFila*);
int filaVazia(TipoFila*);
int insereNaFila(TipoFila*,TipoCliente);
int retiraDaFila(TipoFila*);
int imprimeFila(TipoFila*);
void imprimeCliente(TipoCliente);
void imprimeMenu();
void leDadosCliente(TipoCliente*);
TipoNoh* buscaPrioridade(TipoFila*);