#ifndef LISTA_MUSICA_H
#define LISTA_MUSICA_H
#include "musica.h"

typedef struct lista_musica ListaMusica;

ListaMusica* iniciaListaMusica();

void insereListaMusica(ListaMusica* lista, Musica* p);

void imprimeListaMusica(ListaMusica* lista);

Musica* retiraListaMusica(ListaMusica* lista, char* chave); //talvez não precise retirar Musicas da lista

void destroiListaMusica(ListaMusica* lista);

#endif