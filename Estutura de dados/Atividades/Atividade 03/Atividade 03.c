#include <stdio.h>
#include <stdlib.h>


void imprimirMat(int **matt ,int linha, int coluna){
    int i,j;
    for(i = 0; i < linha ;i++){
        for(j = 0; j < coluna;j++ ){
            printf("%d ",matt[i][j]);
        }
        printf("\n");
    }

}

void imprimirVet(int* vetor,int tam){
    int i;
    printf("tamanhao %d\n",tam);
    for(i = 0; i < tam;i++){
        printf("vetor[%d] = %d ,",i,vetor[i]);
    }
    printf("\n");
}

int** alocandoMatrix(int n,int m){
    int i,j,k;
    //Aloca a matriz
    if(n>0 && m>0){
        int** matrizM1 = (int**)malloc(sizeof(int*)*n);
        if(matrizM1!=NULL){
            for(i = 0; i < m;i++){

                matrizM1[i] = (int*)malloc(sizeof(int)*n);

                if(matrizM1[i]==NULL){
                    for(j=i-1; j<=0;j--){
                        free(matrizM1[j]);
                    }
                    return NULL;
                }
            }
            return matrizM1;
        }
    }

    return NULL;

}

int* alocarVet(int* vetor,int tam){

    vetor = (int*)malloc(sizeof(int)*tam);

    if(vetor==NULL){
        printf("Vetor nao alocado");
        return NULL;

    }else{
        return vetor;
    } 
}

int** vetorEmMatrix(int n,int m,int v,int** matriz,int*vetor){

    int i,j,k=0;
                            
    //transformando o vetor em uma matriz n por m    
    if(v == m*n){
        for(i = 0; i < n;i++){
            for(j = 0; j < m;j++){
                matriz[i][j] = vetor[k];
                k+=1;
            }
        }
        return matriz;
    }else{
        printf("O tamanho do vetor nao e igual ao tamanho da matriz\n");
        return NULL;
    }

}

int* matrizEmVetor(int** matriz, int n, int m){
    
    int i,j,k;
    int* vetor = (int*)malloc(sizeof(int)*n*m);
    if(vetor==NULL){
        printf("Error memoria nao alocada");
        return NULL;
    } 

    for(i=0 ; i < n;i++){
        for(j=0; j < m ;j++){
            k = i*m+j;
            vetor[k] = matriz[i][j];
        }
    }

    return vetor;

}

int * MultMat ( int * vma, int *vmb, int n, int m, int p, int q){

    int i,j,k;
    

    if(vma!=NULL && vmb!=NULL){
        if(n>0 || m > 0 || p>0 || q>0){
            return NULL;
        }
        if(m == p){

            //alocando memoria

            int* matrizAux = (int*)malloc(sizeof(int)*n);
            if(matrizAux==NULL){
                return NULL;
            }

            //alocando memoria

            int l,h,t;
            //multiplicaçao das matrizes
            for(i = 0; i < n ;i++){
                for(j = 0; j < m;j++){
                    l=i*m+j;
                    matrizAux[l] = 0;  
                    for(k=0 ; k < m ;k++){
                        t = k*m+j;
                        h = i*m+k;
                        matrizAux[l]+=vma[h]*vmb[t];
                    }
                }

            }
            //multiplicaçao das matrizes

                return matrizAux;
        }
  
        return NULL;
    }

    return NULL;

}

int *TranspostadeMat ( int * vma, int n, int m){

    int i,j,k=0;
    
    if(n<=0 || m<=0){
        return NULL;
    }

    int aux,trans;
    //transposta
    for(i = 0; i < n ;i++){
        for(j = 0; j < m; j++){
            k = i*m+j;
            trans = j*m+i;
            if(i > j){
                aux = vma[k];
                vma[k] = vma[trans];
                vma[trans] = aux;
            }

        }
    }

    return vma;

}

int SomaDaDiagonal ( int * vma, int n, int m, int l){

    int i,j,k;
    int somaElemts=0;
    if(n > 0 && m > 0){
        //alocaçao
        int* elemts = (int*)malloc(sizeof(int)*m);
        if(elemts==NULL){
            return NULL;
        }
        //alocaçao

        k=0; //linha dos elementos
        for(j=0; j < m ;j++){

            k = l*m+j;
            elemts[j] = vma[k];

        }

        for(i=0; i < m ;i++){
            somaElemts += elemts[i];
        }

        return somaElemts;
    }
    return NULL;


}

int ESimetrica ( int *vma, int n, int m){

    int i,j;
    int k,h;
    
    if(n<=0 || m<=0){
        return NULL;
    }

    for(i=0 ;i < n;i++){
        for(j = i+1; j < m;j++){
            k = i*m+j;
            h = j*m+i;
            if(vma[k]!=vma[h]){
                return 0;
            }
        }
    }

    return 1;

}

int *TRainguloSuperiodemat ( int * vma, int n, int m){

    int i,j,k;
    if(n<=0 || m<=0){
        return NULL;
    }
    int* vetor = (int*)malloc(sizeof(int)*( ( (n*m)-n)/2 ) );//a matris toda menos a diagonal principal divido por 2 
                                                            //isso da os elementos do triangulo supeior ou inferior
    if(vetor==NULL){
        return NULL;
    }

    for(i=0; i<n ;i++){
        for(j=0; j < m;j++){

            if( i < j ){
            k = i*m+j;
            vetor[i] = vma[k];
            }

        }
    }

    return vetor;

}

int ElementosDiagonal ( int * vma, int n, int m){

    int i,j,k;

    int elementos = 0 ;
    if(n>0 && m>0){
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){

                if(i == j){
                    k = i*m+j;
                    elementos += vma[k];

                }
            }
        }

        return elementos;
    }
    return NULL;
}

int main(){

    int i,j,k,l,h,temp;
    int cont=0;

    //linhas e colunas da matrizM1
    int n=2,m=2;
    //linha e colunas da matrizM2
    int p=2,q=2;

    //alocando vetor que tem duas matrizes
    int*vetor = (int*)malloc( sizeof(int)*( m*n + p*q ) );

    if(n>0 && m>0 && p>0 && q>0){
        if(vetor!=NULL){    
            for(i = 0 ; i < m*n + p*q ;i++){
                
                if(cont<m*n){
                    printf("Digite o elemento na matriz 1: ");            
                }else{
                    printf("Digite o elemente na matriz 2: ");                          
                }
                
                scanf("%d", &(vetor[i]) );
                cont++;
                k = i;
            }

        }
    }else{
        printf("Error");
        return 0;
    }
    k++;
    //printf("%d\n",k);

    int tamVm1 = k-(p*q); //o tamanho do vetor ate a matrizM1
    int tamVm2 = k - tamVm1 ;// tamanho da matrizM2

    //alocando os vetores
    int* vM1;
    vM1 = alocarVet(vM1,tamVm1);
    int* vM2;
    vM2 = alocarVet(vM2,tamVm2);
    //alocando os vetores


    //atribuindo os valores do vetor principal nos vMs
    for(i = 0; i <tamVm1 ; i++){
        vM1[i] = vetor[i];
    }

    int a=0;
    for(i=tamVm2; i < k  ; i++){
        vM2[a] = vetor[i];
        a++;
    }

    // int** matrizTeste = alocandoMatrix(n,m);
    // matrizTeste = vetorEmMatrix(n,m,tamVm1,matrizTeste,vM1);
    // imprimirMat(matrizTeste,n,m);
    // printf("\n");

    //Letra A
    int *vetorMult;
    vetorMult = MultMat(vM1,vM2,m,n,p,q);
    //imprimirVet(vetorMult,n*m);

    //letra B
    int** matrizTr;
    matrizTr = TranspostadeMat(vM1,n,m);
    //imprimirMat(matrizTr,n,m);

    //Letra C
    int elementos;
    elementos = SomaDaDiagonal(vM1,n,m,l);
   
    //Letra D
    if(ESimetrica(vM1,n,m)){
        printf("e\n");
    }else{
        printf("nao e\n");
    }

    //Letra E
    int * Tsuper;
    Tsuper = TRainguloSuperiodemat(vM1,n,m);
    //imprimirVet(Tsuper,1);

    //Letra F
    int Dprincipal;
    Dprincipal = ElementosDiagonal(vM1,n,m);
    printf("%d",Dprincipal);


    return 0;
}