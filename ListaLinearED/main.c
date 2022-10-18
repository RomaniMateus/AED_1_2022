#include "ListaLinearED.h"

int main()
{
  ListaLinearED lista;
  TipoItem item;
  int n, i, posicao;

  inicializaListaLLED(&lista);
  printf("Numeros de itens a serem inseridos: ");
  scanf("%i",&n);
  for(i=0;i<n;i++)
  {
    printf("Item %i\n",i+1);
    printf("Chave: ");
    scanf("%i",&item.chave);
    getchar();
    printf("Nome: ");
    fgets(item.nome,sizeof(item.nome),stdin);
    item.nome[strlen(item.nome)-1] = '\0';
    if(!insereNoFinalLLED(&lista,item))
    {
      printf("\nErro! Não foi possível inserir!\n");
      break;
    }
  }

  if(!listaVaziaLLED(&lista))
  {
    printf("\nLista: \n");
    imprimeListaLLED(&lista);
  }
  else
  {
    printf("\nLista Vazia!\n");
  }

  printf("\n***TESTE DA ADICIONA_NA_POSICAO***\n");
  printf("\nDigite abaixo a chave e o nome do item a ser inserido\n");
  printf("\nChave: ");
  scanf("%i",&item.chave);
  getchar();
  printf("Nome: ");
  fgets(item.nome,sizeof(item.nome),stdin);
  item.nome[strlen(item.nome)-1] = '\0';
  printf("\nQual posicao deseja inserir o item? ");
  scanf("%i", &posicao);

  if (adicionaNaPosicao(&lista, item, posicao))
  {
    printf("\nItem adicionado: %i %s\n",item.chave,item.nome);
    imprimeListaLLED(&lista);
  }
  else
  {
    printf("\nNao foi possivel inserir o item...");
  }
  
  printf("\n***TESTE DA REMOVE_DA_POSICAO***");
  printf("\nDigite a posicao do item a ser removido: ");
  scanf("%i", &posicao);

  if (retiraDaPosicao(&lista, &item, posicao))
  {
    printf("\nItem Removido: %i %s\n",item.chave,item.nome);
    imprimeListaLLED(&lista);
  }
  else
  {
    printf("\nNao foi possivel remover o item...");
  }
  

  // if(removeDoFinalLLED(&lista,&item))
  // {
  //   printf("\nItem Removido: %i %s\n",item.chave,item.nome);
  // }
  // else
  // {
  //   printf("\nLista Vazia!\n");
  // }

  // if(!listaVaziaLLED(&lista))
  // {
  //   printf("\nLista: \n");
  //   imprimeListaLLED(&lista);
  // }
  // else
  // {
  //   printf("\nLista Vazia!\n");
  // }
  
  destroiListaLLED(&lista);

  return 0;
}