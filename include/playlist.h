#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "listaMusica.h"

typedef struct playlist Playlist;

char* getNomePlaylist(Playlist* p);

void destroiPlaylist(Playlist* p);

#endif