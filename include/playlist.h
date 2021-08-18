#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct playlist Playlist;

#include "listaMusica.h"
#include "listaPlaylist.h"

/*  Inicializa uma playlist
    input:
    output:
    pré-condição:
    pós-condição:
*/
Playlist* criaPlaylist(char* nome);

/*  Retorna o nome de uma playlist
    input:
    output:
    pré-condição:
    pós-condição:
*/
char* getNomePlaylist(Playlist* p);

/*  Retorna a lista de músicas de uma playlist
    input:
    output:
    pré-condição:
    pós-condição:
*/
ListaMusica* getListaMusicaPlaylist(Playlist* p);

/*  Define o nome de uma playlist
    input:
    output: Nenhum
    pré-condição:
    pós-condição:
*/
void setNomePlaylist(Playlist* p, char* nome);

/*  Aloca e preenche uma playlist
    input:
    output:
    pré-condição:
    pós-condição:
*/
Playlist* preenchePlaylist(char* nome_playlist);

/*  Faz a refatoração de uma playlist
    input:
    output: Nenhum
    pré-condição:
    pós-condição:
*/
void refatoraPlaylist(Playlist* p, ListaPlaylist* lista_refatorada);

/*  Escreve os dados de uma playlist em um arquivo
    input:
    output: Nenhum
    pré-condição:
    pós-condição:
*/
void imprimeNovaPlaylistArq(Playlist* p, FILE* arq);

/*  Conta e retorna as similaridades entre duas playlists
    input:
    output:
    pré-condição:
    pós-condição:
*/
int comparaPlaylistAmigo(Playlist* p1, Playlist* p2);


void imprimePlaylist(Playlist* p);


/*  Libera a memória alocada para uma playlist
    input:
    output: Nenhum
    pré-condição:
    pós-condição:
*/
void destroiPlaylist(Playlist* p);

#endif