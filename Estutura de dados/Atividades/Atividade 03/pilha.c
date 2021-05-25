#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct pilha{

    int max;
    int top;
    int* data;

}Pilha;

Pilha * criar(int maxItens){

    Pilha * pilha;
    if(maxItens <= 0){
        return NULL;
    }
    if(pilha==NULL){
        return NULL;
    }

    pilha->data = (int*)malloc(sizeof(int)*maxItens);

    if(pilha->data == NULL){
        free(pilha);
    }

    pilha->max = maxItens;
    pilha->top = -1;

    return pilha;


}

int push(Pilha* p , int data ){

    if(p == NULL || p->top > p->max){
        return false;
    }

    p->top++;
    p->data[p->top] = data;

    return true;

}

int pop(Pilha * p){

    if(p == NULL || p->top<0){
        return NULL;
    }   
    int aux;
    aux = p->data[p->top];
    p->top--;
    return aux;
}

int top(Pilha*p){


    if(p == NULL || p->top<0){
        return NULL;
    } 
    int aux = p->data[p->top];

    return aux;

}


int main(){

    Pilha *p = criar(10);

    push(p, 1);
    push(p,2);
    push(p,3);
    push(p,4);

    printf("%d\n", top(p) );
    pop(p);
    printf("%d", top(p) );


}