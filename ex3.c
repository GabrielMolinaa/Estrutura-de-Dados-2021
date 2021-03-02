#include <stdio.h>
#include <stdlib.h>

//Função Recursiva para calcular a potência
float recursao(float x, float y){

//Variável que a função ira retornar como resultado;
  float result;

//Condição de parada da recursividade;
  if(y <= 0){
      return(1);//Retorna 1 caso pare;

  }else{

    //Realizando a recursividade para calcular a potência;
        result = x * recursao(x,y-1);

    //Retorna o resultado
      return (result);

  }//if else
}//fechamento função recursão;


int main(){

  float x,y;//Variáveis dos números a ser calculados;
  float resultado;//Variável para armazenar resultado;


//NOME DO PROGRAMA//
  printf("=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("            CALCULO DE POTENCIA\n");
  printf("=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
//NOME DO PROGRAMA//


//Entrada da base da potência;
    printf("---Digite a base x: ");
      scanf("%f",&x);
        printf("\n");

//Entrada do expoente da potência;
    printf("---Digite o expoente y: ");
      scanf("%f",&y);
        printf("\n");


  //Chamada da função recursiva e passagem dos dados;
    resultado = recursao(x,y);


  //EXIBIÇÃO DO RESULTADO//
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("O Resultado e %.0f\n",resultado);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  //EXIBIÇÃO DO RESULTADO//

  return 0;
}//fim função main;
