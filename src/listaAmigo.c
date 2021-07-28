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