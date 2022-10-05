#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct{
  int chave;
  char nome[50];
} TipoItem;

typedef struct{
  TipoItem itens[MAX];
  int ultimo;
} ListaLinearSE;

int listaVaziaLLSE(ListaLinearSE*);
int listaCheiaLLSE(ListaLinearSE*);
void inicializaLLSE(ListaLinearSE*);
void destroiListaLLSE(ListaLinearSE*);
void imprimeListaLLSE(ListaLinearSE*);
int insereNoFinalLLSE(ListaLinearSE*,TipoItem);
int insereNoInicioLLSE(ListaLinearSE*,TipoItem);
int removeDoFinalLLSE(ListaLinearSE*,TipoItem*);
int removeDoInicioLLSE(ListaLinearSE*,TipoItem*);
int AdicionaNaPosicao(ListaLinearSE *, TipoItem , int);
int RetiraDaPosicao(ListaLinearSE *, int);
int RetiraEspecifico(ListaLinearSE *, int);