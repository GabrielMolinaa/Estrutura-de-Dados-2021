#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//TIPOS ABSTRATOS DE DADOS=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
typedef struct NoFila *PtrNoFila;

typedef struct NoFila{
  int valor;
  PtrNoFila proximo;
} NoFila;

typedef struct {
  PtrNoFila inicio;
  PtrNoFila fim;
  int tamanho;
} FilaDinamica;
//TIPOS ABSTRATOS DE DADOS=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void iniciaFila(FilaDinamica *fila){
  fila->inicio = NULL;
  fila->fim = NULL;
  fila->tamanho = 0;
}//iniciar fila

bool estaVazia(FilaDinamica *fila){
     return(fila->tamanho	==	0);
   }//estaVazia

void enfileira(int x, FilaDinamica *fila){

    PtrNoFila Aux;//criando novo nó
    Aux = (PtrNoFila)malloc(sizeof(NoFila));//Alocando memória dinamicamente
    Aux->valor = x;//novo nó recebe valor a ser inserido

//caso for a primeira inserção-->>
    if(estaVazia(fila)){
      fila->inicio = fila->fim = Aux;//Inicio e Fim apontam para AUX
        Aux->proximo = NULL;//Aux proximo aponta para NULL
    }  //se ja existe elementos inseridos -->>
      else{
      Aux->proximo	=	NULL;//Aux proximo aponta para NULL
        fila->fim->proximo = Aux;//fim->proximo aponta para AUX
          fila->fim = Aux;//fim aponta para AUX
      }//else

        fila->tamanho++;//incrementa o contador;

        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("NUMERO [%d] ADICIONADO COM SUCESSO!\n",x);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}//fim enfileira;


int desenfileira(FilaDinamica *fila){

  int temp = -99;//variável auxiliar

  if(!estaVazia(fila)){//se a fila não estiver vazia -->>

      PtrNoFila Aux; // cria um novo nó;
        Aux = fila->inicio;//aux aponta para o inicio;
          fila->inicio = fila->inicio->proximo;//inicio aponta para inicio/prox;
            temp = Aux->valor;//variável recebe o valor que irá ser retirado;
              fila->tamanho--;//decrementa o contador;
                free(Aux);//libera o espaço de memória;

                printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                printf("NUMERO [%d] REMOVIDO COM SUCESSO!\n",temp);
                printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    }else{
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      printf("FILA VAZIA - IMPOSSIVEL REMOVER!\n");
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }//erro caso esteja vazia;

  return(temp);//retorna o valor que foi removido
}//fim desenfileira


void imprimeFila(FilaDinamica *fila){

  PtrNoFila Aux; //cria um novo nó

  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("Fila {");

    for(Aux = fila->inicio; Aux != NULL; Aux = Aux->proximo){
      printf("%i | ",Aux->valor);
    }//for impressão da fila

  printf("}\n");
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}//fim imprime fila

int primeiroElemento(FilaDinamica *fila){
  if(!estaVazia(fila)){//se a fila não estiver vazia, exibe o primeiro elemento
    printf("Primeiro Elemento: [%i] | ", fila->inicio->valor);

  }else printf("Primeiro Elemento: [VAZIA] | ");//se a fila estiver vazia, exibe VAZIA;
  return 0;
}//fim primeiroElemento

int ultimoElemento(FilaDinamica *fila){
  if(!estaVazia(fila)){//caso a fila não esteja vazia, exibe o ultimo elemento
      printf("Ultimo Elemento: [%i]\n\n",fila->fim->valor);

    }else printf("Ultimo Elemento: [VAZIA]\n\n");//se a fila estiver vazia, exibe VAZIA;
  return 0;
}//fim ultimoElemento

void menu(FilaDinamica *fila){

  system("cls");//LIMPAR TELA
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      printf("        BRINQUE COM A FILA DINAMICA\n");
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      printf("N. Elementos: [%i]\n",fila->tamanho);
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
         primeiroElemento(fila);
         ultimoElemento(fila);

        printf("1 -> Enfileirar\n");
        printf("2 -> Desenfileirar\n");
        printf("3 -> Mostrar Fila\n");
        printf("4 -> Reiniciar Fila\n");
        printf("5 -> Sair\n");
}//fim Menu

void destruirFila(FilaDinamica *fila){
  if(estaVazia(fila)){ // caso a fila esteja vazia, ERRO!
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("IMPOSSIVEL: FILA VAZIA!\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  }else{
    //criando nós para resetar a fila
    PtrNoFila Aux;
    PtrNoFila posicao = fila->inicio;

    //enquanto posicao não encontrar NULL, irá executar os comandos
    while(posicao != NULL){
      Aux = posicao; //aux recebe posição
        posicao = posicao->proximo; //posicao passa para o proximo espaço
          free(Aux);//libera o espaço
      }//while

        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("FILA REINICIADA COM SUCESSO!\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }//else
}//fim destruirFila

int main(){

  int opcao, inserir;
  FilaDinamica fd;

  iniciaFila(&fd);

do{
  menu(&fd);

    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Selecione a opcao: ");//lendo a opção do menu
      if(scanf("%d",&opcao) !=1){//if erro caso usuario digite letra
          printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
          printf("        ERRO! DIGITE APENAS NUMEROS\n");
          printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
          break;
}//if erro caso usuario digite letra


  switch(opcao){

    case 1: // OPÇÃO PARA ENFILEIRAR
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
          printf("INSIRA UM NUMERO PARA ENFILEIRAR: ");
            scanf("%d",&inserir);
              enfileira(inserir,&fd);
                system("pause");
                break;

    case 2: // OPÇÃO PARA DESENFILEIRAR
          desenfileira(&fd);
            system("pause");
              break;


    case 3: // OPÇÃO PARA IMPRIMIR FILA
          imprimeFila(&fd);
            system("pause");
              break;

    case 4: // OPÇÃO PARA RESETAR FILA
          destruirFila(&fd);
            iniciaFila(&fd);
              system("pause");
              break;


    case 5:// OPÇÃO DE SAIDA DO PROGRAMA
          printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
          printf("Obrigado Por Brincar com a Fila Dinamica!\n");
          printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            exit(1);


  default: // CASO O USUÁRIO ESCOLHA OPÇÕES NÃO EXISTENTES NO MENU
         printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
         printf("Opcao Nao Existente!\n");
         printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
          system("pause");
        }//switch
  }while(opcao != 5);//while

    return 0;
}//fim main
