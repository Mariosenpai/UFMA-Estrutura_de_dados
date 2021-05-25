#include <stdio.h>
#include <stdlib.h>

typedef struct PESSOA{

    char* nome[30];
    int idade;

}PESSOA;

typedef struct PILHA{

    PESSOA pessoa;
    struct PILHA *fim;

}PILHA;

void push(PILHA*inicio, PESSOA novaPessoa){

    if(inicio == NULL){

        inicio = (PILHA*)malloc(sizeof(PILHA));
        inicio->fim = NULL;
        inicio->pessoa = novaPessoa;
        return;

    }else{

        PILHA *temp = (PILHA*)malloc(sizeof(PILHA));
        temp->pessoa = novaPessoa;
        temp->fim = inicio;
        inicio = temp;
        return;

    }

}

PESSOA* TOP (PILHA*inicio){

    if(inicio==NULL){
        return NULL;
    }

    PESSOA *temp = (PESSOA*)malloc(sizeof(PESSOA));
    
    temp = &inicio->pessoa;

    return temp;


}

PESSOA* pop(PILHA*inicio){

    if(inicio == NULL){
        return NULL;
    }

    PILHA *temp = (PILHA*)malloc(sizeof(PILHA));
    temp = inicio;

    inicio =  (inicio)->fim;

    PESSOA *retorno = (PESSOA*)malloc(sizeof(PESSOA));
    *retorno = temp->pessoa;

    free(temp);

    return retorno;


}

int sllNumNodes(PILHA *list ){
    

    if(list == NULL){
        return 0;
    }

    PILHA *temp = (PILHA*)malloc(sizeof(PILHA));
    temp = list;

    int cont = 0;

    while(temp != NULL){
        cont++;
        temp = temp->fim; 
    }
    
    free(temp);

    return cont;
}


int main(){

    PILHA *inicio =  NULL;

    PESSOA exemplo;
    exemplo.idade = 10;
    *exemplo.nome = "mario";

    push(&inicio,exemplo);

    exemplo.idade = 33;
    *exemplo.nome = "LOOL";

    push(&inicio,exemplo);

    int num;
    num = sllNumNodes(inicio);

    printf("%d",num);

    return 0;
}