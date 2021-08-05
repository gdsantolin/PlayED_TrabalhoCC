#ifndef LISTA_MUSICA_H
#define LISTA_MUSICA_H

typedef struct lista_musica ListaMusica;

#include "musica.h"
#include "listaPlaylist.h"

ListaMusica* iniciaListaMusica();

void insereListaMusica(ListaMusica* lista, Musica* p);

void imprimeListaMusica(ListaMusica* lista);

Musica* retiraListaMusica(ListaMusica* lista, char* chave); //talvez não precise retirar Musicas da lista

void refatoraListaMusica(ListaMusica* lista, char* caminho, ListaPlaylist* lista_refatorada);

void destroiListaMusica(ListaMusica* lista);

#endif