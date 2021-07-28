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

void destroiListaPlaylist(ListaPlaylist* lista){
    CelPlaylist* cel_atual = lista->prim;
    CelPlaylist* cel_prox;

    while(cel_atual != NULL){
        cel_prox = cel_atual->prox;

        destroiPlaylist(cel_atual->playlist);
        free(cel_atual);

        cel_atual = cel_prox;
    }
    free(lista);
}