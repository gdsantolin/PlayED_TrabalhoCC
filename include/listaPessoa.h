#ifndef LISTA_PESSOA_H
#define LISTA_PESSOA_H

typedef struct celula_pessoa CelPessoa;

typedef struct lista_pessoa ListaPessoa;

#include "pessoa.h"

ListaPessoa* iniciaListaPessoa();

void insereListaPessoa(ListaPessoa* lista, Pessoa* p);

void imprimeListaPessoa(ListaPessoa* lista);

Pessoa* buscaPessoa(ListaPessoa* lista, char* chave); 

void refatoraListaPlaylistPessoa(ListaPessoa* lista_p);

void destroiListaPessoa(ListaPessoa* lista);

void preencheListaPessoa(ListaPessoa* lista);

#endif