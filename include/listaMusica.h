#ifndef LISTA_MUSICA_H
#define LISTA_MUSICA_H

typedef struct lista_musica ListaMusica;

#include "musica.h"
#include "listaPlaylist.h"

ListaMusica* iniciaListaMusica();

Musica* buscaMusica(ListaMusica* lista, char* chave_nome, char* chave_banda);

void insereListaMusica(ListaMusica* lista, Musica* p);

void imprimeListaMusica(ListaMusica* lista);

Musica* retiraListaMusica(ListaMusica* lista, char* chave); //talvez não precise retirar Musicas da lista

void refatoraListaMusica(ListaMusica* lista, ListaPlaylist* lista_refatorada);

void imprimeNovaListaMusicaArq(ListaMusica* lista, FILE* arq);

void destroiListaMusica(ListaMusica* lista);

#endif