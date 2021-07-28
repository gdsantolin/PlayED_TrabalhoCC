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