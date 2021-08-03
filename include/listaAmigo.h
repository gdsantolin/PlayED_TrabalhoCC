#ifndef LISTA_AMIGO_H
#define LISTA_AMIGO_H

typedef struct lista_amigo ListaAmigo;

#include "listaPessoa.h"

ListaAmigo* iniciaListaAmigo();

void insereListaAmigo(ListaAmigo* lista, Pessoa* p); //como inserir???

void imprimeListaAmigo(ListaAmigo* lista);

void retiraListaAmigo(ListaAmigo* lista, char* chave); //talvez não precise retirar Amigos da lista

void preencheListaAmigo(FILE* arq, ListaPessoa* lista_pessoa);

void destroiListaAmigo(ListaAmigo* lista);

#endif