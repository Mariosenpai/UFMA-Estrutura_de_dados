/*
ifndef serve para  veria ficar se alguma diretiva (#define/expresao contante )esta 
bloqueada e se estiver entao o codigo é bloqueado
para bloquear uma funçao usasse o (#undef)

FUNCIONAMENTO DO IFNDEF
#ifndef (nome qualquer)
#define (o meu nome do ifndef)
        esse #define funcionara como {} e terminaria no 
        #endif
#endif

    basicamente quer dizer se a variavel nao foi definida 
    defina ela com os determinados paramentros evitando incompatibilidade 
    usase o padrao _NOME_H_, essa incompatibilidade é devido as declaraçoes de variaveis serem 
    feitas 2 vezes no programa e para que isso aconteça apenas uma vez usasse esse codigo



    o arquivo .h onde declaramos nossa funçoes seria o precusor do encapsulamento que vermos em orientaçao a objeto  
    onde nao deixando o usuario ver o codigo em se apenas suas declaraçoes e explicaçoes de como funcionam

*/

#ifndef _COLECAO_H_
#define	_COLECAO_H_
#include "colecao.c"


typedef struct node Node;
typedef struct lista lseLista;



lseLista *lseCriacao();

int lseInserir(lseLista*c, void*item);

int lseDestruir(lseLista*c);

void* lseBusca(lseLista*c , void*chave , int(*MI)(void*,void*) );

int lseRemover(lseLista *c, void* chave , int(*MI)(void*,void*) );

int lseNumList(lseLista *lista);

void* lsepegaPrimeiro(lseLista *c);

void* lsepegaProximo(lseLista* c);




#endif