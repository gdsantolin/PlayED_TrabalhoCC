#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct playlist Playlist;

#include "listaMusica.h"
#include "listaPlaylist.h"

Playlist* criaPlaylist();

char* getNomePlaylist(Playlist* p);

ListaMusica* getListaMusicaPlaylist(Playlist* p);

void setNomePlaylist(Playlist* p, char* nome);

Playlist* preenchePlaylist(char* nome_playlist);

void refatoraPlaylist(Playlist* playlist, ListaPlaylist* lista_refatorada);

void imprimeNovaPlaylistArq(Playlist* p, FILE* arq);

void imprimePlaylist(Playlist* p);

void destroiPlaylist(Playlist* p);

#endif