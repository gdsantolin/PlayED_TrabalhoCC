#ifndef PESSOA_H
#define PESSOA_H

typedef struct pessoa Pessoa;

#include "listaPlaylist.h"
#include "listaAmigo.h"

Pessoa* criaPessoa(char* nome);

char* getNomePessoa(Pessoa* p);

ListaAmigo* getListaAmigoPessoa(Pessoa* p);

ListaPlaylist* getListaPlaylistPessoa(Pessoa* p);

void setListaPlaylistRefatoradaPessoa(Pessoa* p, ListaPlaylist* lista);

void imprimePessoa(Pessoa * p);

void imprimePlayedRefatorada(Pessoa* p, FILE* arq);

void destroiPessoa(Pessoa* p);

#endif