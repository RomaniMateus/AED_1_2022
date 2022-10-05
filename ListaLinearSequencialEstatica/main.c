#include "ListaLinearSE.h"

int main()
{
    ListaLinearSE lista;
    TipoItem item;
    int i, n, posicaoTeste;

    inicializaLLSE(&lista);

    printf("Número de itens a serem inseridos: ");
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

        if(!insereNoInicioLLSE(&lista,item))
        {
            printf("Erro! Tamanho limite excedido!\n");
            break;
        }

    }

    if(!listaVaziaLLSE(&lista))
    {
        printf("\nItens na lista:\n");
        imprimeListaLLSE(&lista);  
    }
    else
    {
        printf("\nLista Vazia.\n");
    }

    printf("\n***TESTANDO A ADICIONA_NA_POSICAO***\n");
    printf("Item %i\n",i+1);
    printf("Chave: ");
    scanf("%i",&item.chave);
    getchar();
    printf("Nome: ");
    fgets(item.nome,sizeof(item.nome),stdin);
    item.nome[strlen(item.nome)-1] = '\0';
    printf("\nPosicao: ");
    scanf("%i", &posicaoTeste);

    if (!AdicionaNaPosicao(&lista, item, posicaoTeste))
    {
        printf("\nAlgo deu errado!");
    }
    else
    {
        if(!listaVaziaLLSE(&lista))
        {
            printf("\nItens na lista:\n");
            imprimeListaLLSE(&lista);  
        }
        else
        {
            printf("\nLista Vazia.\n");
        }
    
    }
    

    // if(!removeDoFinalLLSE(&lista,&item))
    // {
    //     printf("Erro! Lista Vazia!\n");
    // }
    //     printf("\nItem removido: %i %s",item.chave,item.nome);

    // if(!listaVaziaLLSE(&lista))
    // {
    //     printf("\nItens na lista:\n");
    //     imprimeListaLLSE(&lista);  
    // }
    // else
    // {
    //     printf("\nLista Vazia.\n");
    // }

    // if(!removeDoInicioLLSE(&lista,&item))
    // {
    //     printf("Erro! Lista Vazia!\n");
    // }
    //     printf("\nItem removido: %i %s",item.chave,item.nome);

    // if(!listaVaziaLLSE(&lista))
    // {
    //     printf("\nItens na lista:\n");
    //     imprimeListaLLSE(&lista);  
    // }
    // else
    // {
    //     printf("\nLista Vazia.\n");
    // }

    return 0;
}

