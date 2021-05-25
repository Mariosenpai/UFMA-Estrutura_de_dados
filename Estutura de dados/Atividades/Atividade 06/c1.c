#include <stdio.h>
/*
1 - inserir antes do elemento identificado pela chave
2- corrigir a funçao inserir antes do p-ensimo trantado o caso em que o p-esimo elemento é o primeiro
3- remover um elemento identificado pela chave 
*/
int sllinsertBeforeSpec(Sllist *l, void * data , void * key, int(*cmp)(void*,void*)){
    SLNode *newnode; SLNode * cur; SLNode *prev; int stat;
    if (l != NULL){
        if( l != NULL){
            cur = l->first;
            prev = NULL;
            stat = cmp(key,cur->data);
            while (stat != true && cur->next != NULL){
                prev = cur;
                cur = cur->next;
                stat = cmp(key,cur->data);
            }
            if(stat == true){
                newnode = (SLNode*)malloc(sizeof(SLNode));
                if (newnode != NULL){
                    newnode->data = data;
                    if (prev != NULL){
                        newnode->next = cur;
                        prev->next = newnode;
                        return true;
                    }else{
                        newnode->next= cur;
                        l->first = newnode;
                        return true;
                    }
                }    
            }
        }
    }
    return false;
}

int sllinsertBeforePesimo(Sllist *l, void * data , int p){
    SLNode *newnode; SLNode * cur; SLNode *prev; int i = 0;
    if (l != NULL){
        if( l != NULL){
            cur = l->first;
            prev = NULL;
            while (i<p && cur->next != NULL){
                prev = cur;
                cur = cur->next;
                i++;
            }
            newnode = (SLNode*)malloc(sizeof(SLNode));
            if (newnode != NULL){
                newnode->data = data;
                if (prev != NULL){
                    newnode->next = cur;
                    prev->next = newnode;
                    return true;
                }else{
                    newnode->next= cur;
                    l->first = newnode;
                    return true;
                }
            }
        }
    }

    return false;
}

void* sllremoveSpec(Sllist *l, void * key, int(*cmp)(void*, void*)){
    SLNode *newnode; SLNode * cur; SLNode *prev; int stat, data;
    if (l != NULL){
        if( l-> != NULL){
            cur = l->first;
            prev = NULL;
            stat = cmp(key,cur->data);
            while (stat != true && cur->next != NULL){
                prev = cur;
                cur = cur->next;
                stat = cmp(key,cur->data);
            }
            if(stat == true){
                data= cur->data
                if (prev != NULL){
                    prev->next = cur->next;
                }else{
                    l->first = cur->next;
                }
                free(cur);
                return data;
            }
        }
    }         
    return NULL;
}