#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct playlist Playlist;

#include "listaMusica.h"

Playlist* criaPlaylist();

char* getNomePlaylist(Playlist* p);

Playlist* preenchePlaylist(char* nome_playlist);

void imprimePlaylist(Playlist* p);

void destroiPlaylist(Playlist* p);

#endif