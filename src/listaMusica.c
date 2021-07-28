#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/musica.h"
#include "../include/listaMusica.h"

struct celula_musica{
    Musica* msc;
    CelMusica* prox;
};

struct lista_musica{
    CelMusica* prim;
    CelMusica* ult;
};

ListaMusica* iniciaListaMusica(){
    ListaMusica* lista = (ListaMusica*)malloc(sizeof(ListaMusica));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereListaMusica(ListaMusica* lista, Musica* msc){
  CelMusica* cel_nova = (CelMusica*)malloc(sizeof(CelMusica));

  cel_nova->msc = msc;
  cel_nova->prox = NULL;
  lista->ult->prox = cel_nova; 

  lista->ult = cel_nova;
  if(lista->prim == NULL) lista->prim = cel_nova;
}

void destroiListaMusica(ListaMusica* lista){
    CelMusica* cel_atual = lista->prim;
    CelMusica* cel_prox;

    while(cel_atual != NULL){
        cel_prox = cel_atual->prox;

        destroiMusica(cel_atual->msc);
        free(cel_atual);

        cel_atual = cel_prox;
    }
    free(lista);
}