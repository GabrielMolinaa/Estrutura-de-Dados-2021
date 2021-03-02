#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//FUNÇÃO PARA VERIFICAR AS VOGAIS//
void verifica(char subs, FILE *arquivo2){

  //VERIFICA SE É VOGAL//
  if(subs == 'A' || subs == 'E' || subs=='I' || subs == 'O'|| subs == 'U'){
    fputc('*',arquivo2);//substitui as vogais por *//
  }else{
    fputc(subs,arquivo2);
  }//IF ELSE//
}//FIM DA FUNÇÃO VERIFICA


int main(){

  char *teste;
  char subs;

  FILE *arq1, *arq2;

    arq1 = fopen("texto.txt", "r");//ARQUIVO QUE SERA LIDO
    arq2 = fopen("saida.txt", "w");//ARQUIVO QUE SERA ESCRITO

  if(arq1==NULL || arq2==NULL){
      printf("Erro de abertura\n");
      exit(1);
  }//verifica se deu erro na abertura do arquivo//

  //WHILE PARA PEGAR CADA CARACTERE DO ARQUIVO 1 E GRAVAR NA STRING SUBS
    while((subs = fgetc(arq1)) != EOF){

      subs = toupper(subs);//DEIXANDO TODAS AS LETRAS MAIÚSCULAS PARA FACILIDAR NA VERIFIÇÃO DA VOGAL

      verifica(subs,arq2);//CHAMANDO A FUNÇÃO QUE VERIFICA AS VOGAIS E SUBSTITUI POR *
  }

  //FECHANDO OS ARQUIVOS//
  fclose(arq1);
  fclose(arq2);


  return 0;
}//fim da função main
