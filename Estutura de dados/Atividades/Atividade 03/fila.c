#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct fila{
    int frente;
    int atras;
    int max;
    int* data;
}Fila;

Fila * criar(int max){

    if(max<0){
        return NULL;
    }

    Fila *f = (Fila*)malloc(sizeof(Fila));
    if(f ==  NULL){
        return NULL;
    }

    f->data = (int*)malloc(sizeof(int)*max);
    if(f->data == NULL){
        return NULL;
    }

    f->frente = 0;
    f->atras = -1;
    f->max = max;

    return f;

}

int inserir(Fila* f, int data){

    if(f == NULL || f->atras > f->max){
        return false;
    }

    f->atras++;
    f->data[f->atras] = data;
    
    return true;


}

int remover(Fila* f){

    if(f==NULL || f->atras < 0){
        return false;
    }

    int i;
    
    for(i = f->frente; i<f->atras;i++){
        f->data[i] = f->data[i+1];
    }
    f->atras--;

    return true;

}

int primeiro(Fila* f){

    if(f==NULL || f->atras < 0){
        return false;
    }

    return f->data[f->frente];

}

int main(){

    Fila *f = criar(10);

    inserir(f, 1);
    inserir(f, 2);
    inserir(f, 3);
    inserir(f, 4);    

    printf("%d\n",primeiro(f));
    remover(f);
    printf("%d\n",primeiro(f));

}