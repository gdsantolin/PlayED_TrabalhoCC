#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaPlaylist.h"

typedef struct celula_playlist CelPlaylist;

struct celula_playlist{
    Playlist* playlist;
    CelPlaylist* prox;
};

struct lista_playlist{
    CelPlaylist* prim;
    CelPlaylist* ult;
};

ListaPlaylist* iniciaListaPlaylist(){
    ListaPlaylist* lista = (ListaPlaylist*)malloc(sizeof(ListaPlaylist));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereListaPlaylist(ListaPlaylist* lista, Playlist* playlist){
    CelPlaylist* cel_nova = (CelPlaylist*)malloc(sizeof(CelPlaylist));

    cel_nova->playlist = playlist;
    cel_nova->prox = NULL;

    if(lista->prim == NULL){
        lista->prim = cel_nova;
        lista->ult = cel_nova;
    }
    else{
        lista->ult->prox = cel_nova; 
        lista->ult = cel_nova;
    }
}

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