#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//CRIANDO ESTRUTURAS DE NÓPILHA E DA PRÓPRIA PILHA DINAMICA---------------------
typedef struct NoPilha* PtrNoPilha;//PONTEIRO PARA ESTRUTURA NOPILHA

typedef struct NoPilha{
  int valor;
  PtrNoPilha proximo;
} NoPilha;

typedef struct {
  PtrNoPilha topo;
  int tamanho;
} PilhaDinamica;
//CRIANDO ESTRUTURAS DE NÓPILHA E DA PRÓPRIA PILHA DINAMICA---------------------


//DESENVOLVENDO FUNÇÕES BÁSICAS DE OPERAÇÕES COM A PILHA DINAMICA---------------

//função inicia pilha
void iniciaPilha(PilhaDinamica *p){
  p->topo = NULL;
  p->tamanho = 0;
}//função inicia pilha

//função para verificar tamanho da pilha
int tamanho(PilhaDinamica *p){
  return(p->tamanho);
}//função para verificar tamanho da pilha

//função verificando se a pilha está vazia
bool estaVazia(PilhaDinamica *p){
    return(p->tamanho == 0);
}//função verificando se a pilha está vazia

//função para imprimir a pilha
void imprimePilha(PilhaDinamica *p){

  PtrNoPilha imprime;

  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Pilha = {");

    //for para imprimir todos os valores da pilha
    for(imprime = p->topo; imprime != NULL; imprime = imprime->proximo){
       printf("%d|",imprime->valor);
    }//for imprime pilha

    printf("}\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}//função para imprimir a pilha


//função para empilhar(push) valores na pilha
void empilhar(PilhaDinamica *p, int valor) {

    //passo 1 - criar novo nó de pilha
    PtrNoPilha Aux;

    //passo 2 - alocar dinamicamente o novo nó
    Aux = (PtrNoPilha)malloc(sizeof(PtrNoPilha));

    //passo 3 - auxiliar recebe valor a ser inserido
    Aux->valor = valor;

    //passo 4 - auxiliar aponta para quem o topo aponta
    Aux->proximo = p->topo;

    //passo 5 - topo aponta para o novo nó
    p->topo = Aux;

    //passo 6 - incrementa a quantidade de elementos na pilha
    p->tamanho++;

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Valor Inserido com sucesso!\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}//função para empilhar valores na pilha


//função para desempilhar(pop) valores na pilha
bool desempilhar(PilhaDinamica *p){

  int v = -99;
  if(!estaVazia(p)){ //verificando se a pilha não está vazia

      //passo 1
      PtrNoPilha Aux;
      //passo 2
      v = Aux->valor;
      //passo 3
      Aux = p->topo;
      //passo 4
      p->topo = Aux->proximo;

      //Mostrar o elemento que foi removido da pilha
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      printf("Elemento removido: %d\n",Aux->valor);
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

      //passo 5 - desalocar memoria
      free(Aux);

      //passo 6
      p->tamanho--;

    }else{ // Caso a pilha esteja vazia apresente ERRO
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      printf("Nao removido: Pilha Vazia!\n");
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      return false;
    }
      return(true);//Retorne TRUE caso a função for executada com sucesso!
}//função para desempilhar(pop) valores na pilha

//Função para acessar o TOPO sem remoção
int topo(PilhaDinamica *p){
  int valor;
  valor = p->topo->valor;
    return(valor);
}//Função para acessar o TOPO sem remoção

//Função para reinicializar a pilha
void limparPilha(PilhaDinamica *p){

  if(estaVazia(p)){ // caso a pilha esteja vazia, ERRO!
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Impossivel: Pilha Vazia!\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  }else{
    //Criando ponteiros AUXILIARES
    PtrNoPilha Aux;
    PtrNoPilha posicao = p->topo;

    //Laço para percorrer a pilha removendo elementos até encontrar NULL
    while(posicao != NULL) {
      Aux = posicao;
        posicao = posicao->proximo;
          free(Aux);
    }//Laço para percorrer a pilha removendo elementos até encontrar NULL

    //exibir mensagem de sucesso caso a função seja executada corretamente!
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Pilha Reinicializada com Sucesso!\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    p->topo = NULL;//Atribuir NULL ao topo novamente!
  }//else
}//Função para reinicializar a pilha

//Menu do Programa
int menu(){
  system("cls");
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("        BRINQUE COM A PILHA DINAMICA\n");
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

    printf("1 -> Inserir\n");
    printf("2 -> Remover\n");
    printf("3 -> Mostrar Pilha\n");
    printf("4 -> Limpar Pilha\n");
    printf("5 -> Sair\n");

    return 0;
}//Menu do Programa

//FUNÇÃO PRINCIPAL--------------------------------------------------------------
int main(){

  //criação variáveis da função MAIN
    PilhaDinamica pilha;
    int opcao;
    int inserir;

  //iniciando a pilha dinamica
    iniciaPilha(&pilha);

  //inicio laço de repetição para execução do programa
    do{
     menu();//Abrindo menu do programa

    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Selecione a opcao: ");//lendo a opção do menu
      if(scanf("%d",&opcao) !=1){//if erro caso usuario digite letra
          printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
          printf("        ERRO! DIGITE APENAS NUMEROS\n");
          printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
          break;
}//if erro caso usuario digite letra

    //switch para opçoes do menu
    switch(opcao){

       case 1: // OPÇÃO INSERIR NÚMERO NA PILHA
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
              printf("Insira um numero para adicionar na pilha: ");
                scanf("%d",&inserir);
                  empilhar(&pilha,inserir);
                    system("pause");
                    break;

       case 2: // OPÇÃO PARA DESEMPILHAR NÚMERO NA PILHA
            desempilhar(&pilha);
              system("pause");
              break;

       case 3: // OPÇÃO PARA IMPRIMIR PILHA
            imprimePilha(&pilha);
              system("pause");
              break;

       case 4: // OPÇÃO PARA RESETAR PILHA
            limparPilha(&pilha);
              system("pause");
              iniciaPilha(&pilha);//NÃO ESQUECENDO DE INICIALIZAR NOVAMENTE :)
              break;

       case 5:// OPÇÃO DE SAIDA DO PROGRAMA
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("Obrigado Por Brincar com a Pilha Dinamica!\n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
              exit(1);


       default: // CASO O USUÁRIO ESCOLHA OPÇÕES NÃO EXISTENTES NO MENU
          printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
          printf("Opcao Nao Existente!\n");
          printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            system("pause");

       }//FIM SWITCH
    }while(opcao != 5);//CONDIÇÃO DE PARADA DO WHILE


  return 0;
}//FUNÇÃO PRINCIPAL-------------------------------------------------------------
