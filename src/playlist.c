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
    char nome_arquivo[50], nome_banda[150], nome_musica[150];

    Playlist* playlist = (Playlist*)malloc(sizeof(Playlist));
    playlist->nome = strdup(nome_playlist);
    playlist->musicas = iniciaListaMusica();

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

void refatoraPlaylist(Playlist* playlist, char* caminho){
    refatoraListaMusica(playlist->musicas, caminho);
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