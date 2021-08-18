#ifndef LISTA_MUSICA_H
#define LISTA_MUSICA_H

typedef struct lista_musica ListaMusica;

#include "musica.h"
#include "listaPlaylist.h"

/*  Inicializa uma lista encadeada de músicas 
    input: Nenhum
    output:
    pré-condição:
    pós-condição:
*/
ListaMusica* iniciaListaMusica();

/*  Busca uma música dentro de uma lista de músicas
    input:
    output: A música, se encontrada; NULL, caso contrário.
    pré-condição:
    pós-condição:
*/
Musica* buscaMusica(ListaMusica* lista, char* chave_nome, char* chave_banda);

/*  Insere uma célula música em uma lista encadeada de músicas
    input:
    output:
    pré-condição:
    pós-condição:
*/
void insereListaMusica(ListaMusica* lista, Musica* p);

/*  Faz a refatoração de uma lista de músicas
    input:
    output: Nenhum
    pré-condição:
    pós-condição:
*/
void refatoraListaMusica(ListaMusica* lista, ListaPlaylist* lista_refatorada);

/*  Escreve uma lista de músicas em um arquivo
    input:
    output: Nenhum
    pré-condição:
    pós-condição:
*/
void imprimeNovaListaMusicaArq(ListaMusica* lista, FILE* arq);

/*  Conta e retorna as similaridades entre duas listas de músicas
    input:
    output: 
    pré-condição:
    pós-condição:
*/
int comparaListaMusicaAmigo(ListaMusica* lista1, ListaMusica* lista2);


void imprimeListaMusica(ListaMusica* lista); //não precisa


/*  Libera a memória alocada para uma lista de músicas
    input:
    output: Nenhum
    pré-condição:
    pós-condição:
*/
void destroiListaMusica(ListaMusica* lista);

#endif