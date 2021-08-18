#ifndef LISTA_PLAYLIST_H
#define LISTA_PLAYLIST_H

typedef struct lista_playlist ListaPlaylist;

#include "playlist.h"
#include "listaPessoa.h"

/*  Inicializa uma lista encadeada de playlists
    input: Nenhum
    output:
    pré-condição:
    pós-condição:
*/
ListaPlaylist* iniciaListaPlaylist();

/*  Busca uma playlist dentro de uma lista de playlists
    input: 
    output: A playlist, se encontrada; NULL, caso contrário.
    pré-condição:
    pós-condição:
*/
Playlist* buscaPlaylist(ListaPlaylist* lista, char* chave);

/*  Insere uma célula playlist em uma lista encadeada de playlists
    input:
    output: Nenhum
    pré-condição:
    pós-condição:
*/
void insereListaPlaylist(ListaPlaylist* lista, Playlist* playlist);

/*  Preenche as listas de playlists de todas as pessoas a partir do arquivo de entrada
    input:
    output: Nenhum
    pré-condição:
    pós-condição:
*/
void preencheListaPlaylist(ListaPessoa* lista_pessoa);

/*  Faz a refatoração da lista de playlists de uma pessoa
    input:
    output: Nenhum
    pré-condição:
    pós-condição:
*/
void refatoraListaPlaylist(Pessoa* pessoa);

/*  Para cada playlist em uma lista de playlists de uma pessoa, escreve em um arquivo as músicas da playlist
    input:
    output: Nenhum
    pré-condição:
    pós-condição:
*/
void imprimeNovaListaPlaylistArq(char* nome_pessoa, ListaPlaylist* lista); //escrever nos novos arquivos de playlist

/*  Escreve no arquivo played_refatorada o número de playlists em uma lista de playlists e seus nomes
    input:
    output: Nenhum
    pré-condição:
    pós-condição:
*/
void imprimeListaPlayedRefatorada(ListaPlaylist* lista, FILE* arq); //escrever no arquivo played_refatorada

/*  Conta e retorna as similaridades entre duas listas de playlists
    input:
    output:
    pré-condição:
    pós-condição:
*/
int comparaListaPlaylistAmigo(ListaPlaylist* lista1, ListaPlaylist* lista2);


void imprimeListaPlaylist(ListaPlaylist* lista); //não precisa


/*  Libera a memória alocada para uma lista de playlists
    input:
    output: Nenhum
    pré-condição:
    pós-condição:
*/
void destroiListaPlaylist(ListaPlaylist* lista);

#endif