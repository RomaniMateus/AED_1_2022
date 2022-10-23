#include ".\GeradorDeSenhas.h"

int main(){
  TipoFila fila;
  TipoCliente cliente;
  int op = 0, i;

  inicializaFila(&fila);

  while(op != 4){
    imprimeMenu();
    printf("\nOpção: ");
    scanf("%i",&op);
    switch(op){

      case 1:
        leDadosCliente(&cliente);
        if(insereNaFila(&fila,cliente))
          printf("\nSenha retirada com sucesso\n");
        else
          printf("\nErro! Nao foi possivel retirar a senha...\n");
        break;

      case 2:
        if(retiraDaFila(&fila))
          printf("\nCliente atendido com sucesso!");
        else
          printf("\nErro! Nao foi possivel atender o cliente!\n");
        
        break;

      case 3:
        if(!filaVazia(&fila)){
          printf("\nFila:\n");
          imprimeFila(&fila);
        }
        else
          printf("\nFila Vazia!\n");
        break;

      case 4:
        destroiFila(&fila);
        printf("\nAté logo!\n");
        break;

      default:
        break;
    }
  }

  return 0;
}