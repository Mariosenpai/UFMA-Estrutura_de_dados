#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0


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
//retorna o dado que o index inserido esta
Node * nodeIndex(List* lista, int index){

    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL){
        return NULL;
    }
    if(index > lista->tam){
        return NULL;
    }

    node = lista->cabeca;

    int i;

    for(i = 0; i < index; i++){
        node = node->prox;
    }

    return node;

}
//retorna o index que o valor inserido esta
int indexNode(List * lista, int valor){

    Node* nodeAux = (Node*)malloc(sizeof(Node));
    if(nodeAux == NULL){
        return NULL;
    }

    if(lista == NULL || lista->tam == 0){
        return NULL;
    }

    nodeAux = lista->cabeca;

    int i;

    for(i = 0; i<lista->tam;i++){
        if(nodeAux->dados.id == valor ){
            return i;
        }
        nodeAux = nodeAux->prox;
    }

    return NULL;

}

int removerIndex(List* lista ,int index){

    Node* node = (Node*)malloc(sizeof(Node));
    Node* ant;
    if(node == NULL){
        return false;
    }

    if(lista->cabeca == NULL || lista == NULL){
        return false;
    }

    node = lista->cabeca;
    ant = node;
    int i;
    
    for(i = 0; i < index; i++){
        ant = node;
        node = node->prox;
    }

    Node*aux = node;
    node = aux->prox; // faz ele ser igual ao proximo no(o ele recebe o ponteiro do proximo no como referencia )
    ant->prox = node; // fazendo o anterior a ele aponto para o proximo no  deixando o aux sem referencia
    free(aux);
    lista->tam--;

    return true;

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
    dados.id = 4;
    inserir(inicio,dados);
    dados.id = 5;
    inserir(inicio,dados);
    dados.id = 6;
    inserir(inicio,dados);
    dados.id = 7;
    inserir(inicio,dados);



    mostrar(inicio);
    
    printf("%d\n", nodeIndex(inicio,1)->dados.id);
    printf("%d\n", indexNode(inicio,3));
    removerIndex(inicio,1);
    removerIndex(inicio,1);
    removerIndex(inicio,1);        
    mostrar(inicio);


    // removerIni(inicio);

    // mostrar(inicio);

    return 0;
}