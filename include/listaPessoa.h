#ifndef LISTA_PESSOA_H
#define LISTA_PESSOA_H

typedef struct celula_pessoa CelPessoa;

typedef struct lista_pessoa ListaPessoa;


ListaPessoa* iniciaListaPessoa();

void insereListaPessoa(ListaPessoa* lista, Pessoa* p);

void imprimeListaPessoa(ListaPessoa* lista);

Pessoa* retiraListaPessoa(ListaPessoa* lista, char* chave); //talvez não precise retirar pessoas da lista

void destroiListaPessoa(ListaPessoa* lista);

#endif