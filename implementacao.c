

#ifndef LISTA_C
#define LISTA_C


#include <stdio.h>
#include <stdlib.h>

//Definição do tipo nó
struct estruturaLista{
    int dado;
    struct estruturaLista *prox;
    
};
typedef struct estruturaLista tipoLista;


//Prototipos das funções

int contando(tipoLista *lst,tipoLista **lst2);
tipoLista* alocaNo(int valor);
void insereFim(tipoLista **lst,int valor);
void imprimeLista(tipoLista *lst);
void manipula(tipoLista **lst, int tam, tipoLista **lista2);

//Função que realiza a alocação de um novo nó
tipoLista* alocaNo(int valor){
    tipoLista *novoNo;
    
    novoNo = novoNo = (tipoLista*) malloc(sizeof(tipoLista));
    if(novoNo){
        novoNo->dado = valor;
        novoNo->prox = NULL;
        
    }
    return novoNo;
    
}



//Função de inserção no fim de uma lista encadeada 
void insereFim(tipoLista **lst,int valor){
    tipoLista *novoNo,*aux;
    novoNo = NULL;
    tipoLista *aux2;
    aux2 = *lst;
    //ponteiro auxiliar sera usado para percorrer a lista
    
    if(*lst == NULL){//se nao tiver nada dentro do vetor ele insere o primeiro valor
        novoNo = alocaNo(valor);//aloca esse valor
        
        *lst = novoNo;//lista estará apontando para esse primeiro valor
        (*lst)->prox =  *lst; 
        //novoNo->prox = *lst;
       // printf("Entrou\n");
    }else{//senão
        novoNo = alocaNo(valor);//senao for o primeiro ele aloca na outra posição
        
        aux = *lst;
        
        //enquanto for diferente de nulo ele vai indo para a proxima
        while((aux->prox) != (*lst)){
            aux = (tipoLista *)aux->prox;
        }
        aux->prox = (tipoLista*)novoNo;//agora como chegou na ultima posicao atual, ele passa a apontar para o proximo valor
        novoNo->prox = *lst;//e esse ultimo valor atual passa apontar para lista
        
    }
    
}



//Função para impressao da lista
void imprimeLista(tipoLista *lst){
    tipoLista *aux;
    aux = lst;
    
    
     //no caso dele ter algum elemento
    if (aux != NULL) {
        //no caso de ter somente um elemento
        if (aux->prox == aux) {
            printf("[%d]",aux->dado);
        } else {//no caso de ter mais de um elemento
            do{//impressoes desses elementos
                printf("[%d]",aux->dado);
                aux = (tipoLista *) aux->prox;
            }while(aux != lst);
        }
    }
    printf("\n");
    
}


int contando(tipoLista *lst,tipoLista **lst2){
    int cont;
    tipoLista *aux;
    aux = lst;
    
    /* Ira realizar a contabilização da quantidade de elementos*/
    //no caso de ter alguma elemento
    if (aux != NULL) {
        //no caso de ter somente um elemento
        if (aux->prox == aux) {
            cont++;
        } else {//no caso de ter mais de um elemento
            do{//impressoes desses elementos
                cont++;
                aux = (tipoLista *) aux->prox;
            }while(aux != lst);
        }
    }
    
    //Após ter a quantidade total de elementos:

    //se o resto da divisao for 0 entao é par e chama a função de manipular os ponteiros
    if(cont%2 == 0){
        printf("Lista com modificação: \n");
        manipula(&lst,cont,lst2); //chama a função de manipular
        printf("Primeira parte: \n");//mostra ate o metade do vetor
        imprimeLista(lst);
        printf("\n\n");
        printf("Segunda parte: \n");//mostra da metade ate o final
        imprimeLista(*lst2);
        printf("\n\n");
    }else{//caso de errado encerra o programa
        printf("Lista com tamanho ímpar :( , tente novamente com um vetor de tamanho par\n");
        exit(1);
    }
    
    
    return cont;
}


//Implementação da função que manipula os ponteiros para subdividir a lista circular
void manipula(tipoLista **lst, int tam, tipoLista **lst2){
    int i;
    i = tam/2;
    tipoLista *aux,*aux2,*aux3;
    aux = *lst;
    
    
    //Modo inteligente:
    int j; 
    for(j = 1; j < i;j++){
        //caminhando ate a posição do meio
        aux = (tipoLista *) aux->prox;
    }
    aux2 = aux->prox; //aux aponta para o do meio
    aux->prox = *lst; //a posição do meio passa a apontar para a primeira posição, assim subdividi o vetor
    
    //lista passa aponta para a posição do meio
    *lst2 = aux2;
    // debug: printf("Valor: %d\n",(*lst2)->dado);   
    while(aux2->prox != (*lst)){
        aux2 = aux2->prox;
    }
    aux2->prox = (*lst2);
    
}

    
#endif 