#ifndef LISTA_PLAYLIST_H
#define LISTA_PLAYLIST_H

typedef struct lista_playlist ListaPlaylist;

#include "playlist.h"
#include "listaPessoa.h"

ListaPlaylist* iniciaListaPlaylist();

void insereListaPlaylist(ListaPlaylist* lista, Playlist* playlist);

void imprimeListaPlaylist(ListaPlaylist* lista);

Playlist* retiraListaPlaylist(ListaPlaylist* lista, char* chave); //talvez não precise retirar Playlists da lista

void preencheListaPlaylist(ListaPessoa* lista_pessoa);

void imprimeListaPlaylist(ListaPlaylist* lista);

void destroiListaPlaylist(ListaPlaylist* lista);

#endif