/*
 * O programa irá receber uma lista encadeada em duas
 * Retorna mensagem de erro caso a lista seja impar
 */
#include <stdio.h>
#include <stdlib.h>


//inclusão do arquivo com as funções
#include "implementacao.c"


//Função principal
int main(){
    
    
    tipoLista *lista;
    lista = NULL;
   
    tipoLista *lista2;
    lista2 = NULL;
    
    //Inserções
    insereFim(&lista,1);
    insereFim(&lista,2);
    insereFim(&lista,3);
    

    /*Chamada da função mostrando se realmente ocorreu tudo certo nas inserções feitas no fim*/
    printf("Lista original: \n");
    imprimeLista(lista);
    printf("\n\n\n");
    

    contando(lista,&lista2);//chamada da função, se der certo ele separa, senão ele encerra o programa
  
    

    return 1;
}