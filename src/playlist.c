#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/playlist.h"
#include "../include/listaPlaylist.h"
#include "../include/musica.h"
#include "../include/listaMusica.h"

struct playlist{
    char* nome;
    ListaMusica* musicas;
};

char* getNomePlaylist(Playlist* p){
    return p->nome;
}

void destroiPlaylist(Playlist* p){
    free(p->nome);
    destroiListaMusica(p->musicas);
}