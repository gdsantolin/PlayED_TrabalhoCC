#ifndef LISTA_PLAYLIST_H
#define LISTA_PLAYLIST_H

typedef struct lista_playlist ListaPlaylist;

#include "playlist.h"
#include "listaPessoa.h"

ListaPlaylist* iniciaListaPlaylist();

Playlist* buscaPlaylist(ListaPlaylist* lista, char* chave);

void insereListaPlaylist(ListaPlaylist* lista, Playlist* playlist);

void preencheListaPlaylist(ListaPessoa* lista_pessoa);

void refatoraListaPlaylist(Pessoa* pessoa);

void imprimeNovaListaPlaylistArq(char* nome_pessoa, ListaPlaylist* lista); //escrever nos novos arquivos de playlist

void imprimeListaPlayedRefatorada(ListaPlaylist* lista, FILE* arq); //escrever no arquivo played_refatorada

void imprimeListaPlaylist(ListaPlaylist* lista); //não precisa

void destroiListaPlaylist(ListaPlaylist* lista);

#endif