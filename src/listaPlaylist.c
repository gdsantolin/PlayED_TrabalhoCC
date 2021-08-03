#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/listaPlaylist.h"

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

void preencheListaPlaylist(ListaPessoa* lista_pessoa){
    FILE* arq = fopen("data/playlists.txt", "r");
    char linha[100], nome_pessoa[50], nome_playlist[50], nome_arquivo[50], quebra;
    int qtd_playlist, w;
    
    while(fscanf(arq, "%99[^;];%d;", nome_pessoa, &qtd_playlist) == 2){ //cada loop preenche as playlists de uma pessoa
        Pessoa* p = buscaPessoa(lista_pessoa, nome_pessoa);
        //printf("%s %d ", nome_pessoa, qtd_playlist);
        for(int i = 0; i < qtd_playlist; i++){
            w = fscanf(arq, "%99[^;^\n]%c", nome_playlist, &quebra);
            Playlist* playlist = preenchePlaylist(nome_playlist);
            insereListaPlaylist(getListaPlaylistPessoa(p), playlist);
        }
    }
    fclose(arq);
}

void imprimeListaPlaylist(ListaPlaylist* lista){
     CelPlaylist* cel_aux;
    for(cel_aux = lista->prim; cel_aux != NULL; cel_aux = cel_aux->prox){
        printf("Playlist %s:\n", getNomePlaylist(cel_aux->playlist));
        imprimePlaylist(cel_aux->playlist);
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