void * cdllQuery( DLList *l, void *key, int (*cmp)(void *, void *)){
    DLNode *cur; int stat;
    if (l != NULL){
        if (l->first != NULL){
            cur = l->first;
            stat = cmp(key, cur->data);
            while(stat != true && cur->next != l->first){
                cur = cur->next;
                stat = cmp(key, cur->data);
            }
            if (stat == TRUE){
                return cur ->data;
            }
        }
    }
    return NULL;
}

int cdllInsertAfterSpec ( DLList *l, void *key, int (*cmp)(void *, void *), void * data){
    DLNode *cur, *newnode; int stat;
    if (l != NULL){
        if (l->first != NULL){
            cur = l->first;
            stat = cmp(key, cur->data);
            
            while(stat != true && cur->next != l->first){
                cur = cur->next;
                stat = cmp(key, cur->data);
            }
            if (stat == TRUE){
                newnode=(DLnode*)malloc(sizeof(DLnode));
                if(newnode != NULL){
                    newnode->data = data;
                    newnode->next = cur->next;
                    newnode->prev = cur;
                    cur->next->prev = newnode;
                    cur->next = newnode;
                    return TRUE;
                }
            }
        }
    }
    return NULL;
}

void * cdllRemoveSpec (DLList *l, void *key, int (*cmp)(void *, void *)){
     DLNode *cur, *next, *prev; int stat;
    if (l != NULL){
        if (l->first != NULL){
            cur = l->first;
            stat = cmp(key, cur->data);
            while(stat != true && cur->next != l->first){
                cur = cur->next;
                stat = cmp(key, cur->data);
            }
            if (stat == TRUE){
                data = cur->data;
                prev = cur->prev;
                next = cur->next;
                if(cur->next == cur){
                    l->first = NULL;
                }else {
                    prev->next = next;
                    next->prev = prev;
                }
                free(cur);
                return data;
            }
        }
    }
    return NULL;
}

int csllInsertbeforeSpec ( SLList *l, void *key, int (*cmp)(void *, void *), void * data){
    SLNode *cur, *newnode, *prev; int stat;
    if (l != NULL){
        if (l->first != NULL){
            prev = l->first;
            cur = prev->next;
            stat = cmp(key, cur->data);
            while(stat != true && cur->next != l->first){
                prev= cur;
                cur = cur->next;
                stat = cmp(key, cur->data);
            }
            if (stat == TRUE){
                newnode=(SLnode*)malloc(sizeof(SLnode));
                if(newnode != NULL){
                    newnode->data = data;

                    if(cur->next == cur){
                        cur->next = newnode;
                        l->first = newnode;
                        newnode->next = cur;
                    }
                    return TRUE;
                }
            }
        }
    }
    return NULL;
}
