#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/playlist.h"

struct playlist{
    char* nome;
    ListaMusica* musicas;
};

char* getNomePlaylist(Playlist* p){
    return p->nome;
}

Playlist* preenchePlaylist(char* nome_playlist){
    char nome_arquivo[50], nome_banda[100], nome_musica[100];

    Playlist* playlist = (Playlist*)malloc(sizeof(Playlist));
    playlist->nome = strdup(nome_playlist);
    playlist->musicas = iniciaListaMusica();

    strcpy(nome_arquivo, "data/");
    strcat(nome_arquivo, nome_playlist);

    FILE* arq = fopen(nome_arquivo, "r");
    while(fscanf(arq, "%99[^ -] - %99[^\n]", nome_banda, nome_musica) == 2){
        Musica* msc = preencheMusica(nome_banda, nome_musica);
        insereListaMusica(playlist->musicas, msc);
        imprimeListaMusica(playlist->musicas);
    }

    fclose(arq);
    return playlist;
}

void imprimePlaylist(Playlist* p){
    imprimeListaMusica(p->musicas);
}

void destroiPlaylist(Playlist* p){
    free(p->nome);
    destroiListaMusica(p->musicas);
    free(p);
}