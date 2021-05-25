#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"


typedef struct sonegador
{
    int id;
    float dinheiroSonegado;
    char*nome[30];
}Sonegador;


int compararSonegador(void*a,void*b){

    //Forço a troca dos tipos para pode usar no TAD
    //pois como é generico tem q altera o tipo para o desejado
    //cash
 
    int *pa = (int*)a;
    Sonegador *pb = (Sonegador*)b;

    if( pb->id == *pa){
        return true;
    }else{
        return false;
    }

}

void lista(Sonegador* s,Colecao* c ){

    if(c == NULL || c->item == NULL){
        return NULL;
    }

    s = (Sonegador*) pegaPrimeiro(c);

    while (s!=NULL)
    {
        printf("Nome: %s || ID: %d || Dinheiro Sonegado: %.1f\n",s->nome,s->id,s->dinheiroSonegado);
        s = (Sonegador*)pegaProximo(c);
    }


}


/*
1- toda funçao que estao com void* na frente dela quando se vai usar ela precisar fazer a mundaça forçada
de tipo de variavel    
    exemplo 
    x = (int*)buscaImplacavel(todos os seus parametros);

*/

int main(){

    Colecao*c;
    Sonegador*s;
    Sonegador*aux;


    int i,r,id,quant,SN,cId=0;
    int tem=0;
    int qntColl;
    int escolhido;
    int dnv = 1;
    int guard;

    //criaçao da colecao

    s = (Sonegador*)malloc(sizeof(Sonegador));
    if(s==NULL){
        return -1;
    }
    aux = (Sonegador*)malloc(sizeof(Sonegador));
    if(aux==NULL){
        return -1;
    }

    while(1){

        if(dnv == 1){
            printf("Criar Lista com com sonegadores\n");
            printf("Qual o tamanho da lista:");
            scanf("%d", &qntColl);
            c = Criacao(qntColl);
            if(c == NULL){
                printf("Erro na alocacao.\n");
                return 0;
            }
            dnv = 0;
        }

        printf("1 - Inserir Meliante\n");
        printf("2 - Procura na lista\n");
        printf("3 - Remover\n");
        printf("4 - Lista todos meliantes cadastrados\n");
        printf("5 - Apagar toda as provas\n");
        printf("0 - Sair\n");

        scanf("%d",&escolhido);


        if(escolhido == 0){
            return 0;
        }

        //inserir sonegadores
        if(escolhido == 1){

            while (1){
                if(c->numItens > 0 ){
                    s = (Sonegador*)malloc(sizeof(Sonegador)*c->numItens);
                    if(s == NULL){
                        printf("ERRO NA ALOCACAO.");
                        return -1;
                    } 
                }
                printf("\n");
                cId++;
                s->id = cId;

                printf("Nome do meliante: ");
                scanf("%s",&(s->nome));
                printf("Quanto ele sonegou?: ");
                scanf("%f",&(s->dinheiroSonegado));
                
                if(inserir(c,(void*)s)){
                    printf("%s foi cadatrador com sucesso seu ID e %d.\n\n",s->nome, s->id);
                    
                    printf("Deseja inserir outro sonegador? Sim[1] Nao[0]");
                    scanf("%d",&SN);
                    if(SN == 0){
                        break;
                    }             
                }else{
                    printf("Error na insercao tente novamente.\n\n");
                }


            }
        }
        
        //procurar na lista
        if(escolhido == 2){
            if(c->numItens == 0){
                printf("Nao nenhum meliante cadastrado");
                break;
            }

            while (1)
            {

                printf("Qual deseja Procurar (Digite seu ID): ");
                scanf("%d",&id);

                if(id <= 0 ){
                    printf("Esse ID nao existe.\n\n");
                }else{

                    aux = s;
                    s = (Sonegador*)buscaImplacavel(c,(void*)&id, compararSonegador);
                    if(s == NULL){
                        printf("Esse ID nao existe.\n");
                        s = aux;
                    }else{                
                        printf("nome: %s \nsonegou: %.1f\n",s->nome,s->dinheiroSonegado);
                    }

                }

                printf("Deseja procurar outro sonegador? Sim[1] Nao[0]");
                scanf("%d",&SN);
                if(SN == 0){
                    break;
                }
            }
        }    

        //remover
        if(escolhido == 3){
            
            if(c->numItens == 0 ){
                printf("Lista vazia nenhum sonegador cadastrador.\n\n");
            }

            while (1)
            {

                printf("Qual Sonegador gostaria de Remover(Digite seu ID): ");
                scanf("%d",&id);
                
                if(id <= 0 ){
                    printf("Esse ID nao existe.\n\n");
                }
                aux = s;
                s = remover( c, (void*) &id ,compararSonegador);
                
   
                if(s == c->item){
                    printf("Esse ID nao existe.\n\n");
                    s = aux;
                }else{
                    printf("A %s que sonegou %.1f foi removido.\n",s->nome,s->dinheiroSonegado);      

                }

                printf("Deseja remover outro sonegador? Sim[1] Nao[0]: ");
                scanf("%d",&SN);
                if(SN == 0){
                    break;
                }

            }

        }

        //lista sonegadores
        if(escolhido == 4){
            if(c->numItens != 0){
                printf("\nEssa e a lista dos sonegadores cadastrado ate agora:\n");
                //listando os itens que estao em c
                lista(s,c);
                printf("\n");
            }else{
                printf("Lista vazia nenhum sonegador cadastrador.\n\n");
            }    
        }
        //apagar todas as provas
        if(escolhido == 5){
            
            if(c->numItens == 0 ){
                printf("Lista vazia nenhum sonegador cadastrador.\n\n");
            }

            printf("Gostaria de destruir todas as provas? Sim[1] Nao[0] :");
            scanf("%d",&SN);
            if(SN){

                removerTodasAsProvas(c);

                if(autoDestruicao(c)){
                    printf("Todas as provas foram apagadas\n");
                    printf("!!AVISO!! A lista de sonegadores foi apagar\n");
                    dnv = 1;
                }else{
                    printf("Ocorre um erro\n");
                }
                //printf("%d\n",c->numItens);
            }

        }


    }

}