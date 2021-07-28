#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"
#include "listaAmigo.h"


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

void imprimePessoa(Pessoa* p){
    printf("lista: %s\n", p->nome);
}

void destroiPessoa(Pessoa* p){
    free(p->nome);
    destroiListaAmigo(p->amigos);
    destroiListaPlaylist(p->playlists);
    free(p);
}