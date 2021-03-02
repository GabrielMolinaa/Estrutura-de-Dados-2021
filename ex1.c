#include <stdio.h>
#include <stdlib.h>

//função que converte minutos para horas/minutos
void conversao(int totalMinutos, int *horas, int *resto){

    //Realizando o calculo de horas através dos minutos;
    *horas = totalMinutos/60;

    //Realizando calculo dos minutos que sobraram;
      *resto = totalMinutos % 60;

    //Exibindo Resultado;
      printf("%d horas e %d minutos",*horas,*resto);

}//Fim da função conversao;



int main(){

  //Definindo variáveis;
  int minutos;
  int *horas, *resto;

  //Usuário digita a quantidade de minutos para realizar a conversão em horas/minutos;
    printf("Escreva a quantidade de minutos para converter em horas: ");
      scanf("%d", &minutos);

      //Chamada da função conversao e passagem de dados;
      conversao(minutos,&horas,&resto);

  return 0;
}//Fim função main;
