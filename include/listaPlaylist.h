#ifndef LISTA_PLAYLIST_H
#define LISTA_PLAYLIST_H

typedef struct lista_playlist ListaPlaylist;

#include "playlist.h"
#include "listaPessoa.h"

ListaPlaylist* iniciaListaPlaylist();

Playlist* buscaPlaylist(ListaPlaylist* lista, char* chave);

void insereListaPlaylist(ListaPlaylist* lista, Playlist* playlist);

void imprimeListaPlaylist(ListaPlaylist* lista);

void preencheListaPlaylist(ListaPessoa* lista_pessoa);

void refatoraListaPlaylist(Pessoa* pessoa);

void imprimeListaPlaylist(ListaPlaylist* lista);

void imprimeNovaListaPlaylistArq(char* nome_pessoa, ListaPlaylist* lista);

void imprimeListaPlaylistPessoaArq(ListaPlaylist* lista); //criar e imprimir os arquivos de playlist refatorados e as musicas

void imprimeListaPlayedRefatorada(ListaPlaylist* lista, FILE* arq);

void destroiListaPlaylist(ListaPlaylist* lista);

#endif