#ifndef LISTA_PLAYLIST_H
#define LISTA_PLAYLIST_H
#include "playlist.h"

typedef struct celula_playlist CelPlaylist;

typedef struct lista_playlist ListaPlaylist;

ListaPlaylist* iniciaListaPlaylist();

void insereListaPlaylist(ListaPlaylist* lista, Playlist* p);

void imprimeListaPlaylist(ListaPlaylist* lista);

Playlist* retiraListaPlaylist(ListaPlaylist* lista, char* chave); //talvez não precise retirar Playlists da lista

void destroiListaPlaylist(ListaPlaylist* lista);

#endif