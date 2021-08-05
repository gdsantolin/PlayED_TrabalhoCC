#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pessoa.h"


struct pessoa{
    char* nome;
    ListaAmigo* amigos;
    ListaPlaylist* playlists;
};

Pessoa* criaPessoa(char* nome){
    Pessoa* pessoa = (Pessoa*)malloc(sizeof(Pessoa));
    pessoa->nome = strdup(nome);
    pessoa->amigos = iniciaListaAmigo();
    pessoa->playlists = iniciaListaPlaylist();

    return pessoa;
}

char* getNomePessoa(Pessoa* p){
    return p->nome;
}

ListaAmigo* getListaAmigoPessoa(Pessoa* p){
    return p->amigos;
}

ListaPlaylist* getListaPlaylistPessoa(Pessoa* p){
    return p->playlists;
}

void setListaPlaylistRefatoradaPessoa(Pessoa* p, ListaPlaylist* lista){
    p->playlists = lista;
}

void imprimePessoa(Pessoa* p){
    printf("%s\n", p->nome);
    printf("Amigos:\n");
    imprimeListaAmigo(getListaAmigoPessoa(p));
}

void imprimePlayedRefatorada(Pessoa* p, FILE* arq){
    fprintf(arq, "%s;", p->nome);
    imprimeListaPlayedRefatorada(p->playlists, arq);
    imprimeNovaListaPlaylistArq(p->nome, p->playlists);
}

void destroiPessoa(Pessoa* p){
    free(p->nome);
    destroiListaAmigo(p->amigos);
    destroiListaPlaylist(p->playlists);
    free(p);
}