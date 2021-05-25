#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"

#define false 0
#define true 1


typedef struct node{
    void *item;
    struct node* prox;
}Node;

typedef struct lista
{
    Node* cur;
    Node* cabeca;

}lseLista;




lseLista* lseCriacao(){

    lseLista * lista =(lseLista*)malloc(sizeof(lseLista));
    if(lista == NULL){
        return NULL;
    }

    lista->cur = NULL;
    lista->cabeca = NULL;
    
    return lista;

}


int lseInserir(lseLista*inicio, void*dados){

    if(inicio == NULL){
        return false;
    }

    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL){
        return false;
    }

    if(inicio->cabeca == NULL){

        node->item = dados;
        node->prox = inicio->cabeca;
        inicio->cabeca = node;
        return true;

    }else{

        node->item = dados;
        node->prox = NULL;

        Node* last = inicio->cabeca;

        while (last->prox != NULL){
            last =last->prox;
        }
        last->prox = node;


        return true;
    }

    return false;

}


int lseDestruir(lseLista*lista){

    if(lista==NULL || lista->cabeca->item == NULL){
        return false;
    }

    if(lseNumList(lista) == 0){
        free(lista->cabeca);
        free(lista);
        return true;
    }

    return false;

}


void* lseBusca(lseLista* lista , void*chave , int(*MI)(void*,void*) ){

    int i;
    Node* node;
    if(node == NULL){
        return NULL;
    }

    if(lista==NULL || lista->cabeca == NULL){
        return NULL;
    }

    node = lista->cabeca;

    if(lseNumList(lista) > 0 ){

        while(node != NULL){
            if( MI(chave, node->item) ){
                return node->item;
            } 
            node = node->prox;   
        }


    }

    return NULL;

}



int lseRemover(lseLista *lista, void* chave ,int(*MI)(void*,void*)){

    if(lista->cabeca == NULL || lista == NULL){
        return false;
    }

    Node* node;
    Node* ant;

    node = lista->cabeca;
    ant = NULL;
    int stat = MI(chave,node->item);

    while(node->prox != NULL && stat != true ){

        ant = node;
        node = node->prox;
        stat = MI(chave,node->item);

    }
    
    if(stat == true ){

        if(ant != NULL){
            ant->prox = node->prox;
        }else{
            lista->cabeca = node->prox;
        }
        free(node);
        return true;
    }

    return false;

}



int lseNumList(lseLista *lista){

    int cont = 0;
    Node* node;
    node = lista;
    if(node == NULL){
        return 0;
    }

    while(node->prox != NULL){
        cont++;
        node = node->prox;   
    }

    return cont;

}


//gets
void* lsepegaPrimeiro(lseLista *lista){

    if(lista == NULL || lista->cabeca == NULL){
        return NULL;
    }

    void* data;
    Node* node = lista->cabeca;

    data = node->item;  
    lista->cur = node->prox;  

    return data;

}

void* lsepegaProximo(lseLista* lista){

    if(lista == NULL || lista->cabeca == NULL){
        return NULL;
    }

    Node* node = lista->cur;
    if(node == NULL ){
        return NULL;
    }
    void* data = node->item;
    lista->cur = node->prox;

    return data;

}


