#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaAmigo.h"

typedef struct celula_amigo CelAmigo;

struct celula_amigo{
    void* pessoa;
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

void insereListaAmigo(ListaAmigo* lista, void* p){
    CelAmigo* cel_nova = (CelAmigo*)malloc(sizeof(CelAmigo));

    cel_nova->pessoa = p;
    cel_nova->prox = NULL;
    if(lista->prim == NULL){
        lista->prim = cel_nova;
        lista->ult = cel_nova;
    }
    else{
        lista->ult->prox = cel_nova; 
        lista->ult = cel_nova;
    }
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