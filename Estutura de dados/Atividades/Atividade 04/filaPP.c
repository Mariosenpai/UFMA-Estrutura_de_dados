
int promover (Fila f, int n){

    if(f!=NULL || f->numElem > f->maxItens-1){
        return false;
    }
    int i = 0;

    int elm = f->elms[f->fim];

    f->elms[f->fim] = NULL;

    while(i < f->maxItens-1){

        if(f->elms[f->fim+i] == f->maxItens-1 ){
            
            //f->fim = (f->fim+1) % maxItens-1;
            
            f->fim+=i;
            if(f->fim == f->maxItens-1){
                f->fim=0;
            }

            if( f->elms[f->fim+n-i] == NULL){

                f->elms[f->fim+n-i] = elm;
                return true;

            }else{
                return false;
            }
        }
        i++;
    }

    if(f->elms[f->fim+n] == NULL){

        f->elms[f->fim+n] = elm;
        f->fim = (f->fim+n)%maxItens-1;
        return true;

    }else{
        return false;
    }
}




int punir (Fila f, int n){

    if(f==NULL || f->numElem > f->maxItens-1){
        return false;
    }
    int i = 0;

    int elm = f->elms[f->inicio];

    f->elms[f->inicio] = NULL;

    while(i < f->maxItens-1){
        
        if(f->fim-i == 0 ){

            f->inicio = f->maxItens-1 - (n-i);

            if(f->elms[f->inicio] == NULL){
                f->elms[f->inicio] = elm;
                return true;
            }else{
                return false;
            }

        }  
        i++;
    }

    if(f->elms[f->inico-n] == NULL){
        f->elms[f->inicio-n] = elm;
        return true;
    }else{
        return false;
    }

}


