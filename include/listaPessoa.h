#ifndef LISTA_PESSOA_H
#define LISTA_PESSOA_H

typedef struct lista_pessoa ListaPessoa;

#include "pessoa.h"

ListaPessoa* iniciaListaPessoa();

Pessoa* buscaPessoa(ListaPessoa* lista, char* chave); 

void insereListaPessoa(ListaPessoa* lista, Pessoa* p);

void preencheListaPessoa(ListaPessoa* lista);

void refatoraListaPlaylistPessoa(ListaPessoa* lista_p);

void imprimeListaPessoa(ListaPessoa* lista); //não precisa

void destroiListaPessoa(ListaPessoa* lista);

#endif