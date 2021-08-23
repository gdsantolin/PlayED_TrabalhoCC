#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/listaMusica.h"

typedef struct celula_musica CelMusica;

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

Musica* buscaMusica(ListaMusica* lista, char* chave_nome, char* chave_banda){
    CelMusica* cel_aux;
    for(cel_aux = lista->prim; cel_aux != NULL; cel_aux = cel_aux->prox){
        if(strcmp(getNomeMusica(cel_aux->msc), chave_nome) == 0){
            if(strcmp(getBandaMusica(cel_aux->msc), chave_banda) == 0){
                return cel_aux->msc;
            }
        }  
    }
    return NULL;
}

void insereListaMusica(ListaMusica* lista, Musica* msc){
    CelMusica* cel_nova = (CelMusica*)malloc(sizeof(CelMusica));

    cel_nova->msc = msc;
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

void refatoraListaMusica(ListaMusica* lista, ListaPlaylist* lista_refatorada){
    CelMusica* cel_aux;
    char nome_playlist[100];
    
    for(cel_aux = lista->prim; cel_aux != NULL; cel_aux = cel_aux->prox){
        strcpy(nome_playlist, getBandaMusica(cel_aux->msc));
        strcat(nome_playlist, ".txt");

        Playlist* playlist = buscaPlaylist(lista_refatorada, nome_playlist);
        Musica* msc = preencheMusica(getBandaMusica(cel_aux->msc), getNomeMusica(cel_aux->msc));

        if(playlist == NULL){
            playlist = criaPlaylist(nome_playlist);
            insereListaPlaylist(lista_refatorada, playlist);
            insereListaMusica(getListaMusicaPlaylist(playlist), msc);
        }
        else{
            if(buscaMusica(getListaMusicaPlaylist(playlist), getNomeMusica(cel_aux->msc), getBandaMusica(cel_aux->msc)) == NULL){
                insereListaMusica(getListaMusicaPlaylist(playlist), msc);
            }
            else destroiMusica(msc);
        }
    }
}

void imprimeListaMusicaArq(ListaMusica* lista, FILE* arq){
    CelMusica* cel_aux;
    for(cel_aux = lista->prim; cel_aux != NULL; cel_aux = cel_aux->prox){
        imprimeMusicaArq(cel_aux->msc, arq);
    }
}

int comparaListaMusicaAmigo(ListaMusica* lista1, ListaMusica* lista2){
    CelMusica* cel_aux;
    int similaridade = 0;
    for(cel_aux = lista1->prim; cel_aux != NULL; cel_aux = cel_aux->prox){
        if(buscaMusica(lista2, getNomeMusica(cel_aux->msc), getBandaMusica(cel_aux->msc)) != NULL){
            similaridade++;
        }
    }
    return similaridade;
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