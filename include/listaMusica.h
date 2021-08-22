#ifndef LISTA_MUSICA_H
#define LISTA_MUSICA_H

typedef struct lista_musica ListaMusica;

#include "musica.h"
#include "listaPlaylist.h"

/*  Inicializa uma lista encadeada de músicas
    input: Nenhum
    output: Ponteiro para a lista de músicas
    pré-condição: Nenhuma
    pós-condição: Lista de músicas simplesmente encadeada com sentinela (vazia)
*/
ListaMusica* iniciaListaMusica();

/*  Busca uma música dentro de uma lista de músicas
    input: A lista de músicas, o nome da música, o nome da banda
    output: A música, se encontrada; NULL, caso contrário.
    pré-condição: Lista de músicas está inicializada
    pós-condição: A música foi encontrada caso as chaves coincidam
*/
Musica* buscaMusica(ListaMusica* lista, char* chave_nome, char* chave_banda);

/*  Insere uma célula música em uma lista encadeada de músicas
    input: A lista de músicas, a música
    output: Nenhum
    pré-condição: Lista de músicas está inicializada e música existe
    pós-condição: Célula música inserida na lista de músicas
*/
void insereListaMusica(ListaMusica* lista, Musica* msc);

/*  Faz a refatoração de uma lista de músicas por cantor/banda
    input: A lista de músicas, a nova lista de playlists
    output: Nenhum
    pré-condição: Lista de músicas e lista de playlists estão inicializadas
    pós-condição: Lista de músicas foi refatorada criando novas playlists para cada artista/banda
*/
void refatoraListaMusica(ListaMusica* lista, ListaPlaylist* lista_refatorada);

/*  Escreve uma lista de músicas em um arquivo
    input: A lista de músicas, o arquivo a escrever
    output: Nenhum
    pré-condição: Lista de músicas está inicializada e arquivo existe
    pós-condição: Lista de músicas foi escrita no arquivo 
*/
void imprimeListaMusicaArq(ListaMusica* lista, FILE* arq);

/*  Conta e retorna as similaridades entre duas listas de músicas
    input: As duas listas de músicas que serão comparadas
    output: Inteiro com a quantidade de músicas iguais nas duas listas de músicas
    pré-condição: Listas de músicas estão inicializadas
    pós-condição: Quantidade de músicas iguais nas listas de músicas foi contada
*/
int comparaListaMusicaAmigo(ListaMusica* lista1, ListaMusica* lista2);

/*  Libera toda a memória alocada para uma lista de músicas
    input: A lista de músicas 
    output: Nenhum
    pré-condição: Lista de músicas está inicializada
    pós-condição: A memória alocada para a lista de músicas foi liberada
*/
void destroiListaMusica(ListaMusica* lista);

void imprimeListaMusica(ListaMusica* lista); //não precisa

#endif