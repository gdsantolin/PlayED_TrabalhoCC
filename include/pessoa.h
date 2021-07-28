#ifndef PESSOA_H
#define PESSOA_H
#include "listaPlaylist.h"
#include "listaAmigo.h"


typedef struct pessoa Pessoa;

Pessoa* criaPessoa(char* nome);

char* getNomePessoa(Pessoa* p);

ListaAmigo* getListaAmigoPessoa(Pessoa* p);

ListaPlaylist* getListaPlaylistPessoa(Pessoa* p);

void imprimePessoa(Pessoa * p);

void destroiPessoa(Pessoa* p);

#endif