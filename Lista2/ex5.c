/* Criar um tipo abstrato de dados que represente uma pessoa, contendo nome, data de
nascimento e CPF. Crie uma variável que é um ponteiro para este TAD (no programa
principal). Depois crie uma função que receba este ponteiro e preencha os dados da
estrutura e também uma uma função que receba este ponteiro e imprima os dados da
estrutura. Finalmente, faça a chamada a esta função na função principal. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int ano;

}dataNascimento;

typedef struct
{
    char nome[50];
    dataNascimento data;
    char CPF[15];

}pessoa;

void preencheDados(pessoa *);
void imprimeDados(pessoa *);

int main()
{
    pessoa pessoaNova,*pPessoa;
    pPessoa = &pessoaNova;

    preencheDados(pPessoa);

    imprimeDados(pPessoa);

    return 0;
}

void preencheDados(pessoa *novaPessoa)
{
    printf("Digite o seu nome: ");
    fgets(novaPessoa->nome,sizeof(novaPessoa->nome), stdin);
    novaPessoa->nome[strlen(novaPessoa->nome) - 1] = '\0';

    printf("\nDigite a data de nascimento");

    printf("\nDia: ");
    scanf("%i", &novaPessoa->data.dia);

    printf("Mes: ");
    scanf("%i", &novaPessoa->data.mes);

    printf("Ano: ");
    scanf("%i", &novaPessoa->data.ano);

    printf("\nPor fim, digite seu CPF (seguindo o padrao XXX.XXX.XXX-XX): ");
    scanf("%s", &novaPessoa->CPF);
}

void imprimeDados(pessoa *pessoaCadastrada)
{
    printf("\nAqui estao suas informacoes\n");
    printf("\nNome: %s", pessoaCadastrada->nome);
    printf("\nData de nascimento: %i/%i/%i", pessoaCadastrada->data.dia, pessoaCadastrada->data.mes, pessoaCadastrada->data.ano);
    printf("\nCPF: %s", pessoaCadastrada->CPF);

}