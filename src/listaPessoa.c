#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pessoa.h"
#include "../include/listaPessoa.h"

struct celula_pessoa{
    Pessoa* pessoa;
    CelPessoa* prox;
};

struct lista_pessoa{
    CelPessoa* prim;
    CelPessoa* ult;
};

ListaPessoa* iniciaListaPessoa(){
    ListaPessoa* lista = (ListaPessoa*)malloc(sizeof(ListaPessoa));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereListaPessoa(ListaPessoa* lista, Pessoa* p){
  CelPessoa* cel_nova = (CelPessoa*)malloc(sizeof(CelPessoa));

  cel_nova->pessoa = p;
  cel_nova->prox = NULL;
  lista->ult->prox = cel_nova; 

  lista->ult = cel_nova;
  if(lista->prim == NULL) lista->prim = cel_nova;
}

void destroiListaPessoa(ListaPessoa* lista){
    CelPessoa* cel_atual = lista->prim;
    CelPessoa* cel_prox;

    while(cel_atual != NULL){
        cel_prox = cel_atual->prox;

        destroiPessoa(cel_atual->pessoa);
        free(cel_atual);

        cel_atual = cel_prox;
    }
    free(lista);
}