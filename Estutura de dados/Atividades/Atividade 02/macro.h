#include <stdio.h>
#include <stdlib.h>
void MVetor(int elemento, float* vetor){
    int i;
    vetor =(float*)(malloc(elemento * sizeof (float)));
    if (vetor != NULL){
        printf("criado\n");
    }else{
        printf("erro\n");
    }
}  
void Addvetor(int elemento,float* vetor){
    for(int i = 0; i < elemento; i++){     
            printf("valor da posicao[%i]: ",i);
            scanf("%f",&vetor[i]);
        }
}
void PrintV(int elemento, float*vetor){    
    int i;
    for (i = 0 ; i < elemento; i++){
        printf("valor de [%i]: %f \n", i, vetor[i]);
    }

}

float** MMatriz(int linha, int coluna){
    int i;
    float** matriz;
    matriz = (float**) malloc(linha * sizeof(float*));
    if (matriz != NULL){
        for (i=0; i<linha;i++){
            matriz[i]=(float*) malloc(coluna * sizeof(float*));
            if (matriz[i]==NULL){
                printf("f");
            }
        }
        printf("matriz criada com sucesso\n");
    }else{
        printf("nao alocada");
    }
    return matriz;
}

void AddMat(int linha, int coluna, float** matriz){
    int l,k;
    for (l = 0; l < linha; l++){
        for(k = 0; k < coluna; k++){
            printf("valor da posicao[%d][%d]: ",l,k);
            scanf("%f", &matriz[l][k]);
        }
    }
}
void PrintMat(int linha, int coluna, int**matriz){
    int l,k;
    for (l = 0; l < linha; l++){
        for(k = 0; k < coluna; k++){
            printf("valor da posicao[%i][%i]: %i ",l,k,matriz[l][k]);
            printf("\n");
        }
    }
}
void FreeMat(int linha, float**matriz){
    int i;
    for(i=0; i<linha; i++){
        free(matriz[i]);
    }
    free(matriz);
}
int **MultMatrix ( int n, int m, int p, int q, float **ma, float **mb){
    int a,b,c,temp=0;
    //Alocando a matriz resultado
    if(m==p){
        int **Result_Mt;
        Result_Mt = (int**) malloc(n * sizeof(int*));
        if (Result_Mt != NULL){
            for (a = 0; a<n; a++){

                Result_Mt[a]=(int*) malloc(q * sizeof(int*));

            }
        }
        for (a = 0; a<n; a++){
            for (b = 0; b<q; b++){
                for(c = 0; c<m; c++){
                    temp += ma[a][c]*mb[c][b];
                }
                
                Result_Mt[a][b] = temp;
                temp = 0;
            }
        }
        return  Result_Mt;
   }else printf("produto nao existe, o numero de coluna da matriz A eh diferente do numero de linhas da matriz B\n");
}
int CmpVectorMatrix ( int n, int m, int p, float *vet, float **mat){
    for(int q=0; q<n; q++){
        for (int w= 0; w<m;w++){
            for(int e=0;e<p;e++){
                if(vet[q]==mat[w][e]){
                    printf("posicao da matriz[%i][%i] tem valor igual ao vetor[%i] no valor de: %f\n", w,e,q,vet[q]);
                    //printf("\n");
                }
            }
        }
    }
    return 0;
}