#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//TAMANHO DA FILA
#define MAXTAM 5


//TIPO ABSTRATO DE DADOS, FILA ESTÁTICA
typedef struct {
  int array[MAXTAM];
  int tamanho;
  int inicio;
  int fim;
} FilaEstatica;

//INICIAR A FILA
void iniciaFila(FilaEstatica *fila){
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
}//inicia fila

bool estaVazia(FilaEstatica *fila){
      return(fila->tamanho == 0);
}//estaVazia

bool estaCheia(FilaEstatica *fila){
    return(fila->tamanho == MAXTAM);
}//estaCheia

int incrementaIndice(int pos){
  return((pos+1) % MAXTAM);
}//incrementaIndice

void enfileira(int x, FilaEstatica *fila){

  if(!estaCheia(fila)){//se a fila não está cheia
      fila->fim = incrementaIndice(fila->fim);//incrementamos o fim
        fila->array[fila->fim] = x;//atribui valor ao fim da fila
          fila->tamanho++;//incrementa o contador

            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("NUMERO [%d] ADICIONADO COM SUCESSO!\n",x);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    }else{
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("FILA CHEIA - NUMERO [%d] NAO PODE SER ADICIONADO!\n",x);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
          }//else caso fila esteja cheia
}//fim enfileira


int desenfileira(FilaEstatica *fila){

  int temp = -99;//variável que irá armazenar valor que será removido

  if(!estaVazia(fila)){//se a fila não estiver vazia

      temp = fila->array[fila->inicio];//temp recebe valor do inicio
        fila->inicio = incrementaIndice(fila->inicio);//incrementa inicio
          fila->tamanho--;//decrementa o contador de elementos

            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("NUMERO [%d] REMOVIDO COM SUCESSO!\n",temp);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
   }else{
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("FILA VAZIA - IMPOSSIVEL REMOVER!\n",temp);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
          }//else

  return (temp);//retorna o valor removido
}//fim desenfileira


void imprimeFila(FilaEstatica *fila){

  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("Fila {");

  int n = fila->tamanho;

    for(int i = 0; i<n; i++){
      int indice = (fila->inicio + i) % MAXTAM;
        printf("%d | ", fila->array[indice]);
      }//for para imprimir fila

    printf("}\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}//fim imprimeFila


int primeiroElemento(FilaEstatica *fila){
  if(!estaVazia(fila)){//se a fila não estiver vazia, exibe o primeiro elemento
    printf("Primeiro Elemento: [%i] | ", fila->array[fila->inicio]);

  }else printf("Primeiro Elemento: [VAZIA] | ");//se a fila estiver vazia, exibe VAZIA;
  return 0;
}//fim primeiroElemento;

int ultimoElemento(FilaEstatica *fila){
  if(!estaVazia(fila)){//caso a pilha não esteja vazia, exibe o ultimo elemento
      printf("Ultimo Elemento: [%i]\n\n",fila->array[fila->fim]);

    }else printf("Ultimo Elemento: [VAZIA]\n\n");//se a fila estiver vazia, exibe VAZIA;
  return 0;
}//fim ultimoElemento;


int menu(FilaEstatica *fila){

  system("cls");//LIMPAR TELA
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      printf("        BRINQUE COM A FILA ESTATICA\n");
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      printf("Capacidade da Fila: [%i] | N. Elementos: [%i]\n",MAXTAM,fila->tamanho);
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        primeiroElemento(fila);
        ultimoElemento(fila);

        printf("1 -> Enfileirar\n");
        printf("2 -> Desenfileirar\n");
        printf("3 -> Mostrar Fila\n");
        printf("4 -> Reiniciar Fila\n");
        printf("5 -> Sair\n");
}//fim Menu


//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
int main(){

    FilaEstatica f;
    int opcao;
    int inserir;

  //INICIA FILA
    iniciaFila(&f);

do{
    menu(&f);

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
                 enfileira(inserir,&f);
                   system("pause");
                   break;

      case 2: // OPÇÃO PARA DESENFILEIRAR
            desenfileira(&f);
              system("pause");
                  break;


      case 3: // OPÇÃO PARA IMPRIMIR FILA
             imprimeFila(&f);
              system("pause");
                  break;

      case 4: // OPÇÃO PARA RESETAR FILA
            iniciaFila(&f);
              printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
              printf("FILA REINICIADA COM SUCESSO!\n");
              printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                system("pause");
                  break;


      case 5:// OPÇÃO DE SAIDA DO PROGRAMA
             printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
             printf("Obrigado Por Brincar com a Fila Estatica!\n");
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
}//função main
