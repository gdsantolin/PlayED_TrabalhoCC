#ifndef LISTA_AMIGO_H
#define LISTA_AMIGO_H

typedef struct lista_amigo ListaAmigo;

#include "listaPessoa.h"

/*  Inicializa uma lista encadeada de amigos
    input: Nenhum
    output: Ponteiro para a lista de amigos
    pré-condição: Nenhuma
    pós-condição: Lista de amigos simplesmente encadeada com sentinela (vazia)
*/
ListaAmigo* iniciaListaAmigo();

/*  Insere uma célula amigo em uma lista encadeada de amigos
    input: A lista de amigos, a pessoa
    output: Nenhum
    pré-condição: Lista de amigos está inicializada e pessoa existe
    pós-condição: Célula amigo inserida na lista de amigos
*/
void insereListaAmigo(ListaAmigo* lista, Pessoa* p); 

/*  Preenche as listas de amigos de todas as pessoas contidas na lista de pessoas
    input: O arquivo txt com as relações de amizade, a lista de pessoas em que serão preenchidas as listas de amigos
    output: Nenhum
    pré-condição: Arquivo arq existe, lista de pessoas está inicializada
    pós-condição: Listas de amigos de cada pessoa preenchidas
*/
void preencheListaAmigo(FILE* arq, ListaPessoa* lista_pessoa);

/*  Calcula as similaridades de músicas iguais entre uma pessoa e seus amigos e preenche o arquivo similaridades.txt
    input: A pessoa, a lista de pessoas que já foram comparadas, a lista  de amigos, o arquivo similaridades.txt
    output: Nenhum
    pré-condição: Pessoa existe, lista de pessoas repetidas e lista de amigos estão inicializadas, arquivo existe
    pós-condição: Arquivo similaridades.txt foi preenchido
*/
void comparaAmigoPessoa(Pessoa* p, ListaPessoa* repetidos, ListaAmigo* lista_amigos, FILE* arq);

/*  Libera toda a memória alocada para uma lista de amigos
    input: A lista de amigos 
    output: Nenhum
    pré-condição: Lista de amigos está inicializada
    pós-condição: A memória alocada para a lista de amigos foi liberada
*/
void destroiListaAmigo(ListaAmigo* lista);

#endif