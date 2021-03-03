#include "staticStack.h"

//função inicia pilha
void iniciaPilha(pilhaEstatica *pilha) {
      pilha->topo=0;
}//função inicia pilha

//função para verificar se a pilha está vazia
bool estaVazia(pilhaEstatica *pilha) {
      return(pilha->topo == 0);
}//função para verificar se a pilha está vazia

//função para verificar se a pilha está cheia
bool estaCheia(pilhaEstatica *pilha) {
      return(pilha->topo == MAXTAM);
}//função para verificar se a pilha está cheia

//função para empilhar----------------------------------------------------------
void empilha(Objeto item, pilhaEstatica *pilha) {

//if para verificar se a pilha está cheia caso não, execute os comandos
  if(!estaCheia(pilha)){

      pilha->array[pilha->topo] = item;//topo recebe o valor  a ser empilhado
      pilha->topo++;//incrementa topo

      //MENSAGEM DE SUCESSO
      printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      printf(" Numero [%d] Adicionado com Sucesso!\n",item);
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      //MENSAGEM DE SUCESSO

  }else{//else, caso a pilha esteja cheia, exiba erro
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf(" Numero [%d] Nao Adicionado: Pilha Cheia!\n",item);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  }//else, caso a pilha esteja cheia, exiba erro
}//função para empilhar---------------------------------------------------------

//função para desempilhar-------------------------------------------------------
void desempilha(Objeto *item, pilhaEstatica *pilha) {

//if para verificar se a pilha está vazia caso não, execute os comandos
    if(!estaVazia(pilha)){

      *item = pilha->array[pilha->topo];//*item recebe valor do topo
      pilha->topo--;//decrementa topo

      //MENSAGEM DE SUCESSO
      printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      printf(" Numero [%d] Removido com Sucesso!\n",*item = pilha->array[pilha->topo]);
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      //MENSAGEM DE SUCESSO

    }else{//caso a pilha esteja vazia, exiba erro
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Impossivel Remover: Pilha Esta Vazia!\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      }//else, caso a pilha esteja vazia, exiba erro
}//função para desempilhar------------------------------------------------------

//função para mostrar o tamanho da pilha
int tamanhoPilha(pilhaEstatica *pilha) {
    return(pilha->topo);
}//função para mostrar o tamanho da pilha

//função para imprimir a pilha--------------------------------------------------
void imprimePilha(pilhaEstatica *pilha) {
  printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Pilha = {");

  for(int i=0;i<pilha->topo;i++){
     printf("%d|", pilha->array[i].chave);
  }//for para percorrer o vetor e imprimir os valores

    printf("}\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

}//função para imprimir a pilha--------------------------------------------------

//Função para Reiniciar a Pilha
void reiniciarPilha(pilhaEstatica *pilha) {

  if(!estaVazia(pilha)){ //if para verificar se a pilha esta vazia
    pilha->topo = 0;

      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      printf("Pilha Resetada com Sucesso!\n");
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  }else{
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      printf("Impossivel: Pilha Vazia!\n");
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }//else
}//função reiniciarPilha

//Menu do Programa
int menu(pilhaEstatica *pilha){
  system("cls");
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("        BRINQUE COM A PILHA ESTATICA!\n");
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

  //TAMANHO DA PILHA
  printf("Tamanho da Pilha: [%d]\n",MAXTAM);

  //quantidade de elementos na pilha
  printf("Quantidade de Elementos na Pilha: [%d] - Elementos\n",tamanhoPilha(pilha));

  //Mostrar elemento do topo sem remoção
  if(!estaVazia(pilha)){
  printf("Elemento no Topo da Pilha: [%d]\n\n",pilha->array[pilha->topo-1]);
}else{
  printf("Elemento no Topo da Pilha: [VAZIA]\n\n");
}//else

//Opções disponíveis
    printf("1 -> Inserir\n");
    printf("2 -> Remover\n");
    printf("3 -> Mostrar Pilha\n");
    printf("4 -> Resetar Pilha\n");
    printf("5 -> Sair\n");

    return 0;
}//Menu do Programa

int main(){

//Criação de variáveis
  int opcao;
  pilhaEstatica p;
  Objeto aux;

//Iniciando a pilha
  iniciaPilha(&p);

//Laço de repetição do programa
do{
//chamando a função menu
  menu(&p);

//lendo opção escolhida pelo usuário
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
             scanf("%d",&aux.chave);
               empilha(aux,&p);
                 system("pause");
                 break;

    case 2: // OPÇÃO PARA DESEMPILHAR NÚMERO NA PILHA
           desempilha(&aux,&p);
            system("pause");
            break;

    case 3: // OPÇÃO PARA IMPRIMIR PILHA
          imprimePilha(&p);
           system("pause");
           break;

    case 4: // OPÇÃO PARA RESETAR PILHA
           reiniciarPilha(&p);
           system("pause");
           break;

    case 5:// OPÇÃO DE SAIDA DO PROGRAMA
         printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
         printf("Obrigado Por Brincar com a Pilha Estatica!\n");
         printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
         exit(1);


    default: // CASO O USUÁRIO ESCOLHA OPÇÕES NÃO EXISTENTES NO MENU
       printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
       printf("Opcao Nao Existente!\n");
       printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
         system("pause");

    }//FIM SWITCH


}while(opcao!=5);//condição de parada WHILE

  return 0;
}// fim da main
