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

void listar(Sonegador* s,lseLista* lista ){

    if(lista == NULL || lista->cabeca == NULL){
        return NULL;
    }

    s = (Sonegador*) lsepegaPrimeiro(lista);

    while (s!=NULL)
    {
        printf("Nome: %s || ID: %d || Dinheiro Sonegado: %.1f\n",s->nome,s->id,s->dinheiroSonegado);
        s = (Sonegador*)lsepegaProximo(lista);
    }


}

int main(){

    lseLista*lista;
    Sonegador*s;
    Sonegador*aux;


    int i,r,id,quant,SN,cId=0;
    int tem=0;
    int qntColl;
    int escolhido;
    int guard;
    int criarList;

    //criaçao da colecao

    s = (Sonegador*)malloc(sizeof(Sonegador));
    if(s==NULL){
        return -1;
    }
    aux = (Sonegador*)malloc(sizeof(Sonegador));
    if(aux==NULL){
        return -1;
    }

    printf("\nDeseja criar uma LSE(lista simplemente encadeada) de sonegadores [1]-Sim [0]-Nao\n");
    scanf("%d",&criarList);
    if(criarList == 0){
        return 0;
    }

    printf("Lista de Sonegadores Criadar\n\n");
    lista = lseCriacao();
    if(lista == NULL){
        printf("Erro na alocacao.\n");
        return 0;
    }


    while(1){


        printf("1 - Inserir Meliante\n");
        printf("2 - Procura na lista\n");
        printf("3 - Remover\n");
        printf("4 - Lista todos meliantes cadastrados\n");
        printf("5 - Apagar toda as provas\n");
        printf("0 - Sair\n");
        printf("tam = %d\n", lseNumList(lista));

        scanf("%d",&escolhido);


        if(escolhido == 0){
            return 0;
        }

        //inserir sonegadores
        if(escolhido == 1){

            while (1){
     
                s = (Sonegador*)malloc(sizeof(Sonegador));

                printf("\n");
                cId++;
                s->id = cId;

                printf("Nome do meliante: ");
                scanf("%s",&(s->nome));
                printf("Quanto ele sonegou?: ");
                scanf("%f",&(s->dinheiroSonegado));
                
                if(lseInserir(lista,(void*)s)){
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



            while (1)
            {

            if(lseNumList(lista) == 0){
                printf("Nao nenhum meliante cadastrado\n");
                break;
            }

                printf("Qual deseja Procurar (Digite seu ID): ");
                scanf("%d",&id);

                if(id <= 0  ){
                    printf("Esse ID nao existe.\n\n");
                }else{

                    aux = s;
                    s = (Sonegador*)lseBusca(lista,(void*)&id, compararSonegador);
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
            

            while (1)
            {

            if(lseNumList(lista) == 0 ){
                printf("Lista vazia nenhum sonegador cadastrador.\n\n");
                break;
            }

                printf("Qual Sonegador gostaria de Remover(Digite seu ID): ");
                scanf("%d",&id);
                
                if(id <= 0 ){
                    printf("Esse ID nao existe.\n\n");
                }

                if(lseRemover( lista, (void*) &id ,compararSonegador)){
                    printf("O ID %d foi removido com sucesso.\n", id);
                }else{
                    printf("Erro na remocao tente novamente.\n");
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
            if(lseNumList(lista) != 0){
                printf("\nEssa e a lista dos sonegadores cadastrado ate agora:\n");
                //listando os itens que estao em c

                listar(s,lista);

                printf("\n");
            }else{
                printf("Lista vazia nenhum sonegador cadastrador.\n\n");
            }    
        }
        //apagar todas as provas
        if(escolhido == 5){
            

            printf("Gostaria de destruir todas as provas? Sim[1] Nao[0] :");
            scanf("%d",&SN);
            if(SN){


                if(lseDestruir(lista) == false){
                    printf("Lista nao esta vazia porfavor tirer todos os elementos da lista para continua.\n\n");
                }else{
                    printf("Todas as provas foram apagadas\n");
                    printf("!!AVISO!! A lista de sonegadores foi apagar\n");
                    return 0;
                }
                //printf("%d\n",c->numItens);
            }

        }


    }

}