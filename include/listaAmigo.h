#ifndef LISTA_AMIGO_H
#define LISTA_AMIGO_H

typedef struct lista_amigo ListaAmigo;

#include "listaPessoa.h"

/*  Inicializa uma lista encadeada de amigos
    input: Nenhum
    output: Lista de amigos
    pré-condição: Nenhuma
    pós-condição: Lista simplesmente encadeada com sentinela (vazia)
*/
ListaAmigo* iniciaListaAmigo();

/*  Insere uma célula amigo em uma lista encadeada de amigos
    input: 
    output: Nenhum
    pré-condição:
    pós-condição:
*/
void insereListaAmigo(ListaAmigo* lista, Pessoa* p); 

/*  Preenche as listas de amigos de todas as pessoas contidas na lista de pessoas
    input: Arquivo txt com as relações de amizade, lista de pessoas em que serão preenchidas as listas de amigos
    output: Nenhum
    pré-condição: 
    pós-condição: 
*/
void preencheListaAmigo(FILE* arq, ListaPessoa* lista_pessoa);

/*  Conta as similaridades de músicas iguais entre uma pessoa e seus amigos e preenche o arquivo similaridades.txt
    input:
    output: Nenhum
    pré-condição:
    pós-condição:
*/
void comparaAmigoPessoa(Pessoa* p, ListaPessoa* repetidos, ListaAmigo* lista_amigos, FILE* arq);


void imprimeListaAmigo(ListaAmigo* lista); //não precisa


/*  Libera toda a memória alocada para uma lista de amigos
    input: Lista de amigos a ser destruída
    output: Nenhum
    pré-condição:
    pós-condição:
*/
void destroiListaAmigo(ListaAmigo* lista);

#endif