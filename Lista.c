#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//==============================================================================
//DEFININDO ESTRUTURAS
//==============================================================================
typedef struct NoLista *PtrNoLista;

typedef struct NoLista {
    int elemento;
    PtrNoLista proximo;
} NoLista;

typedef struct {
    PtrNoLista primeiro;
    int tamanho;
} ListaDinamica;


//==============================================================================
// FUNÇÕES UTILIZADAS
//==============================================================================

//iniciaLista;
void iniciaLista(ListaDinamica *lista){

  lista->primeiro = NULL;
  lista->tamanho = 0;
}//iniciaLista;


//estaVazia;
bool estaVazia(ListaDinamica *lista){
    return(lista->tamanho == 0);
}//estaVazia;


//tamanhoLista;
int tamanhoLista(ListaDinamica *lista){
    return(lista->tamanho);
}//tamanhoLista;


//imprime a Lista;
void imprimirLista(ListaDinamica *lista){

    printf("Lista = {");

      PtrNoLista Percorre;

    for(Percorre = lista->primeiro; Percorre != NULL; Percorre = Percorre->proximo){
        printf("%d ", Percorre->elemento);
      }//for para percorrer e imprimir
    printf("}\n");
}//imprimirLista;


//inserir elementos;
void inserirElementos(ListaDinamica *lista, int elemento){

  PtrNoLista Novo; //cria um novo nó

  Novo = (PtrNoLista)malloc(sizeof(NoLista));//aloca memória para o nó
  Novo->elemento = elemento;//atribui o elemento a ser inserido para o nó

  //se a lista estiver vazia e o elemento a ser inserido for menor que o primeiro da lista, insere na primeira posição;
    if(estaVazia(lista) || elemento < lista->primeiro->elemento){

      Novo->proximo = lista->primeiro;
        lista->primeiro = Novo;

    }
    //senão insere após o primeiro elemento;
    else{

      PtrNoLista Aux;//Nó auxiliar

        Aux = lista->primeiro;

          while(Aux->proximo != NULL && elemento > Aux->proximo->elemento){
                Aux = Aux->proximo;
              }//while

                Novo->proximo = Aux->proximo;
                  Aux->proximo = Novo;
    }//else

    lista->tamanho++;
}//InserirElementos


//função para pesquisar elemento na lista;
bool pesquisaLista(ListaDinamica *lista, int consulta){

//caso a lista esteja vazia, retorne falso;
  if(estaVazia(lista))
    return(false);

    PtrNoLista percorre = lista->primeiro;

    //percorre a lista até encontrar o valor consultado;
    while(percorre != NULL && consulta > percorre->elemento){
      percorre = percorre->proximo;
    }//while

    //retorna falso caso o elemento não exista;
    if(percorre == NULL || percorre->elemento > consulta){
      return(false);
    }//if
}//fim função pesquisaLista;


bool Remove(ListaDinamica *lista, int x){

  PtrNoLista percorre = lista->primeiro;
    PtrNoLista aux = NULL;


    if(estaVazia(lista) || percorre->elemento > x){
      return false;
    }
  //percorre a lista até encontrar elemento;
  while(percorre != NULL && percorre->elemento != x){

      aux = percorre;//salvando posição do percorre antes de ir para o próximo;
      percorre = percorre->proximo;
  }//while

  if(percorre == NULL){
    return false;
  }//if não achou o elemento;

  //caso elemento esteja na primeira posição, primeiro aponta para o próximo;
   if(aux == NULL){

      lista->primeiro =  percorre->proximo;
   }else{

     //caso elemento esteja após o primeiro elemento;
    aux->proximo = percorre->proximo;
  }//if

    lista->tamanho--;//decrementa o tamanho da lista
      free(percorre);//libera o nó;
    return (true);
}//fim função remove;


void menu(ListaDinamica *lista){

printf("=======================================================================\n");
printf("              OPERACOES COM A LISTA SINGULARMENTE ENCADEADA\n");
printf("=======================================================================\n");
 printf("Tamanho da Lista = |%d|\n",tamanhoLista(lista));
 imprimirLista(lista);
 printf("=======================================================================\n");
 printf("\n");

  printf("1 - INSERIR ELEMENTOS\n");
  printf("2 - PESQUISAR ELEMENTOS\n");
  printf("3 - REMOVER ELEMENTOS\n");
  printf("0 - SAIR DO PROGRAMA\n");

}



//==============================================================================
//FUNÇÃO MAIN
//==============================================================================

int main(){

ListaDinamica lista;
int opcao,inserir,pesquisa,remove;

  //iniciando a lista;
  iniciaLista(&lista);


do{
      system("cls");
        menu(&lista);

printf("=======================================================================\n");
    printf("Escolha uma opcao: ");
    scanf("%d",&opcao);

    switch(opcao){

//caso opcao = 1 - insira elementos;
      case 1:
printf("=======================================================================\n");
        printf("Escolha um numero para inserir: ");
        scanf("%d",&inserir);
        inserirElementos(&lista,inserir);
printf("=======================================================================\n");
        printf("ELEMENTO |%d| INSERIDO!\n",inserir);
printf("=======================================================================\n");
        system("pause");
            break;
//------------------------------------------------------------------------------

//caso opcao = 2 - pesquise elementos;
      case 2:
printf("=======================================================================\n");
        printf("Digite um numero para pesquisar na lista: ");
        scanf("%d",&pesquisa);

          if(pesquisaLista(&lista,pesquisa)){
printf("=======================================================================\n");
            printf("ELEMENTO ENCONTRADO!\n");
          }else{
printf("=======================================================================\n");
            printf("ELEMENTO NAO ENCONTRADO!\n");
          }
printf("=======================================================================\n");
            system("pause");
              break;
//------------------------------------------------------------------------------

//caso opcao = 3 - remova elementos;
      case 3:
printf("=======================================================================\n");

        if(!estaVazia(&lista)){
          printf("Digite um elemento para remover: ");
            scanf("%d",&remove);

              if(Remove(&lista, remove)){
              printf("=======================================================================\n");
                                  printf("ELEMENTO |%d| REMOVIDO!\n",remove);
              printf("=======================================================================\n");
            }else{
              printf("=======================================================================\n");
                                  printf("ELEMENTO |%d| NAO REMOVIDO!\n",remove);
              printf("=======================================================================\n");
            }//else caso for removido

        }else{//caso lista esteja vazia;
            printf("NAO REMOVIDO - LISTA VAZIA!\n",remove);
  printf("=======================================================================\n");
}//else caso lista esteja vazia;
            system("pause");
            break;
//------------------------------------------------------------------------------

    //caso opcao = 0 - saia do programa;
      case 0:
      exit(1);
//------------------------------------------------------------------------------

    //caso usuario digite opções inválidas;
      default:
          printf("=======================================================================\n");
                    printf("OPCAO INVALIDA!\n");
          printf("=======================================================================\n");
          system("pause");
}//fim switch;
}while(opcao != 0);

  return 0;
}//fim da main
