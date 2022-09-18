#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

//estrutura de data
struct data{
  int dia;
  int mes;
  int ano;
};
//estrutura de aluno
struct aluno{
  char nome[30];
  struct data dataNasc;
  int ra;
  float notas[3];
  int freq;
};

//declaração dos métodos que serão utilizados;
void imprimeMenu();
void insereAluno(struct aluno[], int);
int removeAluno(struct aluno[], int, int);
void listaAluno(struct aluno[], int);
void buscaAluno(struct aluno[], int, int);
int buscaRA(struct aluno *, int, int);
void movimentacao(struct aluno[], struct aluno[], int, int);

int main() {

  struct aluno turmaAED[50]; //criando uma turma com 50 vagas

  int tamanhoDaClasse = 0, op = 0, RAbusca, remocao, raDeRemocao;

  while(op != 5) { //laço while que exibe o menu no final de cada operação requisitada pelo usuário

    imprimeMenu();
    printf("\nOpcao: ");
    scanf("%i", &op);

    switch(op) {
      case 1:

        insereAluno(turmaAED, tamanhoDaClasse);
        tamanhoDaClasse++; //incrementando o número de alunos, uma vez que um novo aluno foi adicionado na turma.
        break;

      case 2:

        printf("\nQual aluno deseja remover? Digite o RA (apenas numeros): ");
        scanf("%i", &raDeRemocao);

        remocao = removeAluno(turmaAED, tamanhoDaClasse, raDeRemocao);

        if(remocao == 1) {
          printf("\nRemocao feita com sucesso.");
          tamanhoDaClasse--;
        }
        if(remocao == 0) {
          printf("\nAluno nao encontrado para remocao, tente novamente.");
        }
        break;

      case 3:

        listaAluno(turmaAED, tamanhoDaClasse);
        break;
      case 4:

        printf("Qual aluno deseja buscar? Digite o RA (apenas numeros):");
        scanf("%i", &RAbusca);
        buscaAluno(turmaAED, RAbusca, tamanhoDaClasse);
        break;
      case 5:

        printf("\nObrigado. Saindo do programa...");
        break;
        
      default:
      
        printf("\nOpcao invalida.");
        break;
    }
  }

  return 0;
}

void imprimeMenu() {
  printf("\n1 - Inserir aluno");
  printf("\n2 - Remover aluno");
  printf("\n3 - Listar alunos");
  printf("\n4 - Buscar aluno");
  printf("\n5 - Sair.");
  
};

void insereAluno(struct aluno turma[],int n) {

  int verificacaoRA, raDigitado;
    
  getchar();
    printf("RA: ");
    scanf("%i", &raDigitado);
    verificacaoRA = buscaRA(turma, n, raDigitado); //utilizando o método de busca do RA para saber se o aluno já está inserido na turma
    
    if (verificacaoRA == -1){
    
      turma[n].ra = raDigitado;
      printf("Nome: ");
      getchar();
      fgets(turma[n].nome,sizeof(turma[n].nome),stdin);
      turma[n].nome[strlen(turma[n].nome)-1] = '\0';
      printf("Data de Nascimento\n");
      printf("Dia: ");
      scanf("%i",&turma[n].dataNasc.dia);
      printf("Mes: ");
      scanf("%i",&turma[n].dataNasc.mes);
      printf("Ano: ");
      scanf("%i",&turma[n].dataNasc.ano);
      
      for(int i=0;i<3;i++){

        printf("Nota %i: ",i+1);
        scanf("%f",&turma[n].notas[i]);
      }

      printf("Frequencia: ");
      scanf("%i",&turma[n].freq);
    }
    else{
    
      printf("\nEste RA ja existe. Tente novamente");
    }
    
};

void listaAluno(struct aluno turma[], int tamanhoDaClasse) {

  if(tamanhoDaClasse != 0) { //tamanhoDaClasse == 0 significaria sala vazia e, portanto, não há nada para listar.

    for(int i = 0; i < tamanhoDaClasse; i++) {

      if(turma[i].ra != 0) { //Um RA igual a 0 indica o um espaço vazio (sempre no final do vetor turma).

        printf("\n\nNome: %s\n",turma[i].nome);
        printf("Data de Nascimento:   %i/%i/%i\n",turma[i].dataNasc.dia,turma[i].dataNasc.mes,turma[i].dataNasc.ano);
        printf("RA: %i\n",turma[i].ra);

        for(int j = 0; j < 3; j++) {

          printf("Nota %i: %.2f\n",j+1,turma[i].notas[j]);
        }

        printf("Frequencia: %i\n",turma[i].freq);
      }      
    }
  }else{
  
    printf("\n A sala esta vazia!");
  }
  
};

int removeAluno(struct aluno turma[], int tamanhoDaClasse, int raBusca) {
  int posicaoDoAluno, i, opcaoDeMovimentacao = 0;
  struct aluno aux[1];

  posicaoDoAluno = buscaRA(turma, tamanhoDaClasse, raBusca); //método de busca pelo RA sendo chamado para sabermos em qual posição se encontra o aluno a ser excluído

  if(turma[posicaoDoAluno].ra != raBusca) {

    return 0;
  }
  else {
    opcaoDeMovimentacao = 1;

    movimentacao(aux, turma, posicaoDoAluno, opcaoDeMovimentacao);

    opcaoDeMovimentacao++;
    for (i = posicaoDoAluno; i <= tamanhoDaClasse -1; i++) {

      movimentacao(turma, turma, posicaoDoAluno, opcaoDeMovimentacao);
    }

    opcaoDeMovimentacao++;
    movimentacao(turma, turma, posicaoDoAluno, opcaoDeMovimentacao);
       
    return 1;
  }
};

void buscaAluno(struct aluno turma[], int RAbusca, int tamanhoDaClasse) {

  int aux = 0;

  for(int i=0; i<tamanhoDaClasse; i++) {
    if(turma[i].ra == RAbusca && aux == 0) {
      printf("Aqui estao as informacoes do aluno que voce buscou:");
      printf("\n\nNome: %s\n",turma[i].nome);
      printf("Data de Nascimento:   %i/%i/%i\n",turma[i].dataNasc.dia,turma[i].dataNasc.mes,turma[i].dataNasc.ano);
      printf("RA: %i\n",turma[i].ra);
      for(int j=0;j<3;j++) {
        printf("Nota %i: %.2f\n",j+1,turma[i].notas[j]);
      }
      printf("Frequencia: %i\n",turma[i].freq);
      aux++;
    }
  }

  if(aux==0) {
    printf("\nnao foi possivel encontrar o aluno. Tente novamente.\n");
  }
};

int buscaRA(struct aluno turma[], int tamanhoDaClasse, int raDigitado) {

  for (int i = 0; i < tamanhoDaClasse; i++){
  
    if (turma[i].ra == raDigitado){
    
      return i;
    }

  }

  return -1;
}

void movimentacao(struct aluno receptor[], struct aluno fonte[], int posicaoDoAluno, int opcaoDeMovimento) {

  switch (opcaoDeMovimento){
  
    case 1:

      strcpy(receptor[0].nome, fonte[posicaoDoAluno].nome);
      receptor[0].ra = fonte[posicaoDoAluno].ra;
      receptor[0].dataNasc.dia = fonte[posicaoDoAluno].dataNasc.dia;
      receptor[0].dataNasc.mes = fonte[posicaoDoAluno].dataNasc.mes;
      receptor[0].dataNasc.ano = fonte[posicaoDoAluno].dataNasc.ano;

      for(int i = 0; i < 3; i++) {
        receptor[0].notas[i] = fonte[posicaoDoAluno].notas[i];
      }

      receptor[0].freq = fonte[posicaoDoAluno].freq;

      break;

    case 2:

      strcpy(receptor[posicaoDoAluno].nome, fonte[posicaoDoAluno+1].nome);
      receptor[posicaoDoAluno].ra = fonte[posicaoDoAluno+1].ra;
      receptor[posicaoDoAluno].dataNasc.dia = fonte[posicaoDoAluno+1].dataNasc.dia;
      receptor[posicaoDoAluno].dataNasc.mes = fonte[posicaoDoAluno+1].dataNasc.mes;
      receptor[posicaoDoAluno].dataNasc.ano = fonte[posicaoDoAluno+1].dataNasc.ano;

      for(int i = 0; i < 3; i++) {
        receptor[posicaoDoAluno].notas[i] = fonte[posicaoDoAluno+1].notas[i];
      }

      receptor[posicaoDoAluno].freq = fonte[posicaoDoAluno+1].freq;

      break;

    case 3:
      strcpy(receptor[posicaoDoAluno-1].nome, fonte[0].nome);
      receptor[posicaoDoAluno-1].ra = fonte[0].ra;
      receptor[posicaoDoAluno-1].dataNasc.dia = fonte[0].dataNasc.dia;
      receptor[posicaoDoAluno-1].dataNasc.mes = fonte[0].dataNasc.mes;
      receptor[posicaoDoAluno-1].dataNasc.ano = fonte[0].dataNasc.ano;
      
      for(int i = 0; i < 3; i++) {
        receptor[posicaoDoAluno-1].notas[i] = fonte[0].notas[i];
      }

      receptor[posicaoDoAluno-1].freq = fonte[0].freq;
      break;

    default:

      printf("\nAlgo deu errado, tente novamente.");
      break;
    }
}