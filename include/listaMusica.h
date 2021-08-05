#ifndef LISTA_MUSICA_H
#define LISTA_MUSICA_H

typedef struct lista_musica ListaMusica;

#include "musica.h"
#include "listaPlaylist.h"

ListaMusica* iniciaListaMusica();

Musica* buscaMusica(ListaMusica* lista, char* chave_nome, char* chave_banda);

void insereListaMusica(ListaMusica* lista, Musica* p);

void refatoraListaMusica(ListaMusica* lista, ListaPlaylist* lista_refatorada);

void imprimeNovaListaMusicaArq(ListaMusica* lista, FILE* arq);

void imprimeListaMusica(ListaMusica* lista); //não precisa

void destroiListaMusica(ListaMusica* lista);

#endif