#include <stdio.h>
#include <stdlib.h>


//TIPO ABSTRATO DE DADOS-------------------------------------------------------
typedef struct{
  char nome_da_banda[70];
  char tipo_de_musica[70];
  int numero_de_integrantes;
  int posicao_do_rank;
} Bandas;

typedef struct{

    Bandas cad[5];

}cadastro;
//TIPO ABSTRATO DE DADOS-------------------------------------------------------


void preencher(cadastro *pb, int tam){

  for(int i=0;i<tam;i++){
    fflush(stdin);
    //INSERIR NOME DA BANDA
        printf("Nome da Banda[%d]: ",i+1);
            gets(pb->cad[i].nome_da_banda);

  //INSERIR ESTILO DA BANDA
        printf("Estilo da Banda[%d]: ",i+1);
            gets(pb->cad[i].tipo_de_musica);

  //INSERIR NUMERO DE INTEGRANTES COM EXIBIÇÃO DE ERRO CASO DIGITE LETRA(TESTANDO ESTUDO)
        printf("Numero de Integrantes da Banda[%d]: ",i+1);
          if(scanf("%d",&pb->cad[i].numero_de_integrantes) !=1){//if erro integrantes
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("        ERRO! DIGITE APENAS NUMEROS\n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
              exit(1);//sair do programa
            }//if erro integrantes

  //INSERIR POSIÇÃO NO RANK COM EXIBIÇÃO DE ERRO CASO DIGITE LETRA(TESTANDO ESTUDO)
        printf("Posicao da banda[%d] no Rank: ",i+1);
          if(scanf("%d",&pb->cad[i].posicao_do_rank) !=1){//if erro ranking
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("        ERRO! DIGITE APENAS NUMEROS\n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
              exit(1);//sair do programa
            }//if erro ranking

        //MENSAGEM DE EXITO NO CADASTRO DA BANDA
          printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=\n");
          printf("               BANDA [%d] CADASTRADA COM SUCESSO!\n",i+1);
          printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=\n\n");

        fflush(stdin);//limpar Buffer do teclado para inserir nova banda
      }//for do cadastro das bandas
}//fim função preencher


//MENU-------------------------------------------------------------------
void menu(){
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("             CADASTRO DE BANDAS\n");
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
}//MENU--------------------------------------------------------------------


void mostrarbandas(cadastro *pb, int tam){

  system("cls");//limpar a tela

  menu();//apresentando menu novamente após limpar a tela

//Menu Bandas Cadastradas
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("             BANDAS CADASTRADAS\n");
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

//for para mostrar bandas cadastradas
    for(int i=0;i<tam;i++){
      printf("Nome da Banda[%d]: %s \n",i+1,pb->cad[i].nome_da_banda);
      printf("Estilo da Banda[%d]: %s\n",i+1,pb->cad[i].tipo_de_musica);
      printf("Numero de Integrantes da Banda[%d]: %d\n",i+1,pb->cad[i].numero_de_integrantes);
      printf("Posicao da banda[%d] no Rank: %d \n",i+1,pb->cad[i].posicao_do_rank);
      printf("\n\n");
    }//for
}//fim da função mostrarbandas

//Função para exibir informações da banda cuja posição no seu ranking é a que foi solicitada pelo usuário.
void selecionar(cadastro *pb,int tam){

  int posrank;//variável que armazena a posição solicitada

//INSERÇÃO DA POSIÇÃO PELO USUÁRIO
  printf("Digite uma posicao do rank [1 - 5] para ver as informacoes da banda correspondente: ");
      scanf("%d",&posrank);

      for(int i=0;i<tam;i++){
          if(posrank == pb->cad[i].posicao_do_rank){
              printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
              printf("        BANDA NA [%d] POSICAO DO RANK\n", posrank);
              printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
                printf("Nome da Banda[%d]: %s \n",i+1,pb->cad[i].nome_da_banda);
                printf("Estilo da Banda[%d]: %s\n",i+1,pb->cad[i].tipo_de_musica);
                printf("Numero de Integrantes da Banda[%d]: %d\n",i+1,pb->cad[i].numero_de_integrantes);
                printf("Posicao da banda[%d] no Rank: %d \n",i+1,pb->cad[i].posicao_do_rank);
                printf("\n\n");
              }//if para verificar a posição no rank
          }//for de verificação das bandas
}//fim da função selecionar


int main (){

  int tam = 5;//Quantidade de bandas possíveis

  cadastro band;//Criação do "vetor de estrutura" BAND


//CHAMANDO FUNÇÕES E PASSANDO ESTRUTURAS POR REFERÊNCIA
  menu();
  preencher(&band,tam);
  mostrarbandas(&band,tam);
  selecionar(&band,tam);

  return 0;
}//fim da função MAIN
