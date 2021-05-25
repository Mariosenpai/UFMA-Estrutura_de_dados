#include <stdio.h>
#include <stdlib.h>

typedef struct dado{
    int dado;
}Dados;

typedef struct no{

    Dados dados;
    struct no *prox;

}No;

typedef struct list{
    int tam;
    No* cabeca;
}List;

List* createList(){

    List* novoNo = (List*)malloc(sizeof(List));
    if( novoNo == NULL){
        return NULL;
    }

    novoNo->cabeca = NULL;
    novoNo->tam = 0;

    return novoNo;

}

void inserir(List* list, Dados dados){

    No* node= (No*)malloc(sizeof(No));
    if(node == NULL){
        return NULL;
    }

    node->dados = dados;
    node->prox = list->cabeca;
    list->cabeca = node;
    list->tam++;


}

void printList(List* list){

    if(list == NULL){
        printf("Pilha vazia\n");
        return;
    }

    No* aux = list->cabeca;

    while(aux != NULL){
        printf("%d ", aux->dados.dado );
        aux = aux->prox;
    }
    printf("\n");

}

void remover(List* list){

    if(list == NULL){
        printf("Pilha vazia\n");
        return;
    }

    No* aux = list->cabeca;
    list->cabeca = aux->prox;
    free(aux);
    list->tam--;


}

int main(){

    List* list = createList();
    Dados d;

    d.dado = 1;
    inserir(list,d);
    d.dado = 2;
    inserir(list,d);
    d.dado = 3;
    inserir(list,d);

    printList(list);

    remover(list);
    
    printList(list);

    return 0;
}