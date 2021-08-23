#ifndef LISTA_PLAYLIST_H
#define LISTA_PLAYLIST_H

typedef struct lista_playlist ListaPlaylist;

#include "playlist.h"
#include "listaPessoa.h"

/*  Inicializa uma lista encadeada de playlists
    input: Nenhum
    output: Ponteiro para a lista de playlists
    pré-condição: Nenhuma
    pós-condição: Lista de playlists simplesmente encadeada com sentinela (vazia)
*/
ListaPlaylist* iniciaListaPlaylist();

/*  Busca uma playlist dentro de uma lista de playlists
    input: A lista de playlists, o nome da playlist
    output: A playlist, se encontrada; NULL, caso contrário.
    pré-condição: Lista de playlists está inicializada
    pós-condição: A playlist foi encontrada caso a chave coincida
*/
Playlist* buscaPlaylist(ListaPlaylist* lista, char* chave);

/*  Insere uma célula playlist em uma lista encadeada de playlists
    input: A lista de playlists, a playlist
    output: Nenhum
    pré-condição: Lista de playlists está inicializada e playlist existe
    pós-condição: Célula playlist inserida na lista de playlists
*/
void insereListaPlaylist(ListaPlaylist* lista, Playlist* playlist);

/*  Preenche as listas de playlists de todas as pessoas a partir do arquivo de entrada
    input: A lista de pessoas
    output: Nenhum
    pré-condição: Lista de pessoas está inicializada e arquivo playlists.txt existe
    pós-condição: Todas as listas encadeadas de playlists foram preenchidas
*/
void preencheListaPlaylist(ListaPessoa* lista_pessoa);

/*  Faz a refatoração da lista de playlists de uma pessoa
    input: A pessoa
    output: Nenhum
    pré-condição: Pessoa existe
    pós-condição: Lista de playlists refatorada foi inicializada, preenchida e definida como a nova lista da pessoa
*/
void refatoraListaPlaylist(Pessoa* pessoa);

/*  Para cada playlist em uma lista de playlists de uma pessoa, escreve em um arquivo as músicas da playlist
    input: O nome da pessoa, a lista de playlists
    output: Nenhum
    pré-condição: Lista de playlists está inicializada
    pós-condição: Cada playlist da lista foi escrita em seu respectivo arquivo de saída
*/
void imprimeListaPlaylistArq(char* nome_pessoa, ListaPlaylist* lista); 

/*  Escreve no arquivo played_refatorada o número de playlists em uma lista de playlists e seus nomes
    input: A lista de playlists, o arquivo played_refatorada
    output: Nenhum
    pré-condição: Lista de playlists está inicializada, arquivo existe
    pós-condição: A quantidade de playlists da pessoa e seus nomes foram escritos no arquivo
*/
void imprimeListaPlaylistPlayedRefatorada(ListaPlaylist* lista, FILE* arq); 

/*  Conta e retorna as similaridades entre duas listas de playlists
    input: As duas listas de playlists que serão comparadas
    output: Inteiro com a quantidade de músicas iguais nas duas listas de playlists
    pré-condição: Listas de playlists estão inicializadas
    pós-condição: Quantidade de músicas iguais nas listas de playlists foi contada
*/
int comparaListaPlaylistAmigo(ListaPlaylist* lista1, ListaPlaylist* lista2);

/*  Libera toda a memória alocada para uma lista de playlists
    input: A lista de playlists 
    output: Nenhum
    pré-condição: Lista de playlists está inicializada
    pós-condição: A memória alocada para a lista de playlists foi liberada
*/
void destroiListaPlaylist(ListaPlaylist* lista);

#endif