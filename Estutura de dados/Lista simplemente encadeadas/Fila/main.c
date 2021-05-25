#include <stdio.h>
#include <stdlib.h>

typedef struct dados{

    int id;

}Dados;

typedef struct node{

    Dados dados;
    struct node* prox;

}Node;

typedef struct List{

    int tam;
    Node *cabeca,*calda;

}List;


List * creatList(){

    List* lista = (List*)malloc(sizeof(List));

    if(lista == NULL){
        return NULL;
    }

    //INICIALIZANDO AS VARIAVEIS

    lista->tam = 0;
    lista->cabeca = NULL;

    return lista;


}

void inserir(List * inicio, Dados dados){

    Node* node = (Node*)malloc(sizeof(Node));

    if(inicio->cabeca == NULL){
        node->dados = dados;
        node->prox = NULL;
        inicio->cabeca = node;
        inicio->calda = inicio->cabeca;
        inicio->tam++;
    }else{

        node->dados = dados;
        node->prox = NULL;
        inicio->calda->prox = node;
        inicio->calda = inicio->calda->prox;
        inicio->tam++;

    }


}

void removerIni(List *inicio){

    if(inicio == NULL){
        printf("Vazia\n");
    }

    Node* aux = inicio->cabeca;
    inicio->cabeca = aux->prox;
    free(aux);
    inicio->tam--;

}



void mostrar(List *inicio){


    if(inicio == NULL){
        printf("Lista vazia\n");
    }

    Node *pont = inicio->cabeca;

    while(pont != NULL){

        printf("%d ",pont->dados.id);

        pont = pont->prox;
    }

    free(pont);

    printf("\n");

}

int main(){

    List * inicio = creatList();

    Dados dados;
    
    dados.id = 1;
    inserir(inicio,dados);
    dados.id = 2;
    inserir(inicio,dados);
    dados.id = 3;
    inserir(inicio,dados);


    mostrar(inicio);

    // removerIni(inicio);

    // mostrar(inicio);

    return 0;
}