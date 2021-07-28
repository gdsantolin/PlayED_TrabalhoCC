#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/playlist.h"
#include "../include/listaPlaylist.h"

struct celula_playlist{
    Playlist* playlist;
    CelPlaylist* prox;
};

struct lista_playlist{
    CelPlaylist* prim;
    CelPlaylist* ult;
};