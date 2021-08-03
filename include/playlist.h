#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct playlist Playlist;

#include "listaMusica.h"

char* getNomePlaylist(Playlist* p);

void destroiPlaylist(Playlist* p);

#endif