#ifndef LISTA_AMIGO_H
#define LISTA_AMIGO_H

typedef struct lista_amigo ListaAmigo;

#include "listaPessoa.h"

ListaAmigo* iniciaListaAmigo();

void insereListaAmigo(ListaAmigo* lista, Pessoa* p); 

void preencheListaAmigo(FILE* arq, ListaPessoa* lista_pessoa);

void comparaAmigoPessoa(Pessoa* p, ListaPessoa* repetidos, ListaAmigo* lista_amigos, FILE* arq);

void imprimeListaAmigo(ListaAmigo* lista); //não precisa

void destroiListaAmigo(ListaAmigo* lista);

#endif