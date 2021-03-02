#include <stdio.h>
#include <stdlib.h>


//FUNÇÃO PARA PREENCHER O VETOR//
void preenche(int tamanho, int *vetor){

  for(int i =0;i<tamanho;i++){
    printf("Digite o numero [%d] do vetor: ",i+1);
      scanf("%d", &vetor[i]);
  }//for
}//fim função preenche


//FUNÇÃO PARA IMPRIMIR O VETOR//
void imprime(int tamanho, int *vetor){

  printf("\n\n");
  for(int i=0;i<tamanho;i++){
    printf("Numero [%d] do VETOR: %d\n",i+1,vetor[i]);
  }//for
}//fim função imprime



int main (){

  int tamanho;
  int *vetor;

  //NOME DO PROGRAMA//
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("     PREENCHENDO E IMPRIMINDO VETOR\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
  //NOME DO PROGRAMA//

  //DEFININDO O TAMANHO DO VETOR//
    printf(" - Digite o tamanho do vetor: ");
      scanf("%d",&tamanho);
        printf("\n");

      //ALOCANDO DINAMICAMENTE O VETOR//
      vetor = (int*)malloc(tamanho * sizeof(int));

      //CHAMANDO FUNÇÕES PARA PREENCHER E IMPRIMIR O VETOR//
      preenche(tamanho,&vetor[0]);
      imprime(tamanho, &vetor[0]);


      //LIBERANDO A MEMÓRIA ALOCADA DINAMICAMENTE PARA O VETOR//
      free(vetor);

  return 0;
}//fim da função main//
