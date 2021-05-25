#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true 1

typedef struct node{
    
    struct node *ant;
    struct node *prox;

    void *dado;
}Node;


typedef struct lista{

    Node* cabeca;
    Node* cur;

}Lista;

Lista* criarList(){

    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if(lista == NULL){
        return NULL;
    }
    
    lista->cabeca = NULL;
    lista->cur = NULL;

    return lista;

}

int tamLista(Lista *l){

    if(l == NULL || l->cabeca == NULL){
        return 0;
    }

    Node* lista = l->cabeca;
    int cont = 0;
    while (lista != NULL){

        cont++;
        lista = lista->prox;
    }
    return cont;

}

int inserirInicio(Lista* l, void* dado){

    if(l == NULL){
        return false;
    }

    Node* node = (Node*)malloc(sizeof(Node));

    //inserir no inicio
    node->ant = NULL;
    node->prox = NULL;
    node->dado = dado;
    l->cabeca = node;
    if(l->cabeca != NULL){
        l->cabeca->ant = node;
    }
    l->cabeca = node;

    return true;

}

int inserirFinal(Lista*l,void*dado){
    Node *ant;
    if(l == NULL){
        return false;
    }

    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL){
        return false;
    }

    node->dado = dado;
    node->prox = NULL;

    if(l->cabeca != NULL){
        ant = l->cabeca;
        while(ant->prox != NULL){
            ant = ant->prox;
        }
        ant->prox = node;
        node->ant = ant;

    }else{
        l->cabeca = node;
        node->ant = NULL;
    }

    return true;

}

int remover(Lista *l, void*chave, int(*cmp)(void*,void*)){

    Node *spec,*prev,*next;
    void* data;
    if(l == NULL || l->cabeca == NULL){
        return false;
    }

    spec = l->cabeca;

    while (spec->prox != NULL && cmp(chave,spec->dado) != true){
        spec = spec->prox;
    }

    if(cmp(chave,spec->dado) == true){
        data = spec->dado;
        next = spec->prox;
        prev = spec->ant;

        if(prev != NULL){//se for o primeiro elemento
            prev->prox = next;
        }else{
            l->cabeca = next;
        }

        if(next!=NULL){
            next->ant = prev;
        }
        free(spec);
        return true;

    }
    
    return false;

}

int eInversa(Lista* l1,Lista*l2, int(*cmp)(void*,void*)){

    if(l1 == NULL || l2 == NULL){
        return NULL;
    }
    if(l1->cabeca == NULL || l2->cabeca == NULL){
        return NULL;
    }

    Node *cur1,*cur2;
    Node *ant,*prox,*aux;
    int el1=0, el2 =0;
    cur1 = l1->cabeca;
    cur2 = l2->cabeca;

    Node* c = l2->cabeca;
    while (c != NULL){ 
        el2++;
        c = c->prox;
    }

    while (cur1 != NULL){ 
        el1++;
        cur1 = cur1->prox;
    }


    while(cur2 != NULL){
        ant = cur2;
        aux = cur2->prox;
        cur2->prox = cur2->ant;
        cur2->ant = aux;
        cur2 = aux;
    }

    if(el1 < el2){
        return -1;
    }

    if(el1 > el2){
        return 0;
    }


    cur1 = l1->cabeca;
    while (cur1->prox != NULL){ 
        if(cmp(cur1->dado,ant->dado) == false){
            return 2;
        }
        cur1 = cur1->prox;
        ant = ant->prox;
    }

    return 1;

}




typedef struct aluno{
    int id;
}Aluno;


int comprador(void*a,void*b){

    int *pa = (int*)a;
    Aluno *pb = (Aluno*)b;

    if(pb->id == *pa){
        return true;
    }else{
        return false;
    }

}

int compradorListas(void*a,void*b){

    Aluno *pa = (Aluno*)a;
    Aluno *pb = (Aluno*)b;

    if(pb->id == pa->id){
        return true;
    }else{
        return false;
    }

}


int main(){

    Lista* l = criarList();
    Lista* l1 = criarList();
    int tam = 0;


    Aluno a,b,c,d;
    a.id = 1;
    b.id = 2;
    c.id = 3;
    d.id = 4;

    inserirFinal(l,(void*)&a);
    inserirFinal(l,(void*)&b);
    inserirFinal(l,(void*)&c);
    inserirFinal(l,(void*)&d);

    inserirFinal(l1,(void*)&d);
    inserirFinal(l1,(void*)&c);
    inserirFinal(l1,(void*)&b);
    inserirFinal(l1,(void*)&a);



    int n = eInversa(l,l1,compradorListas);

    printf("%d", n);
    

   
    return 0;
}
