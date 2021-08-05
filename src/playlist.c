#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/playlist.h"

struct playlist{
    char* nome;
    ListaMusica* musicas;
};

Playlist* criaPlaylist(char* nome){
    Playlist* playlist = (Playlist*)malloc(sizeof(Playlist));
    playlist->nome = strdup(nome);
    playlist->musicas = iniciaListaMusica();

    return playlist;
}

char* getNomePlaylist(Playlist* p){
    return p->nome;
}

ListaMusica* getListaMusicaPlaylist(Playlist* p){
    return p->musicas;
}

void setNomePlaylist(Playlist* p, char* nome){
    p->nome = nome;
}

Playlist* preenchePlaylist(char* nome_playlist){
    char nome_arquivo[50], nome_banda[150], nome_musica[150];

    Playlist* playlist = criaPlaylist(nome_playlist);

    strcpy(nome_arquivo, "data/Entrada/");
    strcat(nome_arquivo, nome_playlist);

    FILE* arq = fopen(nome_arquivo, "r");
    while(fscanf(arq, "%149[^-]- %149[^\n] ", nome_banda, nome_musica) == 2){
        nome_banda[strlen(nome_banda)-1] = '\0'; //tirando o espaço a mais do nome da banda
        Musica* msc = preencheMusica(nome_banda, nome_musica);
        insereListaMusica(playlist->musicas, msc);
    }

    fclose(arq);
    return playlist;
}

void refatoraPlaylist(Playlist* p, ListaPlaylist* lista_refatorada){
    refatoraListaMusica(p->musicas, lista_refatorada);
}

void imprimeNovaPlaylistArq(Playlist* p, FILE* arq){
    imprimeNovaListaMusicaArq(p->musicas, arq);
}

void imprimePlaylist(Playlist* p){
    imprimeListaMusica(p->musicas);
    printf("\n-----------\n");
}

void destroiPlaylist(Playlist* p){
    free(p->nome);
    destroiListaMusica(p->musicas);
    free(p);
}