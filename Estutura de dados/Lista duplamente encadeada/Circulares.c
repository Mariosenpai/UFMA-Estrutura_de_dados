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
    Node* calda;

}Lista;

Lista* criarList(){

    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if(lista == NULL){
        return NULL;
    }
    
    lista->cabeca = NULL;
    lista->calda = NULL;

    return lista;

}

int tamList(Lista *l){
    Node *cur;
    int num =0;
    if(l->cabeca == NULL){
        return 0;
    }

    cur = l->cabeca;

    while(cur->prox != l->cabeca){
        num++;
        cur = cur->prox;
    }
    num++;
    return num;


}

int inserir(Lista* l, void*data){

    if(l == NULL){
        return false;
    }
    
    Node* new = (Node*)malloc(sizeof(Node));
    if(new == NULL){
        return false;
    }
    new->dado = data;

    if(l->cabeca == NULL){
        l->cabeca = new;
        l->calda = new;
        return true;
    }else if(l->cabeca->prox == NULL){
        l->cabeca->prox = new;
        l->cabeca->ant = new;
        l->calda = new;
        new->ant = l->cabeca;
        new->prox = l->cabeca;
        return true;
    }else{

        l->cabeca->ant = new;
        new->prox = l->cabeca;
        new->ant = l->calda;
        l->calda->prox = new;
        l->calda = new;
        return true;
    }


}

int inserirAfetSpec(Lista* l, void* chave, int(*cmp)(void*,void*),void*data){

    Node* cur;
    if(l == NULL){
        return -1;
    }
    if(l->cabeca == NULL){
        return -1;
    }

    cur = l->cabeca;

    while(cmp(chave,cur->dado)!= true && cur->prox!= l->cabeca){
        cur = cur->prox;
    }

    if(cmp(chave,cur->dado)){
        Node* new = (Node*)malloc(sizeof(Node));
        new->dado = data;
        new->prox = cur->prox;
        cur->prox = new;
        return true;
    }

    return false;
}

int remover(Lista* l, void* chave, int(*cmp)(void*,void*)){
    
    Node* cur,*prev;
    if(l == NULL || l->cabeca == NULL){
        return false;
    }

    cur = l->cabeca->prox;
    prev = l->cabeca;
    while (cmp(chave,cur->dado)!= true && prev->prox != l->cabeca){
        prev = cur;
        cur = cur->prox;
    }

    if(cmp(chave,cur->dado)){
        void* data = cur->dado;
        prev->prox = cur->prox;
        if(cur == l->cabeca){
            if(cur->prox == cur){
                l->cabeca = NULL;
            }else{
                l->cabeca = cur->prox;
            }
        }
        free(cur);
        return true;

    }

    return false;

}

int numIguais(Lista* l1,Lista*l2, int(*cmp)(void*,void*)){

    if(l1 == NULL || l2 == NULL){
        return -1;
    }
    if(l1->cabeca == NULL || l2->cabeca == NULL){
        return 0;
    }

    int cont = 0;

    Node *cur1,*cur2;
    cur1 = l1->cabeca;

    while (cur1->prox != l1->cabeca){
        cur2 = l2->cabeca;    
        while(cur2->prox != l2->cabeca){
            if(cmp(cur1->dado,cur2->dado) == true){
                cont++;
            }
            cur2 = cur2->prox;
        }
        cur1 = cur1->prox;
    }


    cont++;
    return cont;

}

//nao funcionar a ordem inversa
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

    while (cur1->prox != l1->cabeca){ 
        el1++;
        cur1 = cur1->prox;
    }
    
    Node* c = l2->cabeca;
    while (c->prox != l2->cabeca){ 
        el2++;
        c = c->prox;
    }

    while(cur2->prox != l2->cabeca){
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
    while (cur1->prox != l1->cabeca){ 
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
    Lista* l2 = criarList();

    Aluno a,b,c,d;
    a.id = 1;
    b.id = 2;
    c.id = 3;
    d.id = 4;

    inserir(l,(void*)&a);
    inserir(l,(void*)&b);
    inserir(l,(void*)&c);
    inserir(l,(void*)&d);

    inserir(l2,(void*)&d);
    inserir(l2,(void*)&c);
    inserir(l2,(void*)&b);
    inserir(l2,(void*)&a);

    int n = numIguais(l,l2,compradorListas);

    printf("%d", n);

    return 0;
}