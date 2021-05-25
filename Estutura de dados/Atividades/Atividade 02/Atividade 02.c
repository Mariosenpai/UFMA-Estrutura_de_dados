#include <stdio.h>

void imprimirMat(int **matt ,int  tam){
    int i,j;
    for(i = 0; i < tam ;i++){
        for(j = 0; j < tam;j++ ){
            printf("%d ",matt[i][j]);
        }
        printf("\n");
    }

}

void Addmat(int **matt,int tam){
    int i,j;

    for(i = 0; i < tam ; i++ ){
        for(j = 0 ; j < tam; j++){
            printf("Digite o elemento %d %d :", i,j);
            scanf("%d",&matt[i][j]);
        }
    }

}
//comparar vetor com matriz
int CmpVectorMatrix ( int n, int m, int p, int *vet, int **matt){
    int i,j,k;

    for(i = 0 ;i < n ;i++){
        for(j = 0; j < m ;j++){

            for(k=0; k < p ;k++){
                if(matt[i][j]==vet[k]){
                    printf("%d ",matt[i][j]);
                }
            }

        }
    }

}

int **MultMatrix ( int n, int m, int p, int **ma, int **mb){

    int i,j,k,temp=0;

    //alocando memoria
    int **matt3;
    matt3 = (int**) malloc(sizeof(int*)*p);
    for(i=0; i < p ;i++){
        matt3[i] = (int*) malloc(sizeof(int)*p);
    }
    //alocando memoria

   for(i = 0 ;i < n;i++){
        for(j = 0; j < m;j++){

            for(k = 0; k < p ;k++){   
                temp += ma[i][k]*mb[k][j];
            }
            matt3[i][j] = temp;
            temp = 0;
        }

    }

    return matt3;
}

int main(){

    int i,j,k,tam=3;
    int **matt;
    int **matt2;

    //alocando memoria para a matriz
    matt = (int**) malloc(sizeof(int*)*tam);

    for(i=0; i < tam ; i++){
        matt[i] = (int*) malloc(sizeof(int)*tam);
    }
    //alocando memoria para a matriz

    //alocando matt2
    matt2 = (int**) malloc(sizeof(int*)*tam);

    for(i=0; i < tam ; i++){
        matt2[i] = (int*) malloc(sizeof(int)*tam);
    }
    //alocando matt2

    //aloocando vetor
    int *vetor;
    vetor = (int*) malloc(sizeof(int)*tam);
    //aloocando vetor   

    printf("Add ao matt.\n");
    Addmat(matt,tam);

    printf("Add ao matt2.\n");
    Addmat(matt2,tam);
    //add valores no vetor dinamico
    // for(i = 0; i < tam ;i++){
    //     printf("Digite elemtento do vetor %d :",i);
    //     scanf("%d", &vetor[i]);
    // }
    //add valores no vetor dinamico

    //printando valores do vetor
    // printf("vetor.\n");
    // for(i = 0; i < tam ;i++){
    //     printf("%d ",vetor[i]);
    // }
    // printf("\n");
    //printando valores do vetor


    //primeira matriz
    printf("imprime matt.\n");
    imprimirMat(matt,tam);
    //segunda matriz
    printf("imprime matt2.\n");
    imprimirMat(matt2,tam);

    printf("\nmultiplicacao de matrizes.\n");
    
    int** matt3;

    matt3 = MultMatrix(tam,tam,tam,matt,matt2);

    imprimirMat(matt3,tam);

    return 0;
}
