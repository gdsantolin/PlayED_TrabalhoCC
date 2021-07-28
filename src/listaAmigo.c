#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/amigo.h"
#include "../include/listaAmigo.h"
#include "../include/pessoa.h"

struct celula_amigo{
    Pessoa* pessoa;
    CelAmigo* prox;
};

struct lista_amigo{
    CelAmigo* prim;
    CelAmigo* ult;
};

ListaAmigo* iniciaListaAmigo(){
    ListaAmigo* lista = (ListaAmigo*)malloc(sizeof(ListaAmigo));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereListaAmigo(ListaAmigo* lista, Pessoa* p){
  CelAmigo* cel_nova = (CelAmigo*)malloc(sizeof(CelAmigo));

  cel_nova->pessoa = p;
  cel_nova->prox = NULL;
  lista->ult->prox = cel_nova; 

  lista->ult = cel_nova;
  if(lista->prim == NULL) lista->prim = cel_nova;
}

void destroiListaAmigo(ListaAmigo* lista){
    CelAmigo* cel_atual = lista->prim;
    CelAmigo* cel_prox;

    while(cel_atual != NULL){
        cel_prox = cel_atual->prox;
        free(cel_atual);
        cel_atual = cel_prox;
  }
  free(lista);
}