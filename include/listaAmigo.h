#ifndef LISTA_AMIGO_H
#define LISTA_AMIGO_H
#include "pessoa.h"
typedef struct celula_amigo CelAmigo;

typedef struct lista_amigo ListaAmigo;

ListaAmigo* iniciaListaAmigo();

void insereListaAmigo(ListaAmigo* lista, Pessoa* p); //como inserir???

void imprimeListaAmigo(ListaAmigo* lista);

void retiraListaAmigo(ListaAmigo* lista, char* chave); //talvez não precise retirar Amigos da lista

void destroiListaAmigo(ListaAmigo* lista);

#endif