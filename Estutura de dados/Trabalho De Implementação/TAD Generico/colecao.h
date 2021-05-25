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


typedef struct colecao Colecao;

/*
    ***********  CRIAÇAO COMO FUNCIONA *********** 
                        Struct
        antes de tudo precisamos criar um struct(estrutura) que iria armazenar 
        todas as informaçoes da lista inclusive a propria lista
        -primeiro temos o numero de itens q existe na lista
        -segundo o numero maximo de itens 
        -terceiro uma variavel q iria percorrer q seria o "cur"
        -e por ultimo temos a nossa propria lista abstrata que é um vetor de Void*
        para que isso porque o desse void**?
            Estamos mexendo com uma abstraçao ou seja queremos que esse void** seja qualquer coisa
        qualquer tipo de dado que o programado inventou ou nao que funcione em qualquer situação
        Para isso precisamos fazer um vetor de Void* e dentro desse vetor que iria ficar armazenada a lista
        e para que esse lista de fato seja de um tipo especificado pelo usuario, ele precisa usar o cash 
        quer seria a força trocada de tipo de dado transformando esse void** em qualquer outro tipo.

*/

Colecao *Criacao(int maxItens);

/*
    ***********  CRIAÇAO COMO FUNCIONA *********** 
                    Criaçao da lista
    Logo depois da criaçao da coleçao vamos agora criar a primeira funçao dessa TAD que seria a criaçao da mesma
    a unica coisa q precisamos expecifica seria o numero maximo de itens que essa estrutura suportaria
    -temos a criaçao de uma variavel do tipo colecao(que seria a estrutura)
    -temos a alocaçao dinamica dessa estrutura 
    -e temos as declaraçoes de variaveis aonde tudo fica em zero exceto o numero maximo de itens vai se de acordo com o usuario
    -depois de tudo isso a funçao retorna a estrutura 

*/

int inserir(Colecao*c, void*item);

/*
    ***********  CRIAÇAO COMO FUNCIONA *********** 
                  inserir um item
    inserir um item segue uma logica bem simples porem temos q nos atentar a certos aspectos
    -Primeiros a funçao inserir recebe 2 paramentros a colecao que é a estrutura q ta armazenando a lista e um void* item
    esse void* seria o tipo de variavel seja qualquer que o usario esteja mexendo com isso sempre que ele for inserir um item na colecao
    ele teria q transforma esse tipo de dado para um tipo void* usando o cash que ficaria assim inserir(Colecao c, (void*)nome do item)
    assim tranformando esse tipo de dado em um tipo abstrator de dado

    -Segundo colocamos esse item dentro do vetor de void* na posiçao do numero de item que e toda vez aumenta o numero de item assim sabendo
    quantos itens existem na coleçao(lembrando q o numero de itens n pode ser maior que o numero maximo de itens)
    

*/

int autoDestruicao(Colecao*c);

/*
    ***********  CRIAÇAO COMO FUNCIONA *********** 
                    Destruir a lista
    para se destruir essa estrutura de dados criada primeiro precisamos garantir que nao haja 
    nada dentro dessa lista com isso usaramos o numero de itens como referencia o numero de itens teria q ser igual 
    a zero com isso na ha mas nd dentro da lista entao ela pode ser destruida primeiro se da um free no item que seria o void**
    e depois se da free na estrutura que aguardava ela
    

*/

void* buscaImplacavel(Colecao*c , void*chave , int(*MI)(void*,void*) );

/*
    ***********  CRIAÇAO COMO FUNCIONA *********** 
                        Busca
    Ele busca um item que esta dentro da TAD atraves de um funçao que o usuario devera criar 
    
    --------------- funçao a ser criada pelo usario da TAD  ---------------
    -Essa funçao precisa receber dois(2) parametros do tipo void* que a principio seriam 
    Um tipo int(ou float depende do que voce esta querendo comparar) e o tipo de dado criada pelo usuario, 
    em sua declaraçao quando for usar essa funçao Voce precisa fazer o cash transformando seja la qual for 
    o tipo que o usario criou e o que deseja comparar em tipo (void*) dentro da funçao deverar  fazer o cash 
    novamente transformando o tipo de dado criado pelo usario e o tipo que voce deseja comparar Nesse caso estamos trabalhando com int
    com isso voce compara os 2 e return true se for verdadeiro e false se for falso

    tendo essa funçao criada agora podemos usar ela para busca dentro da lista criada qual item deseja achar
    a funçao busca recebe como paramentro 
    - colecao
    - o item que deseja achar (usasse o cash e transforma ele em void* na hora da ultilização da funçao)
    - a funçao criada pelo usario explicada a cima

    - com isso antes de tudo vemos se o itens da lista estao null ou se a colecao esta null
    
    - se existe um item dentro da lista ou seja o numItens for maior q 0 entao a procurar irar acontece

    - haverar um for que vai de  0 ate o numItens e dentro desse for existe um if que so iria entra nele quando a funçao a cima for verdairo
    se for falso é porque nao achou e nisso iria percorrer todos o itens da lista e iriar retorna o c->item[i] na posiçao (i) encontrada 
    
    obs: Uma coisa muito importante como for usar o "buscaImplacavel" lembrasse que ele retorna um void* porem ele deve retorna
    um tipo especificado pelo usario entao em sua delcaraçao deve ouver o cash para funciona corretarmante
    

*/

int remover(Colecao *c, void* chave , int(*MI)(void*,void*) );

/*
    ***********  CRIAÇAO COMO FUNCIONA *********** 
                    Remover da lista
    Remove da lista funciona como o busca na lista e recebe os meus paramentros 
    - colecao 
    - o itens q deseja excluir (usando o cash para (void*))
    -a funçao de comparar

    depois das comparaçoes de existe item dentro da lista e que nada esta vazio

    - haverar um for que vai de 0 ate numItens e dentro desse for haverar um condiçao que seria se ele achou o valor
    em questao 
    - guardo o valor achado em uma variavel 
    - inicio um while i (que seria a posição que foi achada) ate o numItens quer seria o final da lista -1
        pq o menos 1? // "-1" é porque nao queremos ir ate o final o que esse while faz é ir do item encontrada ate o ante penutimo item 
                         e ele vai botando o item posterior na posição anterior com isso se chegasse no final da fila nao teria como bota o ultimo
                        item pq a posição final +1 seria igual a null e daria um erro
    - todo valor q ele acha apartir desse ponto ele bota uma posiçao anterior como ele faz isso?
        ele pega o i+1 e bota no lugar de i

    - no final eu descremendo a variavel q informava a quantidade de itens na lista e returno o valor retirado 

*/

int removerTodasAsProvas(Colecao *c);

/*
    ***********  CRIAÇAO COMO FUNCIONA *********** 
                 Remover todos da lista
    Exatamente igual a remove um itens especifico com tudo nao existe a chave q seria o itens escolhido a ser removido
    e nem o funçao que comparar esse item com a lista portanto eu so preciso passa colecao e retirar todos os itens
    - colecao
    - Cada posiçao que esta na lista eu transformo para null e diminuo o numero de itens ate chegar em zero
    

*/

void* pegaPrimeiro(Colecao *c);

void* pegaProximo(Colecao* c);


/*
    ***********  CRIAÇAO COMO FUNCIONA *********** 
                    Lista itens
    A 2 funçoes abaixo trabalham em conjunto e a primeiro ela bota o "cur" que seria 
    a varaivel que farar com quw a gnt percorer o a lista
    - primeiro de tudo voce tem que começa da posiçao 0 logo o pegar primeiro bota "cur" na posiçao 0 e retorna oq esta la
    - depois tem o pegar proximo que vai incrimentando o "cur" e retornando o valor que esta nele
    - com isso é necessario usar as 2 funçoes e o pegar proximo dentro de um for e ir pritando  tudo que esta na lista

*/

#endif